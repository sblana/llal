#ifndef LLAL_H

#define LLAL_H

#include <stdlib.h>


typedef unsigned uint;

typedef union {
	float c[2];
	struct { float x, y; };
	struct { float r, g; };
	struct { float s, t; };
} float2;

typedef union {
	double c[2];
	struct { double x, y; };
	struct { double r, g; };
	struct { double s, t; };
} double2;

typedef union {
	int c[2];
	struct { int x, y; };
	struct { int r, g; };
	struct { int s, t; };
} int2;

typedef union {
	uint c[2];
	struct { uint x, y; };
	struct { uint r, g; };
	struct { uint s, t; };
} uint2;


typedef union {
	float c[3];
	struct { float x, y, z; };
	struct { float r, g, b; };
	struct { float s, t, p; };
} float3;

typedef union {
	double c[3];
	struct { double x, y, z; };
	struct { double r, g, b; };
	struct { double s, t, p; };
} double3;

typedef union {
	int c[3];
	struct { int x, y, z; };
	struct { int r, g, b; };
	struct { int s, t, p; };
} int3;

typedef union {
	uint c[3];
	struct { uint x, y, z; };
	struct { uint r, g, b; };
	struct { uint s, t, p; };
} uint3;


typedef union {
	float c[4];
	struct { float x, y, z, w; };
	struct { float r, g, b, a; };
	struct { float s, t, p, q; };
} float4;

typedef union {
	double c[4];
	struct { double x, y, z, w; };
	struct { double r, g, b, a; };
	struct { double s, t, p, q; };
} double4;

typedef union {
	int c[4];
	struct { int x, y, z, w; };
	struct { int r, g, b, a; };
	struct { int s, t, p, q; };
} int4;

typedef union {
	uint c[4];
	struct { uint x, y, z, w; };
	struct { uint r, g, b, a; };
	struct { uint s, t, p, q; };
} uint4;


float2 f2_add(float2 a, float2 b);
float2 f2_add_f(float2 a, float b);
float2 f2_sub(float2 a, float2 b);
float2 f2_sub_f(float2 a, float b);
float2 f2_mul(float2 a, float2 b);
float2 f2_mul_f(float2 a, float b);
float2 f2_div(float2 a, float2 b);
float2 f2_div_f(float2 a, float b);

double2 d2_add(double2 a, double2 b);
double2 d2_add_d(double2 a, double b);
double2 d2_sub(double2 a, double2 b);
double2 d2_sub_d(double2 a, double b);
double2 d2_mul(double2 a, double2 b);
double2 d2_mul_d(double2 a, double b);
double2 d2_div(double2 a, double2 b);
double2 d2_div_d(double2 a, double b);

int2 i2_add(int2 a, int2 b);
int2 i2_add_i(int2 a, int b);
int2 i2_sub(int2 a, int2 b);
int2 i2_sub_i(int2 a, int b);
int2 i2_mul(int2 a, int2 b);
int2 i2_mul_i(int2 a, int b);
int2 i2_div(int2 a, int2 b);
int2 i2_div_i(int2 a, int b);

uint2 u2_add(uint2 a, uint2 b);
uint2 u2_add_u(uint2 a, uint b);
uint2 u2_sub(uint2 a, uint2 b);
uint2 u2_sub_u(uint2 a, uint b);
uint2 u2_mul(uint2 a, uint2 b);
uint2 u2_mul_u(uint2 a, uint b);
uint2 u2_div(uint2 a, uint2 b);
uint2 u2_div_u(uint2 a, uint b);

float3 f3_add(float3 a, float3 b);
float3 f3_add_f(float3 a, float b);
float3 f3_sub(float3 a, float3 b);
float3 f3_sub_f(float3 a, float b);
float3 f3_mul(float3 a, float3 b);
float3 f3_mul_f(float3 a, float b);
float3 f3_div(float3 a, float3 b);
float3 f3_div_f(float3 a, float b);

double3 d3_add(double3 a, double3 b);
double3 d3_add_d(double3 a, double b);
double3 d3_sub(double3 a, double3 b);
double3 d3_sub_d(double3 a, double b);
double3 d3_mul(double3 a, double3 b);
double3 d3_mul_d(double3 a, double b);
double3 d3_div(double3 a, double3 b);
double3 d3_div_d(double3 a, double b);

