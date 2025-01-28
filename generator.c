/* TODO:
- func: vec clamp, scalar
- func: vec min max, scalar
- func: vec min max, scalar
- func: vec floor, ceil
- func: vec lerp, slerp
- func: mat determinant
- func: mat lerp, slerp
- func: vec axis constructor
- macro: print format
- mat constructors
- conversion
- 2d rotation, translate?
- something with perspective distortions?
- quaternion?
- some kind of swizzling? min ~4000 lines via functions.
- bool vectors?
- quadruple floating point?
- integer matrices?
- use inttypes.h?
- shorter type names e.g. f3 vs float3, d4x4 vs double4x4?
- matrices with differing row and column sizes e.g. 4x3?
- C11 generics?
- kahan summation or similar algorithms?
- hypot?
- no scalar fields for matrices? e.g. no .xx .xy .yx etc
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>

/* Generation options */
// Uses MIN and MAX macros instead of its expansion directly.
#define USE_MINMAX_MACRO
// Generates roughly 2000 swizzling functions.
// #define GENERATE_SWIZZLING

#define PRE_FUNCSIG(stream) fprintf(stream, "LLAL_INLINE ");

#define GEN_VECNAME(name, str, N) char name[strlen(str)+2]; \
								  sprintf(name, "%s%zu", str, N); \
								  name[strlen(str)+1] = '\0';

#define GEN_MATNAME(name, str, N) char name[strlen(str)+4]; \
								  sprintf(name, "%s%zux%zu", str, N, N); \
								  name[strlen(str)+3] = '\0';

#define END_FUNCDEF(stream) if (pass == DEFINITION) fprintf(stream, ";\n");

enum DimensionType {
	DIM_VOID = 0,
	DIM_SCALAR,
	DIM_VECTOR,
	DIM_MATRIX,
	DIM_COUNT,
};

#define V_MAX_COMPS 4
#define V_COMP_ALIAS_SETS 3

const char vcomp_alias[V_COMP_ALIAS_SETS][V_MAX_COMPS] = {
	{'x','y','z','w'},
	{'r','g','b','a'},
	{'s','t','p','q'},
};

struct datatype_info {
	char *name;
	char *nickname;
	char *func_suffix;
};

enum DataType {
	DATATYPE_FLOAT = 0,
	DATATYPE_DOUBLE,
	DATATYPE_INT,
	DATATYPE_UNSIGNED,
	DATATYPES_COUNT
};

const struct datatype_info types[DATATYPES_COUNT] = {
	[DATATYPE_FLOAT]	= {"float", "f", "f"},
	[DATATYPE_DOUBLE]	= {"double", "d", "\0"},
	[DATATYPE_INT]		= {"int", "i", "i"},
	[DATATYPE_UNSIGNED]	= {"unsigned", "u", "u"},
};

struct operator_info {
	char *name;
	char *op_token;
};

enum Operators {
	OPERATOR_ADDITION = 0,
	OPERATOR_SUBTRACTION,
	OPERATOR_MULTIPLICATION,
	OPERATOR_DIVISION,
	OPERATORS_COUNT,
};

const struct operator_info operators[OPERATORS_COUNT] = {
	[OPERATOR_ADDITION]		  = {"add", "+"},
	[OPERATOR_SUBTRACTION]	  = {"sub", "-"},
	[OPERATOR_MULTIPLICATION] = {"mul", "*"},
	[OPERATOR_DIVISION]		  = {"div", "/"},
};

enum Coalescers {
	COALESCER_SUM = 0,
	COALESCER_PRODUCT,
	COALESCER_MIN,
	COALESCER_MAX,
	COALESCERS_COUNT,
};

const struct operator_info coalescers[COALESCERS_COUNT] = {
	[COALESCER_SUM]		= {"clesce_sum", "+"},
	[COALESCER_PRODUCT] = {"clesce_product", "*"},
	[COALESCER_MIN]		= {"clesce_min", "<"},
	[COALESCER_MAX]		= {"clesce_max", ">"},
};

#define FUNC_MAX_ARITY 4

struct func_info {
	char *name_fmt;
	bool valid_datatypes[DATATYPES_COUNT];
	size_t arity;
	bool valid_rows[V_MAX_COMPS+1];
};

enum SpecFunc {
	SPECFUNC_LENGTH_SQUARED = 0,
	SPECFUNC_LENGTH,
	SPECFUNC_NORMALIZE,
	SPECFUNC_DOT_PRODUCT,
	SPECFUNC_CROSS_PRODUCT,
	SPECFUNC_TRANSPOSE,
	SPECFUNC_IDENTITY,
	SPECFUNC_SCALE,
	SPECFUNC_ROTATE,
	SPECFUNC_TRANSLATE,
	SPECFUNCS_COUNT,
};

