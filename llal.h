#ifndef LLAL_H
#define LLAL_H

#include <stdlib.h>
#include <math.h>



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
	unsigned c[2];
	struct { unsigned x, y; };
	struct { unsigned r, g; };
	struct { unsigned s, t; };
} unsigned2;


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
	unsigned c[3];
	struct { unsigned x, y, z; };
	struct { unsigned r, g, b; };
	struct { unsigned s, t, p; };
} unsigned3;


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
	unsigned c[4];
	struct { unsigned x, y, z, w; };
	struct { unsigned r, g, b, a; };
	struct { unsigned s, t, p, q; };
} unsigned4;


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
	unsigned c[4];
	unsigned2 v[2];
	struct { unsigned2 x, y; };
	struct {
		unsigned xx, xy;
		unsigned yx, yy;
	};
	struct { unsigned2 r, g; };
	struct {
		unsigned rr, rg;
		unsigned gr, gg;
	};
	struct { unsigned2 s, t; };
	struct {
		unsigned ss, st;
		unsigned ts, tt;
	};
} unsigned2x2;


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
	unsigned c[9];
	unsigned3 v[3];
	struct { unsigned3 x, y, z; };
	struct {
		unsigned xx, xy, xz;
		unsigned yx, yy, yz;
		unsigned zx, zy, zz;
	};
	struct { unsigned3 r, g, b; };
	struct {
		unsigned rr, rg, rb;
		unsigned gr, gg, gb;
		unsigned br, bg, bb;
	};
	struct { unsigned3 s, t, p; };
	struct {
		unsigned ss, st, sp;
		unsigned ts, tt, tp;
		unsigned ps, pt, pp;
	};
} unsigned3x3;


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
	unsigned c[16];
	unsigned4 v[4];
	struct { unsigned4 x, y, z, w; };
	struct {
		unsigned xx, xy, xz, xw;
		unsigned yx, yy, yz, yw;
		unsigned zx, zy, zz, zw;
		unsigned wx, wy, wz, ww;
	};
	struct { unsigned4 r, g, b, a; };
	struct {
		unsigned rr, rg, rb, ra;
		unsigned gr, gg, gb, ga;
		unsigned br, bg, bb, ba;
		unsigned ar, ag, ab, aa;
	};
	struct { unsigned4 s, t, p, q; };
	struct {
		unsigned ss, st, sp, sq;
		unsigned ts, tt, tp, tq;
		unsigned ps, pt, pp, pq;
		unsigned qs, qt, qp, qq;
	};
} unsigned4x4;


float2 f2_add(float2 a, float2 b);
float2 f2_add_f(float2 a, float b);
float2 f2_sub(float2 a, float2 b);
float2 f2_sub_f(float2 a, float b);
float2 f2_mul(float2 a, float2 b);
float2 f2_mul_f(float2 a, float b);
float2 f2_div(float2 a, float2 b);
float2 f2_div_f(float2 a, float b);
float f2_dot(float2 a, float2 b);
float f2_lensqr(float2 a);
float f2_len(float2 a);

double2 d2_add(double2 a, double2 b);
double2 d2_add_d(double2 a, double b);
double2 d2_sub(double2 a, double2 b);
double2 d2_sub_d(double2 a, double b);
double2 d2_mul(double2 a, double2 b);
double2 d2_mul_d(double2 a, double b);
double2 d2_div(double2 a, double2 b);
double2 d2_div_d(double2 a, double b);
double d2_dot(double2 a, double2 b);
double d2_lensqr(double2 a);
double d2_len(double2 a);

int2 i2_add(int2 a, int2 b);
int2 i2_add_i(int2 a, int b);
int2 i2_sub(int2 a, int2 b);
int2 i2_sub_i(int2 a, int b);
int2 i2_mul(int2 a, int2 b);
int2 i2_mul_i(int2 a, int b);
int2 i2_div(int2 a, int2 b);
int2 i2_div_i(int2 a, int b);
int i2_dot(int2 a, int2 b);
int i2_lensqr(int2 a);