int3 i3_add(int3 a, int3 b);
int3 i3_add_i(int3 a, int b);
int3 i3_sub(int3 a, int3 b);
int3 i3_sub_i(int3 a, int b);
int3 i3_mul(int3 a, int3 b);
int3 i3_mul_i(int3 a, int b);
int3 i3_div(int3 a, int3 b);
int3 i3_div_i(int3 a, int b);

uint3 u3_add(uint3 a, uint3 b);
uint3 u3_add_u(uint3 a, uint b);
uint3 u3_sub(uint3 a, uint3 b);
uint3 u3_sub_u(uint3 a, uint b);
uint3 u3_mul(uint3 a, uint3 b);
uint3 u3_mul_u(uint3 a, uint b);
uint3 u3_div(uint3 a, uint3 b);
uint3 u3_div_u(uint3 a, uint b);

float4 f4_add(float4 a, float4 b);
float4 f4_add_f(float4 a, float b);
float4 f4_sub(float4 a, float4 b);
float4 f4_sub_f(float4 a, float b);
float4 f4_mul(float4 a, float4 b);
float4 f4_mul_f(float4 a, float b);
float4 f4_div(float4 a, float4 b);
float4 f4_div_f(float4 a, float b);

double4 d4_add(double4 a, double4 b);
double4 d4_add_d(double4 a, double b);
double4 d4_sub(double4 a, double4 b);
double4 d4_sub_d(double4 a, double b);
double4 d4_mul(double4 a, double4 b);
double4 d4_mul_d(double4 a, double b);
double4 d4_div(double4 a, double4 b);
double4 d4_div_d(double4 a, double b);

int4 i4_add(int4 a, int4 b);
int4 i4_add_i(int4 a, int b);
int4 i4_sub(int4 a, int4 b);
int4 i4_sub_i(int4 a, int b);
int4 i4_mul(int4 a, int4 b);
int4 i4_mul_i(int4 a, int b);
int4 i4_div(int4 a, int4 b);
int4 i4_div_i(int4 a, int b);

uint4 u4_add(uint4 a, uint4 b);
uint4 u4_add_u(uint4 a, uint b);
uint4 u4_sub(uint4 a, uint4 b);
uint4 u4_sub_u(uint4 a, uint b);
uint4 u4_mul(uint4 a, uint4 b);
uint4 u4_mul_u(uint4 a, uint b);
uint4 u4_div(uint4 a, uint4 b);
uint4 u4_div_u(uint4 a, uint b);


#ifdef LLAL_IMPLEMENTATION

float2 f2_add(float2 a, float2 b) {
	for (size_t i = 0; i < 2; i++) a.c[i] += b.c[i];
	return a;
}

float2 f2_add_f(float2 a, float b) {
	for (size_t i = 0; i < 2; i++) a.c[i] += b;
	return a;
}

float2 f2_sub(float2 a, float2 b) {
	for (size_t i = 0; i < 2; i++) a.c[i] -= b.c[i];
	return a;
}

float2 f2_sub_f(float2 a, float b) {
	for (size_t i = 0; i < 2; i++) a.c[i] -= b;
	return a;
}

float2 f2_mul(float2 a, float2 b) {
	for (size_t i = 0; i < 2; i++) a.c[i] *= b.c[i];
	return a;
}

float2 f2_mul_f(float2 a, float b) {
	for (size_t i = 0; i < 2; i++) a.c[i] *= b;
	return a;
}

float2 f2_div(float2 a, float2 b) {
	for (size_t i = 0; i < 2; i++) a.c[i] /= b.c[i];
	return a;
}

float2 f2_div_f(float2 a, float b) {
	for (size_t i = 0; i < 2; i++) a.c[i] /= b;
	return a;
}


double2 d2_add(double2 a, double2 b) {
	for (size_t i = 0; i < 2; i++) a.c[i] += b.c[i];
	return a;
}

double2 d2_add_d(double2 a, double b) {
	for (size_t i = 0; i < 2; i++) a.c[i] += b;
	return a;
}

double2 d2_sub(double2 a, double2 b) {
	for (size_t i = 0; i < 2; i++) a.c[i] -= b.c[i];
	return a;
}

double2 d2_sub_d(double2 a, double b) {
	for (size_t i = 0; i < 2; i++) a.c[i] -= b;
	return a;
}