const struct func_info specfuncs[SPECFUNCS_COUNT] = {
	[SPECFUNC_LENGTH_SQUARED] = {
		.name_fmt = "%s_lensqr",
		.arity = 1,
	},
	[SPECFUNC_LENGTH] = {
		.name_fmt = "%s_len",
		.valid_datatypes = {
			[DATATYPE_FLOAT]	= true,
			[DATATYPE_DOUBLE]	= true,
			[DATATYPE_INT]		= false,
			[DATATYPE_UNSIGNED] = false,
		},
		.arity = 1,
	},
	[SPECFUNC_NORMALIZE] = {
		.name_fmt = "%s_normalize",
		.valid_datatypes = {
			[DATATYPE_FLOAT]	= true,
			[DATATYPE_DOUBLE]	= true,
			[DATATYPE_INT]		= false, // is there a point to normalizing an integer vector?
			[DATATYPE_UNSIGNED] = false,
		},
		.arity = 1,
	},
	[SPECFUNC_DOT_PRODUCT] = {
		.name_fmt = "%s_dot",
		.arity = 2,
	},
	[SPECFUNC_CROSS_PRODUCT] = {
		.name_fmt = "%s_cross",
		.valid_datatypes = {
			[DATATYPE_FLOAT]	= true,
			[DATATYPE_DOUBLE]	= true,
			[DATATYPE_INT]		= true,
			[DATATYPE_UNSIGNED] = false,
		},
		.arity = 2,
	},
	[SPECFUNC_TRANSPOSE] = {
		.name_fmt = "%s_transpose",
		.arity = 1,
	},
	[SPECFUNC_IDENTITY] = {
		.name_fmt = "%s_identity",
		.arity = 0,
	},
	[SPECFUNC_SCALE] = {
		.name_fmt = "%s_scale",
		.arity = 1,
	},
	[SPECFUNC_ROTATE] = {
		.name_fmt = "%s_rotate",
		.arity = 2,
		.valid_datatypes = {
			[DATATYPE_FLOAT]	= true,
			[DATATYPE_DOUBLE]	= true,
			[DATATYPE_INT]		= false,
			[DATATYPE_UNSIGNED]	= false,
		},
		.valid_rows = {
			[2] = false,
			[3] = true,
			[4] = true,
		},
	},
	[SPECFUNC_TRANSLATE] = {
		.name_fmt = "%s_translate",
		.arity = 1,
		.valid_rows = {
			[2] = false,
			[3] = false,
			[4] = true,
		},
	},
};

enum ParameterNameSet {
	PARAMNAMESET_ABCD = 0,
	PARAMNAMESET_VEC_BY,
	PARAMNAMESET_MAT_BY,
	PARAMNAMESETS_COUNT,
};

const char *parameter_name_sets[PARAMNAMESETS_COUNT][FUNC_MAX_ARITY] = {
	[PARAMNAMESET_ABCD] = {"a", "b", "c", "d"},
	[PARAMNAMESET_VEC_BY] = {"vec", "by"},
	[PARAMNAMESET_MAT_BY] = {"mat", "by"},
};

enum FuncGenPassType {
	DEFINITION = 0,
	IMPLEMENTATION,
};

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

// wrap this?
void gen_ctor_vector(FILE *stream, struct datatype_info type, size_t rows, enum FuncGenPassType pass) {
	GEN_VECNAME(vec_name, type.name, rows)
	GEN_VECNAME(vec_nickname, type.nickname, rows)
	char vecrow_names[rows][strlen(vec_name) + 1];
	char vecrow_nicknames[rows][strlen(vec_nickname) + 1];
	for (size_t i = 0; i < rows; i++) {
		strcpy(vecrow_names[i], vec_name);
		strcpy(vecrow_nicknames[i], vec_nickname);
		vecrow_names[i][strlen(vec_name) - 1] = (i == 0) ? '\0' : '1' + (char)i;
		vecrow_nicknames[i][strlen(vec_nickname) - 1] = (i == 0) ? '\0' : '1' + (char)i;
	}
	for (size_t arity = 1; arity <= rows; arity++) {
		for (size_t i = 0; i < pow((double)rows, (double)arity); i++) {
			// generate potential constructors
			size_t param_rows[arity];
			size_t temp = i;
			size_t sum = 0;
			for (size_t j = 0; j < arity; j++) {
				param_rows[j] = (temp % rows) + 1;
				sum += param_rows[j];
				temp /= rows;
			}
			
			// discard invalid constructors
			if (sum != 1 && sum != rows) continue;
			
			// generate parameter names
			char param_names[arity][5];
			size_t comps_remaining = rows;
			for (size_t param = 0; param < arity; param++) {
				for (size_t j = 0; j < param_rows[param]; j++) {
					param_names[param][j] = vcomp_alias[0][rows - comps_remaining];
					comps_remaining--;
				}
				param_names[param][param_rows[param]] = '\0';
			}
			
			PRE_FUNCSIG(stream)
			// writing return type and func symbol
			fprintf(stream, "%s %s_ctor_",
				vec_name, vec_nickname);
			for (size_t param = 0; param < arity; param++) {
				fprintf(stream, "%s", vecrow_nicknames[param_rows[param]-1]);
			}
			// writing parameters
			fprintf(stream, "(");
			for (size_t param = 0; param < arity; param++) {
				fprintf(stream, "%s %s",
					vecrow_names[param_rows[param]-1], param_names[param]);
				if ((param + 1) < arity) fprintf(stream, ", ");
			}
			fprintf(stream, ")");
			
			END_FUNCDEF(stream)
			else if (pass == IMPLEMENTATION) {
				fprintf(stream, "{\n\treturn (%s){{", vec_name);
				comps_remaining = rows;
				for (size_t param = 0; param < arity; param++) {
					for (size_t j = 0; j < param_rows[param]; j++) {
						fprintf(stream, " %s", param_names[param]);
						if (param_rows[param] > 1)
							fprintf(stream, ".%c", vcomp_alias[0][j]);
						if (comps_remaining > 1)
							fprintf(stream, ",");
						comps_remaining--;
					}
				}
				fprintf(stream, " }};\n}\n\n");
			}
		}
	}
}

