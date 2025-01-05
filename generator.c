#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define GEN_VECNAME(name, T, N) char name[strlen(T)+1]; \
								sprintf(name, "%s%zu", T, N);

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


void gen_func_vector_elementary(FILE *stream, struct type_info type, size_t rows, struct operator_info operator, enum FuncGenPassType pass) {
	GEN_VECNAME(vec_name, type.name, rows);
	GEN_VECNAME(vec_nickname, type.nickname, rows);
	
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


int main() {
	fprintf(stdout, "#ifndef LLAL_H\n\n");
	fprintf(stdout, "#define LLAL_H\n\n");
	fprintf(stdout, "#include <stdlib.h>\n\n");
	fprintf(stdout, "\n");
	fprintf(stdout, "typedef unsigned uint;\n");
	for (size_t n = 2; n <= V_MAX_COMPS; n++) {
		fprintf(stdout, "\n");
		for (size_t type = 0; type < TYPES_COUNT; type++) {
			gen_def_vector(stdout, types[type].name, n);
		}
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
			}
		}
		if (pass == DEFINITION)
			fprintf(stdout, "\n");
	}
	fprintf(stdout, "#endif // ifdef LLAL_IMPLEMENTATION\n");
	fprintf(stdout, "#endif // ifndef LLAL_H");
	return 0;
}