unsigned2 u2_add(unsigned2 a, unsigned2 b);
unsigned2 u2_add_u(unsigned2 a, unsigned b);
unsigned2 u2_sub(unsigned2 a, unsigned2 b);
unsigned2 u2_sub_u(unsigned2 a, unsigned b);
unsigned2 u2_mul(unsigned2 a, unsigned2 b);
unsigned2 u2_mul_u(unsigned2 a, unsigned b);
unsigned2 u2_div(unsigned2 a, unsigned2 b);
unsigned2 u2_div_u(unsigned2 a, unsigned b);
unsigned u2_dot(unsigned2 a, unsigned2 b);
unsigned u2_lensqr(unsigned2 a);

float3 f3_add(float3 a, float3 b);
float3 f3_add_f(float3 a, float b);
float3 f3_sub(float3 a, float3 b);
float3 f3_sub_f(float3 a, float b);
float3 f3_mul(float3 a, float3 b);
float3 f3_mul_f(float3 a, float b);
float3 f3_div(float3 a, float3 b);
float3 f3_div_f(float3 a, float b);
float f3_dot(float3 a, float3 b);
float3 f3_cross(float3 a, float3 b);
float f3_lensqr(float3 a);
float f3_len(float3 a);

double3 d3_add(double3 a, double3 b);
double3 d3_add_d(double3 a, double b);
double3 d3_sub(double3 a, double3 b);
double3 d3_sub_d(double3 a, double b);
double3 d3_mul(double3 a, double3 b);
double3 d3_mul_d(double3 a, double b);
double3 d3_div(double3 a, double3 b);
double3 d3_div_d(double3 a, double b);
double d3_dot(double3 a, double3 b);
double3 d3_cross(double3 a, double3 b);
double d3_lensqr(double3 a);
double d3_len(double3 a);

int3 i3_add(int3 a, int3 b);
int3 i3_add_i(int3 a, int b);
int3 i3_sub(int3 a, int3 b);
int3 i3_sub_i(int3 a, int b);
int3 i3_mul(int3 a, int3 b);
int3 i3_mul_i(int3 a, int b);
int3 i3_div(int3 a, int3 b);
int3 i3_div_i(int3 a, int b);
int i3_dot(int3 a, int3 b);
int3 i3_cross(int3 a, int3 b);
int i3_lensqr(int3 a);

unsigned3 u3_add(unsigned3 a, unsigned3 b);
unsigned3 u3_add_u(unsigned3 a, unsigned b);
unsigned3 u3_sub(unsigned3 a, unsigned3 b);
unsigned3 u3_sub_u(unsigned3 a, unsigned b);
unsigned3 u3_mul(unsigned3 a, unsigned3 b);
unsigned3 u3_mul_u(unsigned3 a, unsigned b);
unsigned3 u3_div(unsigned3 a, unsigned3 b);
unsigned3 u3_div_u(unsigned3 a, unsigned b);
unsigned u3_dot(unsigned3 a, unsigned3 b);
unsigned u3_lensqr(unsigned3 a);

float4 f4_add(float4 a, float4 b);
float4 f4_add_f(float4 a, float b);
float4 f4_sub(float4 a, float4 b);
float4 f4_sub_f(float4 a, float b);
float4 f4_mul(float4 a, float4 b);
float4 f4_mul_f(float4 a, float b);
float4 f4_div(float4 a, float4 b);
float4 f4_div_f(float4 a, float b);
float f4_dot(float4 a, float4 b);
float f4_lensqr(float4 a);
float f4_len(float4 a);

double4 d4_add(double4 a, double4 b);
double4 d4_add_d(double4 a, double b);
double4 d4_sub(double4 a, double4 b);
double4 d4_sub_d(double4 a, double b);
double4 d4_mul(double4 a, double4 b);
double4 d4_mul_d(double4 a, double b);
double4 d4_div(double4 a, double4 b);
double4 d4_div_d(double4 a, double b);
double d4_dot(double4 a, double4 b);
double d4_lensqr(double4 a);
double d4_len(double4 a);

int4 i4_add(int4 a, int4 b);
int4 i4_add_i(int4 a, int b);
int4 i4_sub(int4 a, int4 b);
int4 i4_sub_i(int4 a, int b);
int4 i4_mul(int4 a, int4 b);
int4 i4_mul_i(int4 a, int b);
int4 i4_div(int4 a, int4 b);
int4 i4_div_i(int4 a, int b);
int i4_dot(int4 a, int4 b);
int i4_lensqr(int4 a);