void gen_swizzle_vector(FILE *stream, struct datatype_info type, size_t rows, enum FuncGenPassType pass) {
	GEN_VECNAME(vec_name, type.name, rows)
	GEN_VECNAME(vec_nickname, type.nickname, rows)
	if (rows == 1) {
		vec_name[strlen(vec_name)-1] = '\0';
		vec_nickname[strlen(vec_name)] = '\0';
	}
	for (size_t return_rows = 2; return_rows <= V_MAX_COMPS; return_rows++) {
		GEN_VECNAME(ret_name, type.name, (size_t)return_rows)
		for (size_t i = 0; i < pow((double)rows, (double)return_rows); i++) {
			// generate return swizzles
			size_t return_swizzle[return_rows];
			size_t temp = i;
			size_t sum = 0;
			for (size_t j = 0; j < return_rows; j++) {
				return_swizzle[j] = (temp % rows);
				sum += return_swizzle[j];
				temp /= rows;
			}
			
			PRE_FUNCSIG(stream)
			// writing return type and func symbol
			fprintf(stream, "%s %s_",
				ret_name, vec_nickname);
			for (size_t comp = 0; comp < return_rows; comp++) {
				fprintf(stream, "%c", vcomp_alias[0][return_swizzle[comp]]);
			}
			fprintf(stream, "(%s %s)", vec_name, parameter_name_sets[0][0]);
			END_FUNCDEF(stream)
			else if (pass == IMPLEMENTATION) {
				fprintf(stream, "{return (%s){{", ret_name);
				for (size_t comp = 0; comp < return_rows; comp++) {
					fprintf(stream, " %s", parameter_name_sets[0][0]);
					if (rows > 1)
						fprintf(stream, ".%c", vcomp_alias[0][return_swizzle[comp]]);
					if ((comp + 1) < return_rows)
						fprintf(stream, ",");
				}
				fprintf(stream, " }};}\n");
			}
		}
	}
}

void gen_func_vector_elementary(FILE *stream, struct datatype_info type, size_t rows, struct operator_info operator, enum FuncGenPassType pass, enum DimensionType b_dimtype) {
	GEN_VECNAME(vec_name, type.name, rows)
	GEN_VECNAME(vec_nickname, type.nickname, rows)
	GEN_VECNAME(b_name, type.name, rows);
	GEN_VECNAME(b_nickname, type.nickname, rows);
	
	if (b_dimtype == DIM_SCALAR) {
		b_name[strlen(b_name)-1] = '\0';
		b_nickname[strlen(b_nickname)-1] = '\0';
	}
	else if (b_dimtype != DIM_VECTOR) return;
	
	PRE_FUNCSIG(stream)
	fprintf(stream, "%s %s_%s", vec_name, vec_nickname, operator.name);
	if (b_dimtype == DIM_SCALAR) fprintf(stream, "_%s", b_nickname);
	fprintf(stream, "(%s %s, %s %s)", vec_name, parameter_name_sets[0][0], b_name, parameter_name_sets[0][1]);
	END_FUNCDEF(stream)
	else if (pass == IMPLEMENTATION) {
		fprintf(stream, " {\n\tfor (unsigned i = 0; i < %zu; i++)\n\t\t%s.c[i] %s= %s",
			rows, parameter_name_sets[0][0], operator.op_token, parameter_name_sets[0][1]);
		if (b_dimtype == DIM_VECTOR) fprintf(stream, ".c[i]");
		fprintf(stream, ";\n\treturn %s;\n}\n\n", parameter_name_sets[0][0]);
	}
}

