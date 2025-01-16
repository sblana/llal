/* TODO:
- func: vec normalization
- func: vec―mat multiplication
- func: mat transpose
- func: vec cross product
- func: vec clamp, scalar
- func: vec min max, scalar
- func: vec min max, scalar
- func: vec floor, ceil
- func: vec lerp, slerp
- func: mat lerp, slerp
- macro: mat identity constructor
- macro: vec axis constructor
- macro: print format
- constructors
- conversion
- rotation?
- some kind of swizzling?
- bool vectors?
- quadruple?
- function inlining?
- integer matrices?
- use inttypes.h?
- shorter type names e.g. f3 vs float3, d4x4 vs double4x4?
- matrices with differing row and column sizes e.g. 4x3?
- dont use size_t
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>

#define GEN_VECNAME(name, str, N) char name[strlen(str)+2]; \
								  sprintf(name, "%s%zu", str, N); \
								  name[strlen(str)+1] = '\0';

#define END_FUNCDEF(stream) if (pass == DEFINITION) fprintf(stream, ";\n");

enum DimensionType {
	DIM_VOID = 0,
	DIM_SCALAR,
	DIM_VECTOR,
	DIM_MATRIX,
};

struct datatype_info {
	char *name;
	char *nickname;
	char func_suffix;
};

enum DataType {
	DATATYPE_FLOAT = 0,
	DATATYPE_DOUBLE,
	DATATYPE_INT,
	DATATYPE_UNSIGNED,
	DATATYPES_COUNT
};

const struct datatype_info types[DATATYPES_COUNT] = {
	[DATATYPE_FLOAT]	= {"float", "f", 'f'},
	[DATATYPE_DOUBLE]	= {"double", "d", '\0'},
	[DATATYPE_INT]		= {"int", "i", 'i'},
	[DATATYPE_UNSIGNED]	= {"unsigned", "u", 'u'},
};

struct operator_info {
	char *name;
	char *op_token;
};

#define OPERATORS_COUNT 4
const struct operator_info operators[OPERATORS_COUNT] = {
	{"add", "+"},
	{"sub", "-"},
	{"mul", "*"},
	{"div", "/"},
};

#define FUNC_MAX_ARITY 4

enum FuncAffix {
	FUNC_AFFIX_NONE = 0,
	FUNC_AFFIX_RETURN_TYPE,
	FUNC_AFFIX_PARAM_1_TYPE,
	FUNC_AFFIX_COUNT,
};

struct func_name {
	enum FuncAffix prefix;
	char *func_root;
	enum FuncAffix suffix;
};

struct func_info {
	struct func_name name;
	bool valid_datatypes[DATATYPES_COUNT];
	enum DimensionType return_dim;
	size_t arity;
	enum DimensionType param_dims[FUNC_MAX_ARITY];
};

enum SpecFunc {
	SPECFUNC_LENGTH_SQUARED = 0,
	SPECFUNC_LENGTH,
	SPECFUNC_DOT_PRODUCT,
	SPECFUNC_CROSS_PRODUCT,
	SPECFUNCS_COUNT,
};

const struct func_info specfuncs[SPECFUNCS_COUNT] = {
	[SPECFUNC_LENGTH_SQUARED] = {
		.name = {
			.prefix = FUNC_AFFIX_PARAM_1_TYPE,
			.func_root = "lensqr",
			.suffix = FUNC_AFFIX_NONE,
		},
		.valid_datatypes = {
			[DATATYPE_FLOAT]	= true,
			[DATATYPE_DOUBLE]	= true,
			[DATATYPE_INT]		= true,
			[DATATYPE_UNSIGNED] = true,
		},
		.return_dim = DIM_SCALAR,
		.arity = 1,
		.param_dims = { DIM_VECTOR, }
	},
	[SPECFUNC_LENGTH] = {
		.name = {
			.prefix = FUNC_AFFIX_PARAM_1_TYPE,
			.func_root = "len",
			.suffix = FUNC_AFFIX_NONE,
		},
		.valid_datatypes = {
			[DATATYPE_FLOAT]	= true,
			[DATATYPE_DOUBLE]	= true,
			[DATATYPE_INT]		= false,
			[DATATYPE_UNSIGNED] = false,
		},
		.return_dim = DIM_SCALAR,
		.arity = 1,
		.param_dims = { DIM_VECTOR, }
	},
	[SPECFUNC_DOT_PRODUCT] = {
		.name = {
			.prefix = FUNC_AFFIX_PARAM_1_TYPE,
			.func_root = "dot",
			.suffix = FUNC_AFFIX_NONE,
		},
		.valid_datatypes = {
			[DATATYPE_FLOAT]	= true,
			[DATATYPE_DOUBLE]	= true,
			[DATATYPE_INT]		= true,
			[DATATYPE_UNSIGNED] = true,
		},
		.return_dim = DIM_SCALAR,
		.arity = 2,
		.param_dims = { DIM_VECTOR, DIM_VECTOR, }
	},
	[SPECFUNC_CROSS_PRODUCT] = {
		.name = {
			.prefix = FUNC_AFFIX_PARAM_1_TYPE,
			.func_root = "cross",
			.suffix = FUNC_AFFIX_NONE,
		},
		.valid_datatypes = {
			[DATATYPE_FLOAT]	= true,
			[DATATYPE_DOUBLE]	= true,
			[DATATYPE_INT]		= true,
			[DATATYPE_UNSIGNED] = false,
		},
		.return_dim = DIM_VECTOR,
		.arity = 2,
		.param_dims = { DIM_VECTOR, DIM_VECTOR, }
	},
};

const char *parameter_name_sets[][FUNC_MAX_ARITY] = {
	{"a", "b", "c", "d"},
};

#define V_MAX_COMPS 4
#define V_COMP_ALIAS_SETS 3

const char vcomp_alias[V_COMP_ALIAS_SETS][V_MAX_COMPS] = {
	{'x','y','z','w'},
	{'r','g','b','a'},
	{'s','t','p','q'},
};

enum FuncGenPassType {
	DEFINITION = 0,
	IMPLEMENTATION,
};

// returns length. 0 if errored. varargs should be <enum DataType type, size_t rows>
size_t vsngen_func_symbol(char *buffer, size_t buffer_size, struct func_info func, va_list ap) {
	if (!buffer_size) return false;
	buffer[0] = '\0';
	size_t name_length = 0;
	// worst code known to man but prolly changing it all later anyways
	for (size_t i = 0; i < 2; i++) {
		if ((!i ? func.name.prefix : func.name.suffix) != FUNC_AFFIX_NONE) {
			switch (!i ? func.name.prefix : func.name.suffix) {
				case FUNC_AFFIX_PARAM_1_TYPE:
				{
					va_list aq;
					va_copy(aq, ap);
					enum DataType p0_type = va_arg(aq, enum DataType);
					size_t p0_rows = va_arg(aq, size_t);
					va_end(aq);
					
					GEN_VECNAME(vec_nickname, types[p0_type].nickname, p0_rows)
					
					snprintf(buffer + name_length, buffer_size - name_length, !i ? "%s_" : "_%s", vec_nickname);
					name_length += strlen(vec_nickname) + 1;
					if (buffer_size < name_length) return false;
					buffer[name_length] = '\0';
					break;
				}
				// TODO: implement other affixes
				default:
					return false;
			}
		}
		if (!i) {
			snprintf(buffer + name_length, buffer_size - name_length, "%s", func.name.func_root);
			name_length += strlen(func.name.func_root);
			if (buffer_size < name_length) return false;
			buffer[name_length] = '\0';
		}
	}
	return name_length;
}

// returns length. 0 if errored. varargs should be <enum DataType type, size_t rows>
size_t sngen_func_symbol(char *buffer, size_t buffer_size, struct func_info func, ...) {
	va_list args;
	va_start(args, func);
	size_t symbol_length = vsngen_func_symbol(buffer, buffer_size, func, args);
	va_end(args);
	return symbol_length;
}

// returns length. 0 if errored. varargs should be <enum DataType type, size_t rows>
size_t sngen_func_signature(char *buffer, size_t buffer_size, struct func_info func, ...) {
	va_list args;
	va_start(args, func);
	if (func.return_dim != DIM_VOID) {
		va_arg(args, enum DataType);
		va_arg(args, size_t);
	}
	size_t symbol_length = vsngen_func_symbol(buffer, buffer_size, func, args);
	va_end(args);
	
	size_t signature_length = symbol_length;
	
	if (func.return_dim != DIM_VOID) {
		va_start(args, func);
		enum DataType r_type = va_arg(args, enum DataType);
		size_t r_rows = va_arg(args, size_t);
		va_end(args);
		
		GEN_VECNAME(r_name, types[r_type].name, r_rows)
		size_t r_name_length = strlen(r_name);
		
		if (func.return_dim == DIM_SCALAR) {
			r_name_length--;
			r_name[r_name_length] = '\0';
		}
		
		signature_length += r_name_length + 1;
		if (buffer_size < signature_length) return false;
		for (size_t i = symbol_length + 1; i > 0; i--) {
			buffer[i + r_name_length] = buffer[i - 1];
		}
		strcpy(buffer, r_name);
		buffer[strlen(r_name)] = ' ';
	}
	else {
		/* TODO: implement */
	}
	
	if (buffer_size < signature_length + 1) return false;
	snprintf(buffer + signature_length, buffer_size - signature_length, "(");
	signature_length++;
	
	for (size_t i = 0; i < func.arity; i++) {
		if (func.param_dims[i] == DIM_VOID) return false;
		
		va_start(args, func);
		enum DataType p_type;
		size_t p_rows;
		for (size_t j = 0; j <= i + (func.return_dim != DIM_VOID); j++) {
			// printf("%zu", j);
			p_type = va_arg(args, enum DataType);
			p_rows = va_arg(args, size_t);
		}
		va_end(args);
		
		GEN_VECNAME(p_name, types[p_type].name, p_rows)
		if (func.param_dims[i] == DIM_SCALAR) {
			p_name[strlen(p_name)-1] = '\0';
		}
		else if (func.param_dims[i] == DIM_MATRIX) {
			/* TODO: implement */
		}
		snprintf(buffer + signature_length, buffer_size - signature_length, "%s %s, ", p_name, parameter_name_sets[0][i]);
		signature_length += strlen(p_name) + strlen(parameter_name_sets[0][i]) + 3;
		if (i + 1 == func.arity) signature_length -= 2;
		if (buffer_size < signature_length) return false;
	}
	
	if (buffer_size < signature_length + 1) return false;
	snprintf(buffer + signature_length, buffer_size - signature_length, ")");
	signature_length++;
	buffer[signature_length] = '\0';
	return signature_length;
}