unsigned4 u4_add(unsigned4 a, unsigned4 b);
unsigned4 u4_add_u(unsigned4 a, unsigned b);
unsigned4 u4_sub(unsigned4 a, unsigned4 b);
unsigned4 u4_sub_u(unsigned4 a, unsigned b);
unsigned4 u4_mul(unsigned4 a, unsigned4 b);
unsigned4 u4_mul_u(unsigned4 a, unsigned b);
unsigned4 u4_div(unsigned4 a, unsigned4 b);
unsigned4 u4_div_u(unsigned4 a, unsigned b);
unsigned u4_dot(unsigned4 a, unsigned4 b);
unsigned u4_lensqr(unsigned4 a);

float2x2 f2x2_transpose(float2x2 a);

double2x2 d2x2_transpose(double2x2 a);

int2x2 i2x2_transpose(int2x2 a);

unsigned2x2 u2x2_transpose(unsigned2x2 a);

float3x3 f3x3_transpose(float3x3 a);

double3x3 d3x3_transpose(double3x3 a);

int3x3 i3x3_transpose(int3x3 a);

unsigned3x3 u3x3_transpose(unsigned3x3 a);

float4x4 f4x4_transpose(float4x4 a);

double4x4 d4x4_transpose(double4x4 a);

int4x4 i4x4_transpose(int4x4 a);

unsigned4x4 u4x4_transpose(unsigned4x4 a);


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

float f2_dot(float2 a, float2 b) {
	return a.x*b.x + a.y*b.y;
}

float f2_lensqr(float2 a) {
	return a.x*a.x + a.y*a.y;
}