double2 d2_mul(double2 a, double2 b) {
	for (size_t i = 0; i < 2; i++) a.c[i] *= b.c[i];
	return a;
}

double2 d2_mul_d(double2 a, double b) {
	for (size_t i = 0; i < 2; i++) a.c[i] *= b;
	return a;
}

double2 d2_div(double2 a, double2 b) {
	for (size_t i = 0; i < 2; i++) a.c[i] /= b.c[i];
	return a;
}

double2 d2_div_d(double2 a, double b) {
	for (size_t i = 0; i < 2; i++) a.c[i] /= b;
	return a;
}


int2 i2_add(int2 a, int2 b) {
	for (size_t i = 0; i < 2; i++) a.c[i] += b.c[i];
	return a;
}

int2 i2_add_i(int2 a, int b) {
	for (size_t i = 0; i < 2; i++) a.c[i] += b;
	return a;
}

int2 i2_sub(int2 a, int2 b) {
	for (size_t i = 0; i < 2; i++) a.c[i] -= b.c[i];
	return a;
}

int2 i2_sub_i(int2 a, int b) {
	for (size_t i = 0; i < 2; i++) a.c[i] -= b;
	return a;
}

int2 i2_mul(int2 a, int2 b) {
	for (size_t i = 0; i < 2; i++) a.c[i] *= b.c[i];
	return a;
}

int2 i2_mul_i(int2 a, int b) {
	for (size_t i = 0; i < 2; i++) a.c[i] *= b;
	return a;
}

int2 i2_div(int2 a, int2 b) {
	for (size_t i = 0; i < 2; i++) a.c[i] /= b.c[i];
	return a;
}

int2 i2_div_i(int2 a, int b) {
	for (size_t i = 0; i < 2; i++) a.c[i] /= b;
	return a;
}


uint2 u2_add(uint2 a, uint2 b) {
	for (size_t i = 0; i < 2; i++) a.c[i] += b.c[i];
	return a;
}

uint2 u2_add_u(uint2 a, uint b) {
	for (size_t i = 0; i < 2; i++) a.c[i] += b;
	return a;
}

uint2 u2_sub(uint2 a, uint2 b) {
	for (size_t i = 0; i < 2; i++) a.c[i] -= b.c[i];
	return a;
}

uint2 u2_sub_u(uint2 a, uint b) {
	for (size_t i = 0; i < 2; i++) a.c[i] -= b;
	return a;
}

uint2 u2_mul(uint2 a, uint2 b) {
	for (size_t i = 0; i < 2; i++) a.c[i] *= b.c[i];
	return a;
}

uint2 u2_mul_u(uint2 a, uint b) {
	for (size_t i = 0; i < 2; i++) a.c[i] *= b;
	return a;
}

uint2 u2_div(uint2 a, uint2 b) {
	for (size_t i = 0; i < 2; i++) a.c[i] /= b.c[i];
	return a;
}

uint2 u2_div_u(uint2 a, uint b) {
	for (size_t i = 0; i < 2; i++) a.c[i] /= b;
	return a;
}


float3 f3_add(float3 a, float3 b) {
	for (size_t i = 0; i < 3; i++) a.c[i] += b.c[i];
	return a;
}

float3 f3_add_f(float3 a, float b) {
	for (size_t i = 0; i < 3; i++) a.c[i] += b;
	return a;
}

float3 f3_sub(float3 a, float3 b) {
	for (size_t i = 0; i < 3; i++) a.c[i] -= b.c[i];
	return a;
}

float3 f3_sub_f(float3 a, float b) {
	for (size_t i = 0; i < 3; i++) a.c[i] -= b;
	return a;
}

float3 f3_mul(float3 a, float3 b) {
	for (size_t i = 0; i < 3; i++) a.c[i] *= b.c[i];
	return a;
}

float3 f3_mul_f(float3 a, float b) {
	for (size_t i = 0; i < 3; i++) a.c[i] *= b;
	return a;
}

float3 f3_div(float3 a, float3 b) {
	for (size_t i = 0; i < 3; i++) a.c[i] /= b.c[i];
	return a;
}

float3 f3_div_f(float3 a, float b) {
	for (size_t i = 0; i < 3; i++) a.c[i] /= b;
	return a;
}


