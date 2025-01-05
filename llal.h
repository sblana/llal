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


typedef union {
	float c[4];
	float2 v[2];
	struct { float2 x, y; };
	struct {
		float xx, xy;
		float yx, yy;
	};
	struct { float2 r, g; };
	struct {
		float rr, rg;
		float gr, gg;
	};
	struct { float2 s, t; };
	struct {
		float ss, st;
		float ts, tt;
	};
} float2x2;

typedef union {
	double c[4];
	double2 v[2];
	struct { double2 x, y; };
	struct {
		double xx, xy;
		double yx, yy;
	};
	struct { double2 r, g; };
	struct {
		double rr, rg;
		double gr, gg;
	};
	struct { double2 s, t; };
	struct {
		double ss, st;
		double ts, tt;
	};
} double2x2;

typedef union {
	int c[4];
	int2 v[2];
	struct { int2 x, y; };
	struct {
		int xx, xy;
		int yx, yy;
	};
	struct { int2 r, g; };
	struct {
		int rr, rg;
		int gr, gg;
	};
	struct { int2 s, t; };
	struct {
		int ss, st;
		int ts, tt;
	};
} int2x2;

typedef union {
	uint c[4];
	uint2 v[2];
	struct { uint2 x, y; };
	struct {
		uint xx, xy;
		uint yx, yy;
	};
	struct { uint2 r, g; };
	struct {
		uint rr, rg;
		uint gr, gg;
	};
	struct { uint2 s, t; };
	struct {
		uint ss, st;
		uint ts, tt;
	};
} uint2x2;


typedef union {
	float c[9];
	float3 v[3];
	struct { float3 x, y, z; };
	struct {
		float xx, xy, xz;
		float yx, yy, yz;
		float zx, zy, zz;
	};
	struct { float3 r, g, b; };
	struct {
		float rr, rg, rb;
		float gr, gg, gb;
		float br, bg, bb;
	};
	struct { float3 s, t, p; };
	struct {
		float ss, st, sp;
		float ts, tt, tp;
		float ps, pt, pp;
	};
} float3x3;

typedef union {
	double c[9];
	double3 v[3];
	struct { double3 x, y, z; };
	struct {
		double xx, xy, xz;
		double yx, yy, yz;
		double zx, zy, zz;
	};
	struct { double3 r, g, b; };
	struct {
		double rr, rg, rb;
		double gr, gg, gb;
		double br, bg, bb;
	};
	struct { double3 s, t, p; };
	struct {
		double ss, st, sp;
		double ts, tt, tp;
		double ps, pt, pp;
	};
} double3x3;

typedef union {
	int c[9];
	int3 v[3];
	struct { int3 x, y, z; };
	struct {
		int xx, xy, xz;
		int yx, yy, yz;
		int zx, zy, zz;
	};
	struct { int3 r, g, b; };
	struct {
		int rr, rg, rb;
		int gr, gg, gb;
		int br, bg, bb;
	};
	struct { int3 s, t, p; };
	struct {
		int ss, st, sp;
		int ts, tt, tp;
		int ps, pt, pp;
	};
} int3x3;

typedef union {
	uint c[9];
	uint3 v[3];
	struct { uint3 x, y, z; };
	struct {
		uint xx, xy, xz;
		uint yx, yy, yz;
		uint zx, zy, zz;
	};
	struct { uint3 r, g, b; };
	struct {
		uint rr, rg, rb;
		uint gr, gg, gb;
		uint br, bg, bb;
	};
	struct { uint3 s, t, p; };
	struct {
		uint ss, st, sp;
		uint ts, tt, tp;
		uint ps, pt, pp;
	};
} uint3x3;


typedef union {
	float c[16];
	float4 v[4];
	struct { float4 x, y, z, w; };
	struct {
		float xx, xy, xz, xw;
		float yx, yy, yz, yw;
		float zx, zy, zz, zw;
		float wx, wy, wz, ww;
	};
	struct { float4 r, g, b, a; };
	struct {
		float rr, rg, rb, ra;
		float gr, gg, gb, ga;
		float br, bg, bb, ba;
		float ar, ag, ab, aa;
	};
	struct { float4 s, t, p, q; };
	struct {
		float ss, st, sp, sq;
		float ts, tt, tp, tq;
		float ps, pt, pp, pq;
		float qs, qt, qp, qq;
	};
} float4x4;

typedef union {
	double c[16];
	double4 v[4];
	struct { double4 x, y, z, w; };
	struct {
		double xx, xy, xz, xw;
		double yx, yy, yz, yw;
		double zx, zy, zz, zw;
		double wx, wy, wz, ww;
	};
	struct { double4 r, g, b, a; };
	struct {
		double rr, rg, rb, ra;
		double gr, gg, gb, ga;
		double br, bg, bb, ba;
		double ar, ag, ab, aa;
	};
	struct { double4 s, t, p, q; };
	struct {
		double ss, st, sp, sq;
		double ts, tt, tp, tq;
		double ps, pt, pp, pq;
		double qs, qt, qp, qq;
	};
} double4x4;

typedef union {
	int c[16];
	int4 v[4];
	struct { int4 x, y, z, w; };
	struct {
		int xx, xy, xz, xw;
		int yx, yy, yz, yw;
		int zx, zy, zz, zw;
		int wx, wy, wz, ww;
	};
	struct { int4 r, g, b, a; };
	struct {
		int rr, rg, rb, ra;
		int gr, gg, gb, ga;
		int br, bg, bb, ba;
		int ar, ag, ab, aa;
	};
	struct { int4 s, t, p, q; };
	struct {
		int ss, st, sp, sq;
		int ts, tt, tp, tq;
		int ps, pt, pp, pq;
		int qs, qt, qp, qq;
	};
} int4x4;

typedef union {
	uint c[16];
	uint4 v[4];
	struct { uint4 x, y, z, w; };
	struct {
		uint xx, xy, xz, xw;
		uint yx, yy, yz, yw;
		uint zx, zy, zz, zw;
		uint wx, wy, wz, ww;
	};
	struct { uint4 r, g, b, a; };
	struct {
		uint rr, rg, rb, ra;
		uint gr, gg, gb, ga;
		uint br, bg, bb, ba;
		uint ar, ag, ab, aa;
	};
	struct { uint4 s, t, p, q; };
	struct {
		uint ss, st, sp, sq;
		uint ts, tt, tp, tq;
		uint ps, pt, pp, pq;
		uint qs, qt, qp, qq;
	};
} uint4x4;


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