float f2_len(float2 a) {
	return sqrtf(f2_lensqr(a));
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

double d2_dot(double2 a, double2 b) {
	return a.x*b.x + a.y*b.y;
}

double d2_lensqr(double2 a) {
	return a.x*a.x + a.y*a.y;
}

double d2_len(double2 a) {
	return sqrt(d2_lensqr(a));
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

int i2_dot(int2 a, int2 b) {
	return a.x*b.x + a.y*b.y;
}

int i2_lensqr(int2 a) {
	return a.x*a.x + a.y*a.y;
}


unsigned2 u2_add(unsigned2 a, unsigned2 b) {
	for (size_t i = 0; i < 2; i++) a.c[i] += b.c[i];
	return a;
}

unsigned2 u2_add_u(unsigned2 a, unsigned b) {
	for (size_t i = 0; i < 2; i++) a.c[i] += b;
	return a;
}

unsigned2 u2_sub(unsigned2 a, unsigned2 b) {
	for (size_t i = 0; i < 2; i++) a.c[i] -= b.c[i];
	return a;
}

unsigned2 u2_sub_u(unsigned2 a, unsigned b) {
	for (size_t i = 0; i < 2; i++) a.c[i] -= b;
	return a;
}

unsigned2 u2_mul(unsigned2 a, unsigned2 b) {
	for (size_t i = 0; i < 2; i++) a.c[i] *= b.c[i];
	return a;
}

unsigned2 u2_mul_u(unsigned2 a, unsigned b) {
	for (size_t i = 0; i < 2; i++) a.c[i] *= b;
	return a;
}

unsigned2 u2_div(unsigned2 a, unsigned2 b) {
	for (size_t i = 0; i < 2; i++) a.c[i] /= b.c[i];
	return a;
}

unsigned2 u2_div_u(unsigned2 a, unsigned b) {
	for (size_t i = 0; i < 2; i++) a.c[i] /= b;
	return a;
}

unsigned u2_dot(unsigned2 a, unsigned2 b) {
	return a.x*b.x + a.y*b.y;
}

unsigned u2_lensqr(unsigned2 a) {
	return a.x*a.x + a.y*a.y;
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

float f3_dot(float3 a, float3 b) {
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

float3 f3_cross(float3 a, float3 b) {
	return (float3){
		.x = a.y*b.z - a.z*b.y,
		.y = a.z*b.x - a.x*b.z,
		.z = a.x*b.y - a.y*b.x,
	};
}

float f3_lensqr(float3 a) {
	return a.x*a.x + a.y*a.y + a.z*a.z;
}

float f3_len(float3 a) {
	return sqrtf(f3_lensqr(a));
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

double d3_dot(double3 a, double3 b) {
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

double3 d3_cross(double3 a, double3 b) {
	return (double3){
		.x = a.y*b.z - a.z*b.y,
		.y = a.z*b.x - a.x*b.z,
		.z = a.x*b.y - a.y*b.x,
	};
}

double d3_lensqr(double3 a) {
	return a.x*a.x + a.y*a.y + a.z*a.z;
}

double d3_len(double3 a) {
	return sqrt(d3_lensqr(a));
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

int i3_dot(int3 a, int3 b) {
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

int3 i3_cross(int3 a, int3 b) {
	return (int3){
		.x = a.y*b.z - a.z*b.y,
		.y = a.z*b.x - a.x*b.z,
		.z = a.x*b.y - a.y*b.x,
	};
}

int i3_lensqr(int3 a) {
	return a.x*a.x + a.y*a.y + a.z*a.z;
}


unsigned3 u3_add(unsigned3 a, unsigned3 b) {
	for (size_t i = 0; i < 3; i++) a.c[i] += b.c[i];
	return a;
}

unsigned3 u3_add_u(unsigned3 a, unsigned b) {
	for (size_t i = 0; i < 3; i++) a.c[i] += b;
	return a;
}

unsigned3 u3_sub(unsigned3 a, unsigned3 b) {
	for (size_t i = 0; i < 3; i++) a.c[i] -= b.c[i];
	return a;
}

unsigned3 u3_sub_u(unsigned3 a, unsigned b) {
	for (size_t i = 0; i < 3; i++) a.c[i] -= b;
	return a;
}

unsigned3 u3_mul(unsigned3 a, unsigned3 b) {
	for (size_t i = 0; i < 3; i++) a.c[i] *= b.c[i];
	return a;
}

unsigned3 u3_mul_u(unsigned3 a, unsigned b) {
	for (size_t i = 0; i < 3; i++) a.c[i] *= b;
	return a;
}

unsigned3 u3_div(unsigned3 a, unsigned3 b) {
	for (size_t i = 0; i < 3; i++) a.c[i] /= b.c[i];
	return a;
}

unsigned3 u3_div_u(unsigned3 a, unsigned b) {
	for (size_t i = 0; i < 3; i++) a.c[i] /= b;
	return a;
}

unsigned u3_dot(unsigned3 a, unsigned3 b) {
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

unsigned u3_lensqr(unsigned3 a) {
	return a.x*a.x + a.y*a.y + a.z*a.z;
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

float f4_dot(float4 a, float4 b) {
	return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

float f4_lensqr(float4 a) {
	return a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w;
}

float f4_len(float4 a) {
	return sqrtf(f4_lensqr(a));
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

double d4_dot(double4 a, double4 b) {
	return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

double d4_lensqr(double4 a) {
	return a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w;
}

double d4_len(double4 a) {
	return sqrt(d4_lensqr(a));
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

int i4_dot(int4 a, int4 b) {
	return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

int i4_lensqr(int4 a) {
	return a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w;
}


unsigned4 u4_add(unsigned4 a, unsigned4 b) {
	for (size_t i = 0; i < 4; i++) a.c[i] += b.c[i];
	return a;
}

unsigned4 u4_add_u(unsigned4 a, unsigned b) {
	for (size_t i = 0; i < 4; i++) a.c[i] += b;
	return a;
}

unsigned4 u4_sub(unsigned4 a, unsigned4 b) {
	for (size_t i = 0; i < 4; i++) a.c[i] -= b.c[i];
	return a;
}

unsigned4 u4_sub_u(unsigned4 a, unsigned b) {
	for (size_t i = 0; i < 4; i++) a.c[i] -= b;
	return a;
}

unsigned4 u4_mul(unsigned4 a, unsigned4 b) {
	for (size_t i = 0; i < 4; i++) a.c[i] *= b.c[i];
	return a;
}

unsigned4 u4_mul_u(unsigned4 a, unsigned b) {
	for (size_t i = 0; i < 4; i++) a.c[i] *= b;
	return a;
}

unsigned4 u4_div(unsigned4 a, unsigned4 b) {
	for (size_t i = 0; i < 4; i++) a.c[i] /= b.c[i];
	return a;
}

unsigned4 u4_div_u(unsigned4 a, unsigned b) {
	for (size_t i = 0; i < 4; i++) a.c[i] /= b;
	return a;
}

unsigned u4_dot(unsigned4 a, unsigned4 b) {
	return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

unsigned u4_lensqr(unsigned4 a) {
	return a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w;
}


float2x2 f2x2_transpose(float2x2 a) {
	return (float2x2){
		.x = {{ a.xx, a.yx, }},
		.y = {{ a.xy, a.yy, }},
	};
}


double2x2 d2x2_transpose(double2x2 a) {
	return (double2x2){
		.x = {{ a.xx, a.yx, }},
		.y = {{ a.xy, a.yy, }},
	};
}


int2x2 i2x2_transpose(int2x2 a) {
	return (int2x2){
		.x = {{ a.xx, a.yx, }},
		.y = {{ a.xy, a.yy, }},
	};
}


unsigned2x2 u2x2_transpose(unsigned2x2 a) {
	return (unsigned2x2){
		.x = {{ a.xx, a.yx, }},
		.y = {{ a.xy, a.yy, }},
	};
}


float3x3 f3x3_transpose(float3x3 a) {
	return (float3x3){
		.x = {{ a.xx, a.yx, a.zx, }},
		.y = {{ a.xy, a.yy, a.zy, }},
		.z = {{ a.xz, a.yz, a.zz, }},
	};
}


double3x3 d3x3_transpose(double3x3 a) {
	return (double3x3){
		.x = {{ a.xx, a.yx, a.zx, }},
		.y = {{ a.xy, a.yy, a.zy, }},
		.z = {{ a.xz, a.yz, a.zz, }},
	};
}


int3x3 i3x3_transpose(int3x3 a) {
	return (int3x3){
		.x = {{ a.xx, a.yx, a.zx, }},
		.y = {{ a.xy, a.yy, a.zy, }},
		.z = {{ a.xz, a.yz, a.zz, }},
	};
}


unsigned3x3 u3x3_transpose(unsigned3x3 a) {
	return (unsigned3x3){
		.x = {{ a.xx, a.yx, a.zx, }},
		.y = {{ a.xy, a.yy, a.zy, }},
		.z = {{ a.xz, a.yz, a.zz, }},
	};
}


float4x4 f4x4_transpose(float4x4 a) {
	return (float4x4){
		.x = {{ a.xx, a.yx, a.zx, a.wx, }},
		.y = {{ a.xy, a.yy, a.zy, a.wy, }},
		.z = {{ a.xz, a.yz, a.zz, a.wz, }},
		.w = {{ a.xw, a.yw, a.zw, a.ww, }},
	};
}


double4x4 d4x4_transpose(double4x4 a) {
	return (double4x4){
		.x = {{ a.xx, a.yx, a.zx, a.wx, }},
		.y = {{ a.xy, a.yy, a.zy, a.wy, }},
		.z = {{ a.xz, a.yz, a.zz, a.wz, }},
		.w = {{ a.xw, a.yw, a.zw, a.ww, }},
	};
}


int4x4 i4x4_transpose(int4x4 a) {
	return (int4x4){
		.x = {{ a.xx, a.yx, a.zx, a.wx, }},
		.y = {{ a.xy, a.yy, a.zy, a.wy, }},
		.z = {{ a.xz, a.yz, a.zz, a.wz, }},
		.w = {{ a.xw, a.yw, a.zw, a.ww, }},
	};
}


unsigned4x4 u4x4_transpose(unsigned4x4 a) {
	return (unsigned4x4){
		.x = {{ a.xx, a.yx, a.zx, a.wx, }},
		.y = {{ a.xy, a.yy, a.zy, a.wy, }},
		.z = {{ a.xz, a.yz, a.zz, a.wz, }},
		.w = {{ a.xw, a.yw, a.zw, a.ww, }},
	};
}

#endif // ifdef LLAL_IMPLEMENTATION
#endif // ifndef LLAL_H