void gen_def_vector(FILE *stream, const char *type_name, size_t rows) {
	fprintf(stream,
		"typedef union {\n"
		"\t%s c[%zu];\n",
		type_name, rows);
	for (size_t i = 0; i < V_COMP_ALIAS_SETS; i++) {
		fprintf(stream, 
			"\tstruct { %s %c",
			type_name, vcomp_alias[i][0]);
		for (size_t j = 1; j < rows; j++)
			fprintf(stream, ", %c", vcomp_alias[i][j]);
		fprintf(stream, "; };\n");
	}
	fprintf(stream, "} %s%zu;\n\n", type_name, rows);
}

void gen_def_matrix(FILE *stream, const char *type_name, size_t rows) {
	GEN_VECNAME(vec_name, type_name, rows)
	
	fprintf(stream,
		"typedef union {\n"
		"\t%s c[%zu];\n"
		"\t%s v[%zu];\n",
		type_name, rows*rows, vec_name, rows);
	for (size_t k = 0; k < V_COMP_ALIAS_SETS; k++) {
		fprintf(stream, 
			"\tstruct { %s %c",
			vec_name, vcomp_alias[k][0]);
		for (size_t j = 1; j < rows; j++)
			fprintf(stream, ", %c", vcomp_alias[k][j]);
		fprintf(stream, "; };\n");
		
		fprintf(stream, 
			"\tstruct {\n");
		for (size_t j = 0; j < rows; j++) {
			fprintf(stream,
				"\t\t%s %c%c",
				type_name, vcomp_alias[k][j], vcomp_alias[k][0]);
			for (size_t i = 1; i < rows; i++)
				fprintf(stream, ", %c%c", vcomp_alias[k][j], vcomp_alias[k][i]);
			fprintf(stream, ";\n");
		}
		fprintf(stream, "\t};\n");
	}
	fprintf(stream, "} %sx%zu;\n\n", vec_name, rows);
}