double3 d3_add(double3 a, double3 b) {
	for (size_t i = 0; i < 3; i++) a.c[i] += b.c[i];
	return a;
}

double3 d3_add_d(double3 a, double b) {
	for (size_t i = 0; i < 3; i++) a.c[i] += b;
	return a;
}

double3 d3_sub(double3 a, double3 b) {
	for (size_t i = 0; i < 3; i++) a.c[i] -= b.c[i];
	return a;
}

double3 d3_sub_d(double3 a, double b) {
	for (size_t i = 0; i < 3; i++) a.c[i] -= b;
	return a;
}

double3 d3_mul(double3 a, double3 b) {
	for (size_t i = 0; i < 3; i++) a.c[i] *= b.c[i];
	return a;
}

double3 d3_mul_d(double3 a, double b) {
	for (size_t i = 0; i < 3; i++) a.c[i] *= b;
	return a;
}

double3 d3_div(double3 a, double3 b) {
	for (size_t i = 0; i < 3; i++) a.c[i] /= b.c[i];
	return a;
}

double3 d3_div_d(double3 a, double b) {
	for (size_t i = 0; i < 3; i++) a.c[i] /= b;
	return a;
}


int3 i3_add(int3 a, int3 b) {
	for (size_t i = 0; i < 3; i++) a.c[i] += b.c[i];
	return a;
}

int3 i3_add_i(int3 a, int b) {
	for (size_t i = 0; i < 3; i++) a.c[i] += b;
	return a;
}

int3 i3_sub(int3 a, int3 b) {
	for (size_t i = 0; i < 3; i++) a.c[i] -= b.c[i];
	return a;
}

int3 i3_sub_i(int3 a, int b) {
	for (size_t i = 0; i < 3; i++) a.c[i] -= b;
	return a;
}

int3 i3_mul(int3 a, int3 b) {
	for (size_t i = 0; i < 3; i++) a.c[i] *= b.c[i];
	return a;
}

int3 i3_mul_i(int3 a, int b) {
	for (size_t i = 0; i < 3; i++) a.c[i] *= b;
	return a;
}

int3 i3_div(int3 a, int3 b) {
	for (size_t i = 0; i < 3; i++) a.c[i] /= b.c[i];
	return a;
}

int3 i3_div_i(int3 a, int b) {
	for (size_t i = 0; i < 3; i++) a.c[i] /= b;
	return a;
}


uint3 u3_add(uint3 a, uint3 b) {
	for (size_t i = 0; i < 3; i++) a.c[i] += b.c[i];
	return a;
}

uint3 u3_add_u(uint3 a, uint b) {
	for (size_t i = 0; i < 3; i++) a.c[i] += b;
	return a;
}

uint3 u3_sub(uint3 a, uint3 b) {
	for (size_t i = 0; i < 3; i++) a.c[i] -= b.c[i];
	return a;
}

uint3 u3_sub_u(uint3 a, uint b) {
	for (size_t i = 0; i < 3; i++) a.c[i] -= b;
	return a;
}

uint3 u3_mul(uint3 a, uint3 b) {
	for (size_t i = 0; i < 3; i++) a.c[i] *= b.c[i];
	return a;
}

uint3 u3_mul_u(uint3 a, uint b) {
	for (size_t i = 0; i < 3; i++) a.c[i] *= b;
	return a;
}

uint3 u3_div(uint3 a, uint3 b) {
	for (size_t i = 0; i < 3; i++) a.c[i] /= b.c[i];
	return a;
}

uint3 u3_div_u(uint3 a, uint b) {
	for (size_t i = 0; i < 3; i++) a.c[i] /= b;
	return a;
}


float4 f4_add(float4 a, float4 b) {
	for (size_t i = 0; i < 4; i++) a.c[i] += b.c[i];
	return a;
}

float4 f4_add_f(float4 a, float b) {
	for (size_t i = 0; i < 4; i++) a.c[i] += b;
	return a;
}

float4 f4_sub(float4 a, float4 b) {
	for (size_t i = 0; i < 4; i++) a.c[i] -= b.c[i];
	return a;
}

float4 f4_sub_f(float4 a, float b) {
	for (size_t i = 0; i < 4; i++) a.c[i] -= b;
	return a;
}

