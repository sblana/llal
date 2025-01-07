/* TODO:
- remove `typedef unsigned uint`
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
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


#define GEN_VECNAME(name, str, N) char name[strlen(str)+1]; \
								sprintf(name, "%s%zu", str, N);

enum FuncGenPassType {
	DEFINITION = 0,
	IMPLEMENTATION,
};

struct type_info {
	char *name;
	char *nickname;
};

#define TYPES_COUNT 4
const struct type_info types[TYPES_COUNT] = {
	{"float", "f"},
	{"double", "d"},
	{"int", "i"},
	{"uint", "u"},
};


struct operator_info {
	char *name;
	char *symbol;
};

#define OPERATORS_COUNT 4
const struct operator_info operators[OPERATORS_COUNT] = {
	{"add", "+"},
	{"sub", "-"},
	{"mul", "*"},
	{"div", "/"},
};


#define V_MAX_COMPS 4
#define V_COMP_ALIAS_SETS 3

const char vcomp_alias[V_COMP_ALIAS_SETS][V_MAX_COMPS] = {
	{'x','y','z','w'},
	{'r','g','b','a'},
	{'s','t','p','q'},
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

void gen_func_vector_elementary(FILE *stream, struct type_info type, size_t rows, struct operator_info operator, enum FuncGenPassType pass) {
	GEN_VECNAME(vec_name, type.name, rows)
	GEN_VECNAME(vec_nickname, type.nickname, rows)
	
	fprintf(stream,
		"%s %s_%s(%s a, %s b)",
		vec_name, vec_nickname, operator.name, vec_name, vec_name);
	if (pass == DEFINITION)
		fprintf(stream, ";\n");
	else if (pass == IMPLEMENTATION)
		fprintf(stream, " {\n"
				"\tfor (size_t i = 0; i < %zu; i++) a.c[i] %s= b.c[i];\n"
				"\treturn a;\n"
			"}\n\n",
			rows, operator.symbol);
}

void gen_func_vector_scalar_elementary(FILE *stream, struct type_info type, size_t rows, struct operator_info operator, enum FuncGenPassType pass) {
	GEN_VECNAME(vec_name, type.name, rows);
	GEN_VECNAME(vec_nickname, type.nickname, rows);
	
	fprintf(stream,
		"%s %s_%s_%s(%s a, %s b)",
		vec_name, vec_nickname, operator.name, type.nickname, vec_name, type.name);
	if (pass == DEFINITION)
		fprintf(stream, ";\n");
	else if (pass == IMPLEMENTATION)
		fprintf(stream, " {\n"
				"\tfor (size_t i = 0; i < %zu; i++) a.c[i] %s= b;\n"
				"\treturn a;\n"
			"}\n\n",
			rows, operator.symbol);
}

void gen_func_vector_dot(FILE *stream, struct type_info type, size_t rows, enum FuncGenPassType pass) {
	GEN_VECNAME(vec_name, type.name, rows)
	GEN_VECNAME(vec_nickname, type.nickname, rows)
	
	fprintf(stream,
		"%s %s_dot(%s a, %s b)",
		type.name, vec_nickname, vec_name, vec_name);
	if (pass == DEFINITION)
		fprintf(stream, ";\n");
	else if (pass == IMPLEMENTATION) {
		fprintf(stream, " {\n"
				"\treturn a.x*b.x");
		for (size_t j = 1; j < rows; j++)
			fprintf(stream, " + a.%c*b.%c", vcomp_alias[0][j], vcomp_alias[0][j]);
		fprintf(stream, ";\n}\n\n");
	}
}

void gen_func_vector_lensqr(FILE *stream, struct type_info type, size_t rows, enum FuncGenPassType pass) {
	GEN_VECNAME(vec_name, type.name, rows)
	GEN_VECNAME(vec_nickname, type.nickname, rows)
	
	fprintf(stream,
		"%s %s_lensqr(%s a)",
		type.name, vec_nickname, vec_name);
	if (pass == DEFINITION)
		fprintf(stream, ";\n");
	else if (pass == IMPLEMENTATION) {
		fprintf(stream, " {\n\treturn a.x*a.x");
		for (size_t j = 1; j < rows; j++)
			fprintf(stream, " + a.%c*a.%c", vcomp_alias[0][j], vcomp_alias[0][j]);
		fprintf(stream, ";\n}\n\n");
	}
}

void gen_func_vector_len(FILE *stream, struct type_info type, size_t rows, enum FuncGenPassType pass) {
	if (abs(strcmp(type.name, "float")) && abs(strcmp(type.name, "double"))) return;
	GEN_VECNAME(vec_name, type.name, rows)
	GEN_VECNAME(vec_nickname, type.nickname, rows)
	
	fprintf(stream,
		"%s %s_len(%s a)",
		type.name, vec_nickname, vec_name);
	if (pass == DEFINITION)
		fprintf(stream, ";\n");
	else if (pass == IMPLEMENTATION) {
		fprintf(stream, " {\n\treturn sqrt");
		if (strcmp(type.name, "float") == 0)
			fprintf(stream, "%c", 'f');
		fprintf(stream, "(%s_lensqr(a));\n}\n\n", vec_nickname);
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
		"\n"
		"typedef unsigned uint;\n");
	for (size_t n = 2; n <= V_MAX_COMPS; n++) {
		fprintf(stdout, "\n");
		for (size_t type = 0; type < TYPES_COUNT; type++)
			gen_def_vector(stdout, types[type].name, n);
	}
	for (size_t n = 2; n <= V_MAX_COMPS; n++) {
		fprintf(stdout, "\n");
		for (size_t type = 0; type < TYPES_COUNT; type++)
			gen_def_matrix(stdout, types[type].name, n);
	}
	for (enum FuncGenPassType pass = DEFINITION; pass <= IMPLEMENTATION; pass++) {
		if (pass == IMPLEMENTATION)
			fprintf(stdout, "\n#ifdef LLAL_IMPLEMENTATION\n");
		for (size_t n = 2; n <= V_MAX_COMPS; n++) {
			for (size_t type = 0; type < TYPES_COUNT; type++) {
				fprintf(stdout, "\n");
				for (size_t operator = 0; operator < OPERATORS_COUNT; operator++) {
					gen_func_vector_elementary(stdout, types[type], n, operators[operator], pass);
					gen_func_vector_scalar_elementary(stdout, types[type], n, operators[operator], pass);
				}
				gen_func_vector_dot(stdout, types[type], n, pass);
				gen_func_vector_lensqr(stdout, types[type], n, pass);
				gen_func_vector_len(stdout, types[type], n, pass);
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