void gen_func_vector_elementary(FILE *stream, struct datatype_info type, size_t rows, struct operator_info operator, enum FuncGenPassType pass) {
	GEN_VECNAME(vec_name, type.name, rows)
	GEN_VECNAME(vec_nickname, type.nickname, rows)
	
	fprintf(stream,
		"%s %s_%s(%s a, %s b)",
		vec_name, vec_nickname, operator.name, vec_name, vec_name);
	END_FUNCDEF(stream)
	else if (pass == IMPLEMENTATION)
		fprintf(stream, " {\n"
				"\tfor (size_t i = 0; i < %zu; i++) a.c[i] %s= b.c[i];\n"
				"\treturn a;\n"
			"}\n\n",
			rows, operator.op_token);
}

void gen_func_vector_scalar_elementary(FILE *stream, struct datatype_info type, size_t rows, struct operator_info operator, enum FuncGenPassType pass) {
	GEN_VECNAME(vec_name, type.name, rows);
	GEN_VECNAME(vec_nickname, type.nickname, rows);
	
	fprintf(stream,
		"%s %s_%s_%s(%s a, %s b)",
		vec_name, vec_nickname, operator.name, type.nickname, vec_name, type.name);
	END_FUNCDEF(stream)
	else if (pass == IMPLEMENTATION)
		fprintf(stream, " {\n"
				"\tfor (size_t i = 0; i < %zu; i++) a.c[i] %s= b;\n"
				"\treturn a;\n"
			"}\n\n",
			rows, operator.op_token);
}

