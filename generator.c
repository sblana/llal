/* TODO:
- func: vec clamp, scalar
- func: vec min max, scalar
- func: vec min max, scalar
- func: vec floor, ceil
- func: vec lerp, slerp
- func: mat determinant
- func: mat lerp, slerp
- macro: mat identity constructor
- macro: vec axis constructor
- macro: print formatù
- mat constructors
- conversion
- rotation, scale, translate?
- something with perspective distortions?
- quaternion?
- some kind of swizzling? min ~4000 lines via functions.
- bool vectors?
- quadruple?
- function inlining?
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

struct func_info {
	char *name_fmt;
	bool valid_datatypes[DATATYPES_COUNT];
	size_t arity;
};

enum SpecFunc {
	SPECFUNC_LENGTH_SQUARED = 0,
	SPECFUNC_LENGTH,
	SPECFUNC_NORMALIZE,
	SPECFUNC_DOT_PRODUCT,
	SPECFUNC_CROSS_PRODUCT,
	SPECFUNC_TRANSPOSE,
	SPECFUNCS_COUNT,
};

const struct func_info specfuncs[SPECFUNCS_COUNT] = {
	[SPECFUNC_LENGTH_SQUARED] = {
		.name_fmt = "%s_lensqr",
		.valid_datatypes = {
			[DATATYPE_FLOAT]	= true,
			[DATATYPE_DOUBLE]	= true,
			[DATATYPE_INT]		= true,
			[DATATYPE_UNSIGNED] = true,
		},
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
		.valid_datatypes = {
			[DATATYPE_FLOAT]	= true,
			[DATATYPE_DOUBLE]	= true,
			[DATATYPE_INT]		= true,
			[DATATYPE_UNSIGNED] = true,
		},
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
		.valid_datatypes = {
			[DATATYPE_FLOAT]	= true,
			[DATATYPE_DOUBLE]	= true,
			[DATATYPE_INT]		= true,
			[DATATYPE_UNSIGNED] = true,
		},
		.arity = 1,
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
		vecrow_names[i][strlen(vec_name) - 1] = (i == 0) ? '\0' : '1' + i;
		vecrow_nicknames[i][strlen(vec_nickname) - 1] = (i == 0) ? '\0' : '1' + i;
	}
	for (int arity = 1; (size_t)arity <= rows; arity++) {
		for (int i = 0; i < pow(rows, arity); i++) {
			// generate potential constructors
			int param_rows[arity];
			int temp = i;
			size_t sum = 0;
			for (int j = 0; j < arity; j++) {
				param_rows[j] = (temp % rows) + 1;
				sum += param_rows[j];
				temp /= rows;
			}
			
			// discard invalid constructors
			if (sum != 1 && sum != rows) continue;
			
			// generate parameter names
			char param_names[arity][5];
			int comps_remaining = rows;
			for (int param = 0; param < arity; param++) {
				for (int j = 0; j < param_rows[param]; j++) {
					param_names[param][j] = vcomp_alias[0][rows - comps_remaining];
					comps_remaining--;
				}
				param_names[param][param_rows[param]] = '\0';
			}
			
			// writing return type and func symbol
			fprintf(stream, "%s %s_ctor_",
				vec_name, vec_nickname);
			for (int param = 0; param < arity; param++) {
				fprintf(stream, "%s", vecrow_nicknames[param_rows[param]-1]);
			}
			// writing parameters
			fprintf(stream, "(");
			for (int param = 0; param < arity; param++) {
				fprintf(stream, "%s %s",
					vecrow_names[param_rows[param]-1], param_names[param]);
				if (param < (arity - 1)) fprintf(stream, ", ");
			}
			fprintf(stream, ")");
			
			END_FUNCDEF(stream)
			else if (pass == IMPLEMENTATION) {
				fprintf(stream, "{\n\treturn (%s){{", vec_name);
				comps_remaining = rows;
				for (int param = 0; param < arity; param++) {
					for (int j = 0; j < param_rows[param]; j++) {
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
	for (int return_rows = 2; return_rows <= V_MAX_COMPS; return_rows++) {
		GEN_VECNAME(ret_name, type.name, (size_t)return_rows)
		for (int i = 0; i < pow(rows, return_rows); i++) {
			// generate return swizzles
			int return_swizzle[return_rows];
			int temp = i;
			size_t sum = 0;
			for (int j = 0; j < return_rows; j++) {
				return_swizzle[j] = (temp % rows);
				sum += return_swizzle[j];
				temp /= rows;
			}
			
			// writing return type and func symbol
			fprintf(stream, "%s %s_",
				ret_name, vec_nickname);
			for (int comp = 0; comp < return_rows; comp++) {
				fprintf(stream, "%c", vcomp_alias[0][return_swizzle[comp]]);
			}
			fprintf(stream, "(%s %s)", vec_name, parameter_name_sets[0][0]);
			END_FUNCDEF(stream)
			else if (pass == IMPLEMENTATION) {
				fprintf(stream, "{return (%s){{", ret_name);
				for (int comp = 0; comp < return_rows; comp++) {
					fprintf(stream, " %s", parameter_name_sets[0][0]);
					if (rows > 1)
						fprintf(stream, ".%c", vcomp_alias[0][return_swizzle[comp]]);
					if (comp < (return_rows - 1))
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

void gen_func_vector_dot(FILE *stream, enum DataType type, size_t rows, enum FuncGenPassType pass) {
	if (specfuncs[SPECFUNC_DOT_PRODUCT].valid_datatypes[type] == false) return;
	GEN_VECNAME(vec_name, types[type].name, rows)
	GEN_VECNAME(vec_nickname, types[type].nickname, rows)
	
	fprintf(stream, "%s ", types[type].name);
	fprintf(stream, specfuncs[SPECFUNC_DOT_PRODUCT].name_fmt, vec_nickname);
	fprintf(stream, "(%s %s, %s %s)", vec_name, parameter_name_sets[0][0], vec_name, parameter_name_sets[0][1]);
	END_FUNCDEF(stream)
	if (pass == IMPLEMENTATION) {
		fprintf(stream, " {\n\treturn %s.x*%s.x", parameter_name_sets[0][0], parameter_name_sets[0][1]);
		for (size_t j = 1; j < rows; j++)
			fprintf(stream, " + %s.%c*%s.%c",
				parameter_name_sets[0][0], vcomp_alias[0][j], parameter_name_sets[0][1], vcomp_alias[0][j]);
		fprintf(stream, ";\n}\n\n");
	}
}

void gen_func_vector_cross(FILE *stream, enum DataType type, size_t rows, enum FuncGenPassType pass) {
	if (specfuncs[SPECFUNC_CROSS_PRODUCT].valid_datatypes[type] == false) return;
	if (rows != (size_t)3) return;
	GEN_VECNAME(vec_name, types[type].name, rows)
	GEN_VECNAME(vec_nickname, types[type].nickname, rows)
	
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
	if (specfuncs[SPECFUNC_LENGTH_SQUARED].valid_datatypes[type] == false) return;
	GEN_VECNAME(vec_name, types[type].name, rows)
	GEN_VECNAME(vec_nickname, types[type].nickname, rows)
	
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
	
	fprintf(stream, "%s ", types[type].name);
	fprintf(stream, specfuncs[SPECFUNC_LENGTH].name_fmt, vec_nickname);
	fprintf(stream, "(%s %s)", vec_name, parameter_name_sets[0][0]);
	END_FUNCDEF(stream)
	if (pass == IMPLEMENTATION) {
		fprintf(stream, " {\n\treturn sqrt");
		if (type != DATATYPE_DOUBLE)
			fprintf(stream, "%c", types[type].func_suffix);
		fprintf(stream, "(");
		fprintf(stream, specfuncs[SPECFUNC_LENGTH_SQUARED].name_fmt, vec_nickname);
		fprintf(stream, "(%s));\n}\n\n", parameter_name_sets[0][0]);
	}
}

void gen_func_vector_normalize(FILE *stream, enum DataType type, size_t rows, enum FuncGenPassType pass) {
	if (specfuncs[SPECFUNC_NORMALIZE].valid_datatypes[type] == false) return;
	GEN_VECNAME(vec_name, types[type].name, rows)
	GEN_VECNAME(vec_nickname, types[type].nickname, rows)
	
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

void gen_func_matmult_mat_mat(FILE *stream, enum DataType type, size_t rows, enum FuncGenPassType pass) {
	GEN_MATNAME(mat_name, types[type].name, rows)
	GEN_MATNAME(mat_nickname, types[type].nickname, rows)
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
	if (specfuncs[SPECFUNC_TRANSPOSE].valid_datatypes[type] == false) return;
	GEN_MATNAME(mat_name, types[type].name, rows)
	GEN_MATNAME(mat_nickname, types[type].nickname, rows)
	
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

int main() {
	fprintf(stdout,
		"#ifndef LLAL_H\n"
		"#define LLAL_H\n"
		"\n"
		"#include <math.h>\n"
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
				for (size_t operator = 0; operator < OPERATORS_COUNT; operator++) {
					gen_func_matrix_elementary(stdout, types[type], n, operators[operator], pass, DIM_MATRIX);
					gen_func_matrix_elementary(stdout, types[type], n, operators[operator], pass, DIM_SCALAR);
				}
				gen_func_matmult_mat_mat(stdout, type, n, pass);
				gen_func_matmult_mat_cvec(stdout, type, n, pass);
				gen_func_matmult_rvec_mat(stdout, type, n, pass);
				gen_func_matrix_transpose(stdout, type, n, pass);
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