float4 f4_mul(float4 a, float4 b) {
	for (size_t i = 0; i < 4; i++) a.c[i] *= b.c[i];
	return a;
}

float4 f4_mul_f(float4 a, float b) {
	for (size_t i = 0; i < 4; i++) a.c[i] *= b;
	return a;
}

float4 f4_div(float4 a, float4 b) {
	for (size_t i = 0; i < 4; i++) a.c[i] /= b.c[i];
	return a;
}

float4 f4_div_f(float4 a, float b) {
	for (size_t i = 0; i < 4; i++) a.c[i] /= b;
	return a;
}


double4 d4_add(double4 a, double4 b) {
	for (size_t i = 0; i < 4; i++) a.c[i] += b.c[i];
	return a;
}

double4 d4_add_d(double4 a, double b) {
	for (size_t i = 0; i < 4; i++) a.c[i] += b;
	return a;
}

double4 d4_sub(double4 a, double4 b) {
	for (size_t i = 0; i < 4; i++) a.c[i] -= b.c[i];
	return a;
}

double4 d4_sub_d(double4 a, double b) {
	for (size_t i = 0; i < 4; i++) a.c[i] -= b;
	return a;
}

double4 d4_mul(double4 a, double4 b) {
	for (size_t i = 0; i < 4; i++) a.c[i] *= b.c[i];
	return a;
}

double4 d4_mul_d(double4 a, double b) {
	for (size_t i = 0; i < 4; i++) a.c[i] *= b;
	return a;
}

double4 d4_div(double4 a, double4 b) {
	for (size_t i = 0; i < 4; i++) a.c[i] /= b.c[i];
	return a;
}

double4 d4_div_d(double4 a, double b) {
	for (size_t i = 0; i < 4; i++) a.c[i] /= b;
	return a;
}


int4 i4_add(int4 a, int4 b) {
	for (size_t i = 0; i < 4; i++) a.c[i] += b.c[i];
	return a;
}

int4 i4_add_i(int4 a, int b) {
	for (size_t i = 0; i < 4; i++) a.c[i] += b;
	return a;
}

int4 i4_sub(int4 a, int4 b) {
	for (size_t i = 0; i < 4; i++) a.c[i] -= b.c[i];
	return a;
}

int4 i4_sub_i(int4 a, int b) {
	for (size_t i = 0; i < 4; i++) a.c[i] -= b;
	return a;
}

int4 i4_mul(int4 a, int4 b) {
	for (size_t i = 0; i < 4; i++) a.c[i] *= b.c[i];
	return a;
}

int4 i4_mul_i(int4 a, int b) {
	for (size_t i = 0; i < 4; i++) a.c[i] *= b;
	return a;
}

int4 i4_div(int4 a, int4 b) {
	for (size_t i = 0; i < 4; i++) a.c[i] /= b.c[i];
	return a;
}

int4 i4_div_i(int4 a, int b) {
	for (size_t i = 0; i < 4; i++) a.c[i] /= b;
	return a;
}


uint4 u4_add(uint4 a, uint4 b) {
	for (size_t i = 0; i < 4; i++) a.c[i] += b.c[i];
	return a;
}

uint4 u4_add_u(uint4 a, uint b) {
	for (size_t i = 0; i < 4; i++) a.c[i] += b;
	return a;
}

uint4 u4_sub(uint4 a, uint4 b) {
	for (size_t i = 0; i < 4; i++) a.c[i] -= b.c[i];
	return a;
}

uint4 u4_sub_u(uint4 a, uint b) {
	for (size_t i = 0; i < 4; i++) a.c[i] -= b;
	return a;
}

uint4 u4_mul(uint4 a, uint4 b) {
	for (size_t i = 0; i < 4; i++) a.c[i] *= b.c[i];
	return a;
}

uint4 u4_mul_u(uint4 a, uint b) {
	for (size_t i = 0; i < 4; i++) a.c[i] *= b;
	return a;
}

uint4 u4_div(uint4 a, uint4 b) {
	for (size_t i = 0; i < 4; i++) a.c[i] /= b.c[i];
	return a;
}

uint4 u4_div_u(uint4 a, uint b) {
	for (size_t i = 0; i < 4; i++) a.c[i] /= b;
	return a;
}

#endif // ifdef LLAL_IMPLEMENTATION
#endif // ifndef LLAL_H