void gen_func_vector_dot(FILE *stream, enum DataType type, size_t rows, enum FuncGenPassType pass) {
	if (specfuncs[SPECFUNC_DOT_PRODUCT].valid_datatypes[type] == false) return;
	GEN_VECNAME(vec_name, types[type].name, rows)
	GEN_VECNAME(vec_nickname, types[type].nickname, rows)
	
	char func_sig[128];
	sngen_func_signature(func_sig, 128, specfuncs[SPECFUNC_DOT_PRODUCT], type, (size_t)1, type, rows, type, rows);
	
	fprintf(stream, "%s", func_sig);
	END_FUNCDEF(stream)
	if (pass == IMPLEMENTATION) {
		fprintf(stream, " {\n"
				"\treturn a.x*b.x");
		for (size_t j = 1; j < rows; j++)
			fprintf(stream, " + a.%c*b.%c", vcomp_alias[0][j], vcomp_alias[0][j]);
		fprintf(stream, ";\n}\n\n");
	}
}

void gen_func_vector_cross(FILE *stream, enum DataType type, size_t rows, enum FuncGenPassType pass) {
	if (specfuncs[SPECFUNC_CROSS_PRODUCT].valid_datatypes[type] == false) return;
	if (rows != (size_t)3) return;
	GEN_VECNAME(vec_name, types[type].name, rows)
	GEN_VECNAME(vec_nickname, types[type].nickname, rows)
	char func_sig[128];
	sngen_func_signature(func_sig, 128, specfuncs[SPECFUNC_CROSS_PRODUCT], type, rows, type, rows, type, rows);
	
	fprintf(stream, "%s", func_sig);
	END_FUNCDEF(stream)
	if (pass == IMPLEMENTATION) {
		fprintf(stream, " {\n\treturn (%s){", vec_name);
		for (size_t j = 0; j < rows; j++) {
			fprintf(stream, "\n\t\t.%c = ", vcomp_alias[0][j]);
			fprintf(stream, "a.%c*b.%c -", vcomp_alias[0][(j+1)%rows], vcomp_alias[0][(j+2)%rows]);
			fprintf(stream, " a.%c*b.%c,", vcomp_alias[0][(j+2)%rows], vcomp_alias[0][(j+1)%rows]);
		}
		fprintf(stream, "\n\t};\n}\n\n");
	}
}

void gen_func_vector_lensqr(FILE *stream, enum DataType type, size_t rows, enum FuncGenPassType pass) {
	if (specfuncs[SPECFUNC_LENGTH_SQUARED].valid_datatypes[type] == false) return;
	GEN_VECNAME(vec_name, types[type].name, rows)
	GEN_VECNAME(vec_nickname, types[type].nickname, rows)
	
	char func_sig[128];
	sngen_func_signature(func_sig, 128, specfuncs[SPECFUNC_LENGTH_SQUARED], type, (size_t)1, type, rows);	
	
	fprintf(stream, "%s", func_sig);
	END_FUNCDEF(stream)
	if (pass == IMPLEMENTATION) {
		fprintf(stream, " {\n\treturn a.x*a.x");
		for (size_t j = 1; j < rows; j++)
			fprintf(stream, " + a.%c*a.%c", vcomp_alias[0][j], vcomp_alias[0][j]);
		fprintf(stream, ";\n}\n\n");
	}
}

void gen_func_vector_len(FILE *stream, enum DataType type, size_t rows, enum FuncGenPassType pass) {
	if (specfuncs[SPECFUNC_LENGTH].valid_datatypes[type] == false) return;
	GEN_VECNAME(vec_name, types[type].name, rows)
	GEN_VECNAME(vec_nickname, types[type].nickname, rows)
	char func_sig[128];
	sngen_func_signature(func_sig, 128, specfuncs[SPECFUNC_LENGTH], type, (size_t)1, type, rows);
	
	fprintf(stream, "%s", func_sig);
	END_FUNCDEF(stream)
	if (pass == IMPLEMENTATION) {
		fprintf(stream, " {\n\treturn sqrt");
		if (type != DATATYPE_DOUBLE)
			fprintf(stream, "%c", types[type].func_suffix);
		char len_symbol[128];
		sngen_func_symbol(len_symbol, 128, specfuncs[SPECFUNC_LENGTH_SQUARED], type, rows);
		fprintf(stream, "(%s(a));\n}\n\n", len_symbol);
	}
}

int main() {
	fprintf(stdout,
		"#ifndef LLAL_H\n"
		"#define LLAL_H\n"
		"\n"
		"#include <stdlib.h>\n"
		"#include <math.h>\n"
		"\n"
		"\n");
	for (size_t n = 2; n <= V_MAX_COMPS; n++) {
		fprintf(stdout, "\n");
		for (size_t type = 0; type < DATATYPES_COUNT; type++)
			gen_def_vector(stdout, types[type].name, n);
	}
	for (size_t n = 2; n <= V_MAX_COMPS; n++) {
		fprintf(stdout, "\n");
		for (size_t type = 0; type < DATATYPES_COUNT; type++)
			gen_def_matrix(stdout, types[type].name, n);
	}
	for (enum FuncGenPassType pass = DEFINITION; pass <= IMPLEMENTATION; pass++) {
		if (pass == IMPLEMENTATION)
			fprintf(stdout, "\n#ifdef LLAL_IMPLEMENTATION\n");
		for (size_t n = 2; n <= V_MAX_COMPS; n++) {
			for (size_t type = 0; type < DATATYPES_COUNT; type++) {
				fprintf(stdout, "\n");
				for (size_t operator = 0; operator < OPERATORS_COUNT; operator++) {
					gen_func_vector_elementary(stdout, types[type], n, operators[operator], pass);
					gen_func_vector_scalar_elementary(stdout, types[type], n, operators[operator], pass);
				}
				gen_func_vector_dot(stdout, type, n, pass);
				gen_func_vector_cross(stdout, type, n, pass);
				gen_func_vector_lensqr(stdout, type, n, pass);
				gen_func_vector_len(stdout, type, n, pass);
			}
		}
		// Matrix functions
		// for (size_t n = 2; n <= V_MAX_COMPS; n++) {}
		if (pass == DEFINITION)
			fprintf(stdout, "\n");
	}
	fprintf(stdout, "#endif // ifdef LLAL_IMPLEMENTATION\n");
	fprintf(stdout, "#endif // ifndef LLAL_H");
	return 0;
}