void gen_func_vector_coalesce(FILE *stream, enum DataType type, size_t rows, enum Coalescers coalescer, enum FuncGenPassType pass) {
	GEN_VECNAME(vec_name, types[type].name, rows)
	GEN_VECNAME(vec_nickname, types[type].nickname, rows)
	
	PRE_FUNCSIG(stream)
	fprintf(stream, "%s ", types[type].name);
	fprintf(stream, "%s_%s", vec_nickname, coalescers[coalescer].name);
	fprintf(stream, "(%s %s)", vec_name, parameter_name_sets[0][0]);
	END_FUNCDEF(stream)
	else if (pass == IMPLEMENTATION) {
		fprintf(stream, " {");
		if (coalescer < COALESCER_MIN) {
			fprintf(stream, "\n\treturn ");
			for (size_t i = 0; i < rows; i++) {
				fprintf(stream, "%s.%c", parameter_name_sets[0][0], vcomp_alias[0][i]);
				if (i < (rows - 1))
					fprintf(stream, " %s ", coalescers[coalescer].op_token);
			}
		}
		else {
			for (size_t i = 1; i < rows; i++) {
				fprintf(stream, "\n\t");
				if (i < (rows - 1))
					fprintf(stream, "%s.%c = ", parameter_name_sets[0][0], vcomp_alias[0][i - (i%2)]);
				else
					fprintf(stream, "return ");
#ifdef USE_MINMAX_MACRO
				fprintf(stream, "%s(%s.%c, %s.%c);",
					coalescer == COALESCER_MIN ? "MIN" : "MAX",
#else
				fprintf(stream, "%s.%c %s %s.%c ? %s.%c : %s.%c;",
					parameter_name_sets[0][0], vcomp_alias[0][(i < (rows - 1)) ? i - (i%2) : 0], coalescers[coalescer].op_token,
					parameter_name_sets[0][0], vcomp_alias[0][(i == 2) && (i < (rows - 1)) ? i+1 : i/2 + 1],
#endif
					parameter_name_sets[0][0], vcomp_alias[0][(i < (rows - 1)) ? i - (i%2) : 0],
					parameter_name_sets[0][0], vcomp_alias[0][(i == 2) && (i < (rows - 1)) ? i+1 : i/2 + 1]);
			}
		}
		fprintf(stream, ";\n}\n\n");
	}
}

void gen_func_vector_dot(FILE *stream, enum DataType type, size_t rows, enum FuncGenPassType pass) {
	GEN_VECNAME(vec_name, types[type].name, rows)
	GEN_VECNAME(vec_nickname, types[type].nickname, rows)
	
	PRE_FUNCSIG(stream)
	fprintf(stream, "%s ", types[type].name);
	fprintf(stream, specfuncs[SPECFUNC_DOT_PRODUCT].name_fmt, vec_nickname);
	fprintf(stream, "(%s %s, %s %s)", vec_name, parameter_name_sets[0][0], vec_name, parameter_name_sets[0][1]);
	END_FUNCDEF(stream)
	if (pass == IMPLEMENTATION) {
		fprintf(stream, " {\n\treturn ");
		fprintf(stream, "%s_%s(%s_%s(%s, %s))",
			vec_nickname, coalescers[COALESCER_SUM].name,
			vec_nickname, operators[OPERATOR_MULTIPLICATION].name,
			parameter_name_sets[0][0], parameter_name_sets[0][1]);
		fprintf(stream, ";\n}\n\n");
	}
}

void gen_func_vector_cross(FILE *stream, enum DataType type, size_t rows, enum FuncGenPassType pass) {
	if (specfuncs[SPECFUNC_CROSS_PRODUCT].valid_datatypes[type] == false) return;
	if (rows != (size_t)3) return;
	GEN_VECNAME(vec_name, types[type].name, rows)
	GEN_VECNAME(vec_nickname, types[type].nickname, rows)
	
	PRE_FUNCSIG(stream)
	fprintf(stream, "%s ", vec_name);
	fprintf(stream, specfuncs[SPECFUNC_CROSS_PRODUCT].name_fmt, vec_nickname);
	fprintf(stream, "(%s %s, %s %s)", vec_name, parameter_name_sets[0][0], vec_name, parameter_name_sets[0][1]);
	END_FUNCDEF(stream)
	if (pass == IMPLEMENTATION) {
		fprintf(stream, " {\n\treturn (%s){", vec_name);
		for (size_t j = 0; j < rows; j++) {
			fprintf(stream, "\n\t\t.%c = ", vcomp_alias[0][j]);
			fprintf(stream, "%s.%c*%s.%c -",
				parameter_name_sets[0][0], vcomp_alias[0][(j+1)%rows],
				parameter_name_sets[0][1], vcomp_alias[0][(j+2)%rows]);
			fprintf(stream, " %s.%c*%s.%c,",
				parameter_name_sets[0][0], vcomp_alias[0][(j+2)%rows],
				parameter_name_sets[0][1], vcomp_alias[0][(j+1)%rows]);
		}
		fprintf(stream, "\n\t};\n}\n\n");
	}
}

void gen_func_vector_lensqr(FILE *stream, enum DataType type, size_t rows, enum FuncGenPassType pass) {
	GEN_VECNAME(vec_name, types[type].name, rows)
	GEN_VECNAME(vec_nickname, types[type].nickname, rows)
	
	PRE_FUNCSIG(stream)
	fprintf(stream, "%s ", types[type].name);
	fprintf(stream, specfuncs[SPECFUNC_LENGTH_SQUARED].name_fmt, vec_nickname);
	fprintf(stream, "(%s %s)", vec_name, parameter_name_sets[0][0]);
	END_FUNCDEF(stream)
	if (pass == IMPLEMENTATION) {
		fprintf(stream, " {\n\treturn %s.x*%s.x", parameter_name_sets[0][0], parameter_name_sets[0][0]);
		for (size_t j = 1; j < rows; j++)
			fprintf(stream, " + %s.%c*%s.%c",
				parameter_name_sets[0][0], vcomp_alias[0][j], parameter_name_sets[0][0], vcomp_alias[0][j]);
		fprintf(stream, ";\n}\n\n");
	}
}

void gen_func_vector_len(FILE *stream, enum DataType type, size_t rows, enum FuncGenPassType pass) {
	if (specfuncs[SPECFUNC_LENGTH].valid_datatypes[type] == false) return;
	GEN_VECNAME(vec_name, types[type].name, rows)
	GEN_VECNAME(vec_nickname, types[type].nickname, rows)
	
	PRE_FUNCSIG(stream)
	fprintf(stream, "%s ", types[type].name);
	fprintf(stream, specfuncs[SPECFUNC_LENGTH].name_fmt, vec_nickname);
	fprintf(stream, "(%s %s)", vec_name, parameter_name_sets[0][0]);
	END_FUNCDEF(stream)
	if (pass == IMPLEMENTATION) {
		fprintf(stream, " {\n\treturn sqrt%s(", types[type].func_suffix);
		fprintf(stream, specfuncs[SPECFUNC_LENGTH_SQUARED].name_fmt, vec_nickname);
		fprintf(stream, "(%s));\n}\n\n", parameter_name_sets[0][0]);
	}
}

void gen_func_vector_normalize(FILE *stream, enum DataType type, size_t rows, enum FuncGenPassType pass) {
	if (specfuncs[SPECFUNC_NORMALIZE].valid_datatypes[type] == false) return;
	GEN_VECNAME(vec_name, types[type].name, rows)
	GEN_VECNAME(vec_nickname, types[type].nickname, rows)
	
	PRE_FUNCSIG(stream)
	fprintf(stream, "%s ", vec_name);
	fprintf(stream, specfuncs[SPECFUNC_NORMALIZE].name_fmt, vec_nickname);
	fprintf(stream, "(%s %s)", vec_name, parameter_name_sets[0][0]);
	END_FUNCDEF(stream)
	if (pass == IMPLEMENTATION) {
		fprintf(stream, " {\n\treturn %s_div_%s(%s, ", vec_nickname, types[type].nickname, parameter_name_sets[0][0]);
		fprintf(stream, specfuncs[SPECFUNC_LENGTH].name_fmt, vec_nickname);
		fprintf(stream, "(%s));\n}\n\n", parameter_name_sets[0][0]);
	}
}

void gen_func_matrix_identity(FILE *stream, enum DataType type, size_t rows, enum FuncGenPassType pass) {
	GEN_MATNAME(mat_name, types[type].name, rows)
	GEN_MATNAME(mat_nickname, types[type].nickname, rows)
	
	PRE_FUNCSIG(stream)
	fprintf(stream, "%s ", mat_name);
	fprintf(stream, specfuncs[SPECFUNC_IDENTITY].name_fmt, mat_nickname);
	fprintf(stream, "(void)");
	END_FUNCDEF(stream)
	if (pass == IMPLEMENTATION) {
		fprintf(stream, " {\n\treturn (%s){", mat_name);
		for (size_t j = 0; j < rows; j++) {
			fprintf(stream, "\n\t\t.%c = {{", vcomp_alias[0][j]);
			for (size_t i = 0; i < rows; i++) {
				fprintf(stream, " %c,", j==i ? '1' : '0');
			}
			fprintf(stream, " }},");
		}
		fprintf(stream, "\n\t};\n}\n\n");
	}
}

void gen_func_matrix_elementary(FILE *stream, struct datatype_info type, size_t rows, struct operator_info operator, enum FuncGenPassType pass, enum DimensionType b_dimtype) {
	GEN_MATNAME(mat_name, type.name, rows);
	GEN_MATNAME(mat_nickname, type.nickname, rows);
	GEN_MATNAME(b_name, type.name, rows);
	GEN_MATNAME(b_nickname, type.nickname, rows);
	
	if (b_dimtype == DIM_SCALAR) {
		b_name[strlen(b_name)-3] = '\0';
		b_nickname[strlen(b_nickname)-3] = '\0';
	}
	else if (b_dimtype != DIM_MATRIX) return;
	
	PRE_FUNCSIG(stream)
	fprintf(stream, "%s %s_%s", mat_name, mat_nickname, operator.name);
	if (b_dimtype == DIM_SCALAR) fprintf(stream, "_%s", b_nickname);
	fprintf(stream, "(%s %s, %s %s)", mat_name, parameter_name_sets[0][0], b_name, parameter_name_sets[0][1]);
	END_FUNCDEF(stream)
	else if (pass == IMPLEMENTATION) {
		fprintf(stream,
			" {\n\tfor (unsigned j = 0; j < %zu; j++)\n\t\tfor (unsigned i = 0; i < %zu; i++)\n\t\t\t%s.v[j].c[i] %s= %s",
			rows, rows, parameter_name_sets[0][0], operator.op_token, parameter_name_sets[0][1]);
		if (b_dimtype == DIM_MATRIX) fprintf(stream, ".v[j].c[i]");
		fprintf(stream, ";\n\treturn %s;\n}\n\n", parameter_name_sets[0][0]);
	}
}

void gen_func_matrix_coalesce(FILE *stream, enum DataType type, size_t rows, enum Coalescers coalescer, enum FuncGenPassType pass) {
	GEN_MATNAME(mat_name, types[type].name, rows)
	GEN_MATNAME(mat_nickname, types[type].nickname, rows)
	GEN_VECNAME(vec_nickname, types[type].nickname, rows)
	
	PRE_FUNCSIG(stream)
	fprintf(stream, "%s ", types[type].name);
	fprintf(stream, "%s_%s", mat_nickname, coalescers[coalescer].name);
	fprintf(stream, "(%s %s)", mat_name, parameter_name_sets[0][0]);
	END_FUNCDEF(stream)
	else if (pass == IMPLEMENTATION) {
		fprintf(stream, " {\n\treturn ");
		if (coalescer >= COALESCER_MIN) {
			fprintf(stream, "%s_%s(%s_ctor_", vec_nickname, coalescers[coalescer].name, vec_nickname);
			for (size_t i = 0; i < rows; i++) {
				fprintf(stream, "%s", types[type].nickname);
			}
		}
		fprintf(stream, "(\n\t");
		for (size_t j = 0; j < rows; j++) {
			fprintf(stream, "\t");
			fprintf(stream, "%s_%s(%s.%c)", vec_nickname, coalescers[coalescer].name, parameter_name_sets[0][0], vcomp_alias[0][j]);
			if (j < (rows - 1)) {
				if (coalescer < COALESCER_MIN) fprintf(stream, " %s", coalescers[coalescer].op_token);
				else fprintf(stream, ",");
			}
			// for (size_t i = 0; i < rows; i++) {
			fprintf(stream, "\n\t");
		}
		if (coalescer >= COALESCER_MIN) fprintf(stream, ")");
		fprintf(stream, ");\n}\n\n");
	}
}

void gen_func_matmult_mat_mat(FILE *stream, enum DataType type, size_t rows, enum FuncGenPassType pass) {
	GEN_MATNAME(mat_name, types[type].name, rows)
	GEN_MATNAME(mat_nickname, types[type].nickname, rows)
	
	PRE_FUNCSIG(stream)
	fprintf(stream, "%s %s_matmult_%s(%s %s, %s %s)",
		mat_name, mat_nickname, mat_nickname, mat_name, parameter_name_sets[0][0], mat_name, parameter_name_sets[0][1]);
	END_FUNCDEF(stream)
	if (pass == IMPLEMENTATION) {
		fprintf(stream," {"
			"\n\t%s c = {0};"
			"\n\tfor (unsigned j = 0; j < %zu; j++) {"
			"\n\t\tfor (unsigned i = 0; i < %zu; i++) {"
			"\n\t\t\tfor (unsigned k = 0; k < %zu; k++) {"
			"\n\t\t\t\tc.v[j].c[i] += %s.v[k].c[i]*%s.v[j].c[k];"
			"\n\t\t\t}"
			"\n\t\t}"
			"\n\t}"
			"\n\treturn c;"
			"\n}\n\n",
			mat_name, rows, rows, rows, parameter_name_sets[0][0], parameter_name_sets[0][1]);
	}
}

void gen_func_matmult_mat_cvec(FILE *stream, enum DataType type, size_t rows, enum FuncGenPassType pass) {
	GEN_VECNAME(vec_name, types[type].name, rows)
	GEN_VECNAME(vec_nickname, types[type].nickname, rows)
	GEN_MATNAME(mat_name, types[type].name, rows)
	GEN_MATNAME(mat_nickname, types[type].nickname, rows)
	
	PRE_FUNCSIG(stream)
	fprintf(stream, "%s %s_matmult_%sc(%s %s, %s %s)",
		vec_name, mat_nickname, vec_nickname, mat_name, parameter_name_sets[0][0], vec_name, parameter_name_sets[0][1]);
	END_FUNCDEF(stream)
	if (pass == IMPLEMENTATION) {
		fprintf(stream," {\n\treturn (%s){{", vec_name);
		for (size_t i = 0; i < rows; i++) {
			fprintf(stream, "\n\t\t");
			fprintf(stream, specfuncs[SPECFUNC_DOT_PRODUCT].name_fmt, vec_nickname);
			fprintf(stream, "((%s){{", vec_name);
			// fprintf(stream, "\n\t\t");
			for (size_t k = 0; k < rows; k++) {
				fprintf(stream, " %s.%c%c",
					parameter_name_sets[0][0], vcomp_alias[0][k], vcomp_alias[0][i]);
				// fprintf(stream, "a.%c%c*b.%c",
				// 	vcomp_alias[0][k], vcomp_alias[0][i], vcomp_alias[0][k]);
				if ((k + 1) < rows)
					fprintf(stream, ",");
					// fprintf(stream, " + ");
			}
			fprintf(stream, " }}, %s),", parameter_name_sets[0][1]);
			// fprintf(stream, ",");
		}
		fprintf(stream, "\n\t}};\n}\n\n");
	}
}

void gen_func_matmult_rvec_mat(FILE *stream, enum DataType type, size_t rows, enum FuncGenPassType pass) {
	GEN_VECNAME(vec_name, types[type].name, rows)
	GEN_VECNAME(vec_nickname, types[type].nickname, rows)
	GEN_MATNAME(mat_name, types[type].name, rows)
	GEN_MATNAME(mat_nickname, types[type].nickname, rows)
	
	PRE_FUNCSIG(stream)
	fprintf(stream, "%s %sr_matmult_%s(%s %s, %s %s)",
		vec_name, vec_nickname, mat_nickname, vec_name, parameter_name_sets[0][0], mat_name, parameter_name_sets[0][1]);
	END_FUNCDEF(stream)
	if (pass == IMPLEMENTATION) {
		fprintf(stream," {\n\treturn (%s){{", vec_name);
		for (size_t j = 0; j < rows; j++) {
			fprintf(stream, "\n\t\t");
			fprintf(stream, specfuncs[SPECFUNC_DOT_PRODUCT].name_fmt, vec_nickname);
			fprintf(stream, "(%s, %s.%c),", parameter_name_sets[0][0], parameter_name_sets[0][1], vcomp_alias[0][j]);
		}
		fprintf(stream, "\n\t}};\n}\n\n");
	}
}

void gen_func_matrix_transpose(FILE *stream, enum DataType type, size_t rows, enum FuncGenPassType pass) {
	GEN_MATNAME(mat_name, types[type].name, rows)
	GEN_MATNAME(mat_nickname, types[type].nickname, rows)
	
	PRE_FUNCSIG(stream)
	fprintf(stream, "%s ", mat_name);
	fprintf(stream, specfuncs[SPECFUNC_TRANSPOSE].name_fmt, mat_nickname);
	fprintf(stream, "(%s %s)", mat_name, parameter_name_sets[0][0]);
	END_FUNCDEF(stream)
	if (pass == IMPLEMENTATION) {
		fprintf(stream, " {\n\treturn (%s){", mat_name);
		for (size_t j = 0; j < rows; j++) {
			fprintf(stream, "\n\t\t.%c = {{", vcomp_alias[0][j]);
			for (size_t i = 0; i < rows; i++) {
				fprintf(stream, " %s.%c%c,", parameter_name_sets[0][0], vcomp_alias[0][i], vcomp_alias[0][j]);
			}
			fprintf(stream, " }},");
		}
		fprintf(stream, "\n\t};\n}\n\n");
	}
}

void gen_func_matrix_scale(FILE *stream, enum DataType type, size_t rows, enum FuncGenPassType pass) {
	GEN_MATNAME(mat_name, types[type].name, rows)
	GEN_MATNAME(mat_nickname, types[type].nickname, rows)
	GEN_VECNAME(vec_name, types[type].name, rows)
	
	PRE_FUNCSIG(stream)
	fprintf(stream, "%s ", mat_name);
	fprintf(stream, specfuncs[SPECFUNC_SCALE].name_fmt, mat_nickname);
	fprintf(stream, "(%s %s)", vec_name, parameter_name_sets[PARAMNAMESET_MAT_BY][1]);
	END_FUNCDEF(stream)
	if (pass == IMPLEMENTATION) {
		fprintf(stream, " {\n\t%s mat = {0};", mat_name);
		for (size_t j = 0; j < rows; j++) {
			fprintf(stream, "\n\tmat.%c%c = %s.%c;",
				vcomp_alias[0][j], vcomp_alias[0][j],
				parameter_name_sets[PARAMNAMESET_MAT_BY][1], vcomp_alias[0][j]);
		}
		fprintf(stream, "\n\treturn mat;\n}\n\n");
	}
}

void gen_func_matrix_rotate(FILE *stream, enum DataType type, size_t rows, enum FuncGenPassType pass) {
	if (specfuncs[SPECFUNC_ROTATE].valid_datatypes[type] == false) return;
	if (specfuncs[SPECFUNC_ROTATE].valid_rows[rows] == false) return;
	GEN_MATNAME(mat_name, types[type].name, rows)
	GEN_MATNAME(mat_nickname, types[type].nickname, rows)
	GEN_VECNAME(vec_name, types[type].name, (size_t)3)
	
	PRE_FUNCSIG(stream)
	fprintf(stream, "%s ", mat_name);
	fprintf(stream, specfuncs[SPECFUNC_ROTATE].name_fmt, mat_nickname);
	fprintf(stream, "(%s %s, %s %s)",
		types[type].name, "angle",
		vec_name, "axis");
	END_FUNCDEF(stream)
	if (pass == IMPLEMENTATION) {
		fprintf(stream, " {");
		fprintf(stream, "\n\t%s cosangle = cos%s(angle);", types[type].name, types[type].func_suffix);
		fprintf(stream, "\n\t%s sinangle = sin%s(angle);", types[type].name, types[type].func_suffix);
		fprintf(stream, "\n\t%s mat = {", mat_name);
		for (size_t j = 0; j < (size_t)3; j++) {
			fprintf(stream, "\n\t\t.%c = {{", vcomp_alias[0][j]);
			for (size_t i = 0; i < (size_t)3; i++)
				fprintf(stream, " axis.%c*axis.%c*(1.0%s-cosangle),",
					vcomp_alias[0][j], vcomp_alias[0][i], types[type].func_suffix);
			if (rows == (size_t)4)
				fprintf(stream, " 0.0%s,", types[type].func_suffix);
			fprintf(stream, " }},");
		}
		if (rows == (size_t)4)
			fprintf(stream, "\n\t\t.w = {{ 0.0%s, 0.0%s, 0.0%s, 1.0%s, }},",
				types[type].func_suffix, types[type].func_suffix, types[type].func_suffix, types[type].func_suffix);
		fprintf(stream, "\n\t};\n\treturn %s_add(mat, (%s){", mat_nickname, mat_name);
		for (size_t j = 0; j < (size_t)3; j++) {
			fprintf(stream, "\n\t\t.%c = {{", vcomp_alias[0][j]);
			for (size_t i = 0; i < (size_t)3; i++) {
				if (j==i)
					fprintf(stream, "         cosangle,");
				else
					fprintf(stream, " %caxis.%c*sinangle,", j==((i+1)%3) ? '-' : ' ', vcomp_alias[0][(6-i-j)%3]);
			}
			if (rows == (size_t)4)
				fprintf(stream, " 0.0%s,", types[type].func_suffix);
			fprintf(stream, " }},");
		}
		if (rows == (size_t)4)
			fprintf(stream, "\n\t\t.w = {{ 0.0%s, 0.0%s, 0.0%s, 0.0%s, }},",
				types[type].func_suffix, types[type].func_suffix, types[type].func_suffix, types[type].func_suffix);
		fprintf(stream, "\n\t});\n}\n\n");
	}
}

void gen_func_matrix_translate(FILE *stream, enum DataType type, size_t rows, enum FuncGenPassType pass) {
	if (specfuncs[SPECFUNC_TRANSLATE].valid_rows[rows] == false) return;
	GEN_MATNAME(mat_name, types[type].name, rows)
	GEN_MATNAME(mat_nickname, types[type].nickname, rows)
	GEN_VECNAME(vec_name, types[type].name, rows)
	GEN_VECNAME(vec_namem1, types[type].name, (rows-1))
	
	PRE_FUNCSIG(stream)
	fprintf(stream, "%s ", mat_name);
	fprintf(stream, specfuncs[SPECFUNC_TRANSLATE].name_fmt, mat_nickname);
	fprintf(stream, "(%s %s)", vec_namem1, parameter_name_sets[PARAMNAMESET_MAT_BY][1]);
	END_FUNCDEF(stream)
	if (pass == IMPLEMENTATION) {
		fprintf(stream, " {\n\t%s mat = {0};", mat_name);
		for (size_t j = 0; j < (rows - 1); j++) {
			fprintf(stream, "\n\tmat.%c%c = 1.0;",
				vcomp_alias[0][j], vcomp_alias[0][j]);
		}
		fprintf(stream, "\n\tmat.w = (%s){{ %s.x, %s.y, %s.z, 1.0 }};",
			vec_name,
			parameter_name_sets[PARAMNAMESET_MAT_BY][1],
			parameter_name_sets[PARAMNAMESET_MAT_BY][1],
			parameter_name_sets[PARAMNAMESET_MAT_BY][1]);
		fprintf(stream, "\n\treturn mat;\n}\n\n");
	}
}

int main(void) {
	fprintf(stdout,
		"#ifndef LLAL_H\n"
		"#define LLAL_H\n"
		"\n"
		"#include <math.h>\n"
		"\n"
		"#ifdef LLAL_USE_STATIC_INLINE\n"
		"#define LLAL_INLINE static inline\n"
		"#if !defined LLAL_IMPLEMENTATION\n"
		"#define LLAL_IMPLEMENTATION\n"
		"#endif\n"
		"#else\n"
		"#define LLAL_INLINE\n"
		"#endif\n"
#ifdef USE_MINMAX_MACRO
		"\n"
		"#ifndef MIN\n"
		"#define MIN(a, b) ((a) < (b) ? (a) : (b))\n"
		"#endif\n"
		"#ifndef MAX\n"
		"#define MAX(a, b) ((a) > (b) ? (a) : (b))\n"
		"#endif\n"
#endif
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
		if (pass == DEFINITION)
			fprintf(stdout,
				"\n"
				"#ifndef LLAL_USE_STATIC_INLINE\n");
		if (pass == IMPLEMENTATION)
			fprintf(stdout,
				"#endif // !LLAL_USE_STATIC_INLINE\n"
				"\n"
				"#ifdef LLAL_IMPLEMENTATION\n");
		// Scalar functions
		// for (size_t type = 0; type < DATATYPES_COUNT; type++) {
		// }
		// Vector functions
		for (size_t n = 2; n <= V_MAX_COMPS; n++) {
			for (size_t type = 0; type < DATATYPES_COUNT; type++) {
				fprintf(stdout, "\n");
				gen_ctor_vector(stdout, types[type], n, pass);
				for (size_t operator = 0; operator < OPERATORS_COUNT; operator++) {
					gen_func_vector_elementary(stdout, types[type], n, operators[operator], pass, DIM_VECTOR);
					gen_func_vector_elementary(stdout, types[type], n, operators[operator], pass, DIM_SCALAR);
				}
				for (size_t coalescer = 0; coalescer < COALESCERS_COUNT; coalescer++) {
					gen_func_vector_coalesce(stdout, type, n, coalescer, pass);
				}
				gen_func_vector_dot(stdout, type, n, pass);
				gen_func_vector_cross(stdout, type, n, pass);
				gen_func_vector_lensqr(stdout, type, n, pass);
				gen_func_vector_len(stdout, type, n, pass);
				gen_func_vector_normalize(stdout, type, n, pass);
			}
		}
		// Matrix functions
		for (size_t n = 2; n <= V_MAX_COMPS; n++) {
			for (size_t type = 0; type < DATATYPES_COUNT; type++) {
				fprintf(stdout, "\n");
				gen_func_matrix_identity(stdout, type, n, pass);
				for (size_t operator = 0; operator < OPERATORS_COUNT; operator++) {
					gen_func_matrix_elementary(stdout, types[type], n, operators[operator], pass, DIM_MATRIX);
					gen_func_matrix_elementary(stdout, types[type], n, operators[operator], pass, DIM_SCALAR);
				}
				for (size_t coalescer = 0; coalescer < COALESCERS_COUNT; coalescer++) {
					gen_func_matrix_coalesce(stdout, type, n, coalescer, pass);
				}
				gen_func_matmult_mat_mat(stdout, type, n, pass);
				gen_func_matmult_mat_cvec(stdout, type, n, pass);
				gen_func_matmult_rvec_mat(stdout, type, n, pass);
				gen_func_matrix_transpose(stdout, type, n, pass);
				gen_func_matrix_scale(stdout, type, n, pass);
				gen_func_matrix_rotate(stdout, type, n, pass);
				gen_func_matrix_translate(stdout, type, n, pass);
			}
		}
#		ifdef GENERATE_SWIZZLING
		// Swizzling
		for (size_t n = 1; n <= V_MAX_COMPS; n++) {
			for (size_t type = 0; type < DATATYPES_COUNT; type++) {
				fprintf(stdout, "\n");
				gen_swizzle_vector(stdout, types[type], n, pass);
			}
		}
#		endif //ifdef GENERATE_SWIZZLING
		if (pass == DEFINITION)
			fprintf(stdout, "\n");
	}
	fprintf(stdout, "#endif // ifdef LLAL_IMPLEMENTATION\n");
	fprintf(stdout, "#endif // ifndef LLAL_H");
	return 0;
}