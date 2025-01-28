#ifndef LLAL_H
#define LLAL_H

#include <math.h>

#ifdef LLAL_USE_STATIC_INLINE
#define LLAL_INLINE static inline
#if !defined LLAL_IMPLEMENTATION
#define LLAL_IMPLEMENTATION
#endif
#else
#define LLAL_INLINE
#endif

#ifndef MIN
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#endif
#ifndef MAX
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#endif


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


#ifndef LLAL_USE_STATIC_INLINE

LLAL_INLINE float2 f2_ctor_f(float x);
LLAL_INLINE float2 f2_ctor_f2(float2 xy);
LLAL_INLINE float2 f2_ctor_ff(float x, float y);
LLAL_INLINE float2 f2_add(float2 a, float2 b);
LLAL_INLINE float2 f2_add_f(float2 a, float b);
LLAL_INLINE float2 f2_sub(float2 a, float2 b);
LLAL_INLINE float2 f2_sub_f(float2 a, float b);
LLAL_INLINE float2 f2_mul(float2 a, float2 b);
LLAL_INLINE float2 f2_mul_f(float2 a, float b);
LLAL_INLINE float2 f2_div(float2 a, float2 b);
LLAL_INLINE float2 f2_div_f(float2 a, float b);
LLAL_INLINE float f2_clesce_sum(float2 a);
LLAL_INLINE float f2_clesce_product(float2 a);
LLAL_INLINE float f2_clesce_min(float2 a);
LLAL_INLINE float f2_clesce_max(float2 a);
LLAL_INLINE float f2_dot(float2 a, float2 b);
LLAL_INLINE float f2_lensqr(float2 a);
LLAL_INLINE float f2_len(float2 a);
LLAL_INLINE float2 f2_normalize(float2 a);

LLAL_INLINE double2 d2_ctor_d(double x);
LLAL_INLINE double2 d2_ctor_d2(double2 xy);
LLAL_INLINE double2 d2_ctor_dd(double x, double y);
LLAL_INLINE double2 d2_add(double2 a, double2 b);
LLAL_INLINE double2 d2_add_d(double2 a, double b);
LLAL_INLINE double2 d2_sub(double2 a, double2 b);
LLAL_INLINE double2 d2_sub_d(double2 a, double b);
LLAL_INLINE double2 d2_mul(double2 a, double2 b);
LLAL_INLINE double2 d2_mul_d(double2 a, double b);
LLAL_INLINE double2 d2_div(double2 a, double2 b);
LLAL_INLINE double2 d2_div_d(double2 a, double b);
LLAL_INLINE double d2_clesce_sum(double2 a);
LLAL_INLINE double d2_clesce_product(double2 a);
LLAL_INLINE double d2_clesce_min(double2 a);
LLAL_INLINE double d2_clesce_max(double2 a);
LLAL_INLINE double d2_dot(double2 a, double2 b);
LLAL_INLINE double d2_lensqr(double2 a);
LLAL_INLINE double d2_len(double2 a);
LLAL_INLINE double2 d2_normalize(double2 a);

LLAL_INLINE int2 i2_ctor_i(int x);
LLAL_INLINE int2 i2_ctor_i2(int2 xy);
LLAL_INLINE int2 i2_ctor_ii(int x, int y);
LLAL_INLINE int2 i2_add(int2 a, int2 b);
LLAL_INLINE int2 i2_add_i(int2 a, int b);
LLAL_INLINE int2 i2_sub(int2 a, int2 b);
LLAL_INLINE int2 i2_sub_i(int2 a, int b);
LLAL_INLINE int2 i2_mul(int2 a, int2 b);
LLAL_INLINE int2 i2_mul_i(int2 a, int b);
LLAL_INLINE int2 i2_div(int2 a, int2 b);
LLAL_INLINE int2 i2_div_i(int2 a, int b);
LLAL_INLINE int i2_clesce_sum(int2 a);
LLAL_INLINE int i2_clesce_product(int2 a);
LLAL_INLINE int i2_clesce_min(int2 a);
LLAL_INLINE int i2_clesce_max(int2 a);
LLAL_INLINE int i2_dot(int2 a, int2 b);
LLAL_INLINE int i2_lensqr(int2 a);

LLAL_INLINE unsigned2 u2_ctor_u(unsigned x);
LLAL_INLINE unsigned2 u2_ctor_u2(unsigned2 xy);
LLAL_INLINE unsigned2 u2_ctor_uu(unsigned x, unsigned y);
LLAL_INLINE unsigned2 u2_add(unsigned2 a, unsigned2 b);
LLAL_INLINE unsigned2 u2_add_u(unsigned2 a, unsigned b);
LLAL_INLINE unsigned2 u2_sub(unsigned2 a, unsigned2 b);
LLAL_INLINE unsigned2 u2_sub_u(unsigned2 a, unsigned b);
LLAL_INLINE unsigned2 u2_mul(unsigned2 a, unsigned2 b);
LLAL_INLINE unsigned2 u2_mul_u(unsigned2 a, unsigned b);
LLAL_INLINE unsigned2 u2_div(unsigned2 a, unsigned2 b);
LLAL_INLINE unsigned2 u2_div_u(unsigned2 a, unsigned b);
LLAL_INLINE unsigned u2_clesce_sum(unsigned2 a);
LLAL_INLINE unsigned u2_clesce_product(unsigned2 a);
LLAL_INLINE unsigned u2_clesce_min(unsigned2 a);
LLAL_INLINE unsigned u2_clesce_max(unsigned2 a);
LLAL_INLINE unsigned u2_dot(unsigned2 a, unsigned2 b);
LLAL_INLINE unsigned u2_lensqr(unsigned2 a);

LLAL_INLINE float3 f3_ctor_f(float x);
LLAL_INLINE float3 f3_ctor_f3(float3 xyz);
LLAL_INLINE float3 f3_ctor_f2f(float2 xy, float z);
LLAL_INLINE float3 f3_ctor_ff2(float x, float2 yz);
LLAL_INLINE float3 f3_ctor_fff(float x, float y, float z);
LLAL_INLINE float3 f3_add(float3 a, float3 b);
LLAL_INLINE float3 f3_add_f(float3 a, float b);
LLAL_INLINE float3 f3_sub(float3 a, float3 b);
LLAL_INLINE float3 f3_sub_f(float3 a, float b);
LLAL_INLINE float3 f3_mul(float3 a, float3 b);
LLAL_INLINE float3 f3_mul_f(float3 a, float b);
LLAL_INLINE float3 f3_div(float3 a, float3 b);
LLAL_INLINE float3 f3_div_f(float3 a, float b);
LLAL_INLINE float f3_clesce_sum(float3 a);
LLAL_INLINE float f3_clesce_product(float3 a);
LLAL_INLINE float f3_clesce_min(float3 a);
LLAL_INLINE float f3_clesce_max(float3 a);
LLAL_INLINE float f3_dot(float3 a, float3 b);
LLAL_INLINE float3 f3_cross(float3 a, float3 b);
LLAL_INLINE float f3_lensqr(float3 a);
LLAL_INLINE float f3_len(float3 a);
LLAL_INLINE float3 f3_normalize(float3 a);

LLAL_INLINE double3 d3_ctor_d(double x);
LLAL_INLINE double3 d3_ctor_d3(double3 xyz);
LLAL_INLINE double3 d3_ctor_d2d(double2 xy, double z);
LLAL_INLINE double3 d3_ctor_dd2(double x, double2 yz);
LLAL_INLINE double3 d3_ctor_ddd(double x, double y, double z);
LLAL_INLINE double3 d3_add(double3 a, double3 b);
LLAL_INLINE double3 d3_add_d(double3 a, double b);
LLAL_INLINE double3 d3_sub(double3 a, double3 b);
LLAL_INLINE double3 d3_sub_d(double3 a, double b);
LLAL_INLINE double3 d3_mul(double3 a, double3 b);
LLAL_INLINE double3 d3_mul_d(double3 a, double b);
LLAL_INLINE double3 d3_div(double3 a, double3 b);
LLAL_INLINE double3 d3_div_d(double3 a, double b);
LLAL_INLINE double d3_clesce_sum(double3 a);
LLAL_INLINE double d3_clesce_product(double3 a);
LLAL_INLINE double d3_clesce_min(double3 a);
LLAL_INLINE double d3_clesce_max(double3 a);
LLAL_INLINE double d3_dot(double3 a, double3 b);
LLAL_INLINE double3 d3_cross(double3 a, double3 b);
LLAL_INLINE double d3_lensqr(double3 a);
LLAL_INLINE double d3_len(double3 a);
LLAL_INLINE double3 d3_normalize(double3 a);

LLAL_INLINE int3 i3_ctor_i(int x);
LLAL_INLINE int3 i3_ctor_i3(int3 xyz);
LLAL_INLINE int3 i3_ctor_i2i(int2 xy, int z);
LLAL_INLINE int3 i3_ctor_ii2(int x, int2 yz);
LLAL_INLINE int3 i3_ctor_iii(int x, int y, int z);
LLAL_INLINE int3 i3_add(int3 a, int3 b);
LLAL_INLINE int3 i3_add_i(int3 a, int b);
LLAL_INLINE int3 i3_sub(int3 a, int3 b);
LLAL_INLINE int3 i3_sub_i(int3 a, int b);
LLAL_INLINE int3 i3_mul(int3 a, int3 b);
LLAL_INLINE int3 i3_mul_i(int3 a, int b);
LLAL_INLINE int3 i3_div(int3 a, int3 b);
LLAL_INLINE int3 i3_div_i(int3 a, int b);
LLAL_INLINE int i3_clesce_sum(int3 a);
LLAL_INLINE int i3_clesce_product(int3 a);
LLAL_INLINE int i3_clesce_min(int3 a);
LLAL_INLINE int i3_clesce_max(int3 a);
LLAL_INLINE int i3_dot(int3 a, int3 b);
LLAL_INLINE int3 i3_cross(int3 a, int3 b);
LLAL_INLINE int i3_lensqr(int3 a);

LLAL_INLINE unsigned3 u3_ctor_u(unsigned x);
LLAL_INLINE unsigned3 u3_ctor_u3(unsigned3 xyz);
LLAL_INLINE unsigned3 u3_ctor_u2u(unsigned2 xy, unsigned z);
LLAL_INLINE unsigned3 u3_ctor_uu2(unsigned x, unsigned2 yz);
LLAL_INLINE unsigned3 u3_ctor_uuu(unsigned x, unsigned y, unsigned z);
LLAL_INLINE unsigned3 u3_add(unsigned3 a, unsigned3 b);
LLAL_INLINE unsigned3 u3_add_u(unsigned3 a, unsigned b);
LLAL_INLINE unsigned3 u3_sub(unsigned3 a, unsigned3 b);
LLAL_INLINE unsigned3 u3_sub_u(unsigned3 a, unsigned b);
LLAL_INLINE unsigned3 u3_mul(unsigned3 a, unsigned3 b);
LLAL_INLINE unsigned3 u3_mul_u(unsigned3 a, unsigned b);
LLAL_INLINE unsigned3 u3_div(unsigned3 a, unsigned3 b);
LLAL_INLINE unsigned3 u3_div_u(unsigned3 a, unsigned b);
LLAL_INLINE unsigned u3_clesce_sum(unsigned3 a);
LLAL_INLINE unsigned u3_clesce_product(unsigned3 a);
LLAL_INLINE unsigned u3_clesce_min(unsigned3 a);
LLAL_INLINE unsigned u3_clesce_max(unsigned3 a);
LLAL_INLINE unsigned u3_dot(unsigned3 a, unsigned3 b);
LLAL_INLINE unsigned u3_lensqr(unsigned3 a);

LLAL_INLINE float4 f4_ctor_f(float x);
LLAL_INLINE float4 f4_ctor_f4(float4 xyzw);
LLAL_INLINE float4 f4_ctor_f3f(float3 xyz, float w);
LLAL_INLINE float4 f4_ctor_f2f2(float2 xy, float2 zw);
LLAL_INLINE float4 f4_ctor_ff3(float x, float3 yzw);
LLAL_INLINE float4 f4_ctor_f2ff(float2 xy, float z, float w);
LLAL_INLINE float4 f4_ctor_ff2f(float x, float2 yz, float w);
LLAL_INLINE float4 f4_ctor_fff2(float x, float y, float2 zw);
LLAL_INLINE float4 f4_ctor_ffff(float x, float y, float z, float w);
LLAL_INLINE float4 f4_add(float4 a, float4 b);
LLAL_INLINE float4 f4_add_f(float4 a, float b);
LLAL_INLINE float4 f4_sub(float4 a, float4 b);
LLAL_INLINE float4 f4_sub_f(float4 a, float b);
LLAL_INLINE float4 f4_mul(float4 a, float4 b);
LLAL_INLINE float4 f4_mul_f(float4 a, float b);
LLAL_INLINE float4 f4_div(float4 a, float4 b);
LLAL_INLINE float4 f4_div_f(float4 a, float b);
LLAL_INLINE float f4_clesce_sum(float4 a);
LLAL_INLINE float f4_clesce_product(float4 a);
LLAL_INLINE float f4_clesce_min(float4 a);
LLAL_INLINE float f4_clesce_max(float4 a);
LLAL_INLINE float f4_dot(float4 a, float4 b);
LLAL_INLINE float f4_lensqr(float4 a);
LLAL_INLINE float f4_len(float4 a);
LLAL_INLINE float4 f4_normalize(float4 a);

LLAL_INLINE double4 d4_ctor_d(double x);
LLAL_INLINE double4 d4_ctor_d4(double4 xyzw);
LLAL_INLINE double4 d4_ctor_d3d(double3 xyz, double w);
LLAL_INLINE double4 d4_ctor_d2d2(double2 xy, double2 zw);
LLAL_INLINE double4 d4_ctor_dd3(double x, double3 yzw);
LLAL_INLINE double4 d4_ctor_d2dd(double2 xy, double z, double w);
LLAL_INLINE double4 d4_ctor_dd2d(double x, double2 yz, double w);
LLAL_INLINE double4 d4_ctor_ddd2(double x, double y, double2 zw);
LLAL_INLINE double4 d4_ctor_dddd(double x, double y, double z, double w);
LLAL_INLINE double4 d4_add(double4 a, double4 b);
LLAL_INLINE double4 d4_add_d(double4 a, double b);
LLAL_INLINE double4 d4_sub(double4 a, double4 b);
LLAL_INLINE double4 d4_sub_d(double4 a, double b);
LLAL_INLINE double4 d4_mul(double4 a, double4 b);
LLAL_INLINE double4 d4_mul_d(double4 a, double b);
LLAL_INLINE double4 d4_div(double4 a, double4 b);
LLAL_INLINE double4 d4_div_d(double4 a, double b);
LLAL_INLINE double d4_clesce_sum(double4 a);
LLAL_INLINE double d4_clesce_product(double4 a);
LLAL_INLINE double d4_clesce_min(double4 a);
LLAL_INLINE double d4_clesce_max(double4 a);
LLAL_INLINE double d4_dot(double4 a, double4 b);
LLAL_INLINE double d4_lensqr(double4 a);
LLAL_INLINE double d4_len(double4 a);
LLAL_INLINE double4 d4_normalize(double4 a);

LLAL_INLINE int4 i4_ctor_i(int x);
LLAL_INLINE int4 i4_ctor_i4(int4 xyzw);
LLAL_INLINE int4 i4_ctor_i3i(int3 xyz, int w);
LLAL_INLINE int4 i4_ctor_i2i2(int2 xy, int2 zw);
LLAL_INLINE int4 i4_ctor_ii3(int x, int3 yzw);
LLAL_INLINE int4 i4_ctor_i2ii(int2 xy, int z, int w);
LLAL_INLINE int4 i4_ctor_ii2i(int x, int2 yz, int w);
LLAL_INLINE int4 i4_ctor_iii2(int x, int y, int2 zw);
LLAL_INLINE int4 i4_ctor_iiii(int x, int y, int z, int w);
LLAL_INLINE int4 i4_add(int4 a, int4 b);
LLAL_INLINE int4 i4_add_i(int4 a, int b);
LLAL_INLINE int4 i4_sub(int4 a, int4 b);
LLAL_INLINE int4 i4_sub_i(int4 a, int b);
LLAL_INLINE int4 i4_mul(int4 a, int4 b);
LLAL_INLINE int4 i4_mul_i(int4 a, int b);
LLAL_INLINE int4 i4_div(int4 a, int4 b);
LLAL_INLINE int4 i4_div_i(int4 a, int b);
LLAL_INLINE int i4_clesce_sum(int4 a);
LLAL_INLINE int i4_clesce_product(int4 a);
LLAL_INLINE int i4_clesce_min(int4 a);
LLAL_INLINE int i4_clesce_max(int4 a);
LLAL_INLINE int i4_dot(int4 a, int4 b);
LLAL_INLINE int i4_lensqr(int4 a);

LLAL_INLINE unsigned4 u4_ctor_u(unsigned x);
LLAL_INLINE unsigned4 u4_ctor_u4(unsigned4 xyzw);
LLAL_INLINE unsigned4 u4_ctor_u3u(unsigned3 xyz, unsigned w);
LLAL_INLINE unsigned4 u4_ctor_u2u2(unsigned2 xy, unsigned2 zw);
LLAL_INLINE unsigned4 u4_ctor_uu3(unsigned x, unsigned3 yzw);
LLAL_INLINE unsigned4 u4_ctor_u2uu(unsigned2 xy, unsigned z, unsigned w);
LLAL_INLINE unsigned4 u4_ctor_uu2u(unsigned x, unsigned2 yz, unsigned w);
LLAL_INLINE unsigned4 u4_ctor_uuu2(unsigned x, unsigned y, unsigned2 zw);
LLAL_INLINE unsigned4 u4_ctor_uuuu(unsigned x, unsigned y, unsigned z, unsigned w);
LLAL_INLINE unsigned4 u4_add(unsigned4 a, unsigned4 b);
LLAL_INLINE unsigned4 u4_add_u(unsigned4 a, unsigned b);
LLAL_INLINE unsigned4 u4_sub(unsigned4 a, unsigned4 b);
LLAL_INLINE unsigned4 u4_sub_u(unsigned4 a, unsigned b);
LLAL_INLINE unsigned4 u4_mul(unsigned4 a, unsigned4 b);
LLAL_INLINE unsigned4 u4_mul_u(unsigned4 a, unsigned b);
LLAL_INLINE unsigned4 u4_div(unsigned4 a, unsigned4 b);
LLAL_INLINE unsigned4 u4_div_u(unsigned4 a, unsigned b);
LLAL_INLINE unsigned u4_clesce_sum(unsigned4 a);
LLAL_INLINE unsigned u4_clesce_product(unsigned4 a);
LLAL_INLINE unsigned u4_clesce_min(unsigned4 a);
LLAL_INLINE unsigned u4_clesce_max(unsigned4 a);
LLAL_INLINE unsigned u4_dot(unsigned4 a, unsigned4 b);
LLAL_INLINE unsigned u4_lensqr(unsigned4 a);

LLAL_INLINE float2x2 f2x2_identity(void);
LLAL_INLINE float2x2 f2x2_add(float2x2 a, float2x2 b);
LLAL_INLINE float2x2 f2x2_add_f(float2x2 a, float b);
LLAL_INLINE float2x2 f2x2_sub(float2x2 a, float2x2 b);
LLAL_INLINE float2x2 f2x2_sub_f(float2x2 a, float b);
LLAL_INLINE float2x2 f2x2_mul(float2x2 a, float2x2 b);
LLAL_INLINE float2x2 f2x2_mul_f(float2x2 a, float b);
LLAL_INLINE float2x2 f2x2_div(float2x2 a, float2x2 b);
LLAL_INLINE float2x2 f2x2_div_f(float2x2 a, float b);
LLAL_INLINE float f2x2_clesce_sum(float2x2 a);
LLAL_INLINE float f2x2_clesce_product(float2x2 a);
LLAL_INLINE float f2x2_clesce_min(float2x2 a);
LLAL_INLINE float f2x2_clesce_max(float2x2 a);
LLAL_INLINE float2x2 f2x2_matmult_f2x2(float2x2 a, float2x2 b);
LLAL_INLINE float2 f2x2_matmult_f2c(float2x2 a, float2 b);
LLAL_INLINE float2 f2r_matmult_f2x2(float2 a, float2x2 b);
LLAL_INLINE float2x2 f2x2_transpose(float2x2 a);
LLAL_INLINE float2x2 f2x2_scale(float2 by);

LLAL_INLINE double2x2 d2x2_identity(void);
LLAL_INLINE double2x2 d2x2_add(double2x2 a, double2x2 b);
LLAL_INLINE double2x2 d2x2_add_d(double2x2 a, double b);
LLAL_INLINE double2x2 d2x2_sub(double2x2 a, double2x2 b);
LLAL_INLINE double2x2 d2x2_sub_d(double2x2 a, double b);
LLAL_INLINE double2x2 d2x2_mul(double2x2 a, double2x2 b);
LLAL_INLINE double2x2 d2x2_mul_d(double2x2 a, double b);
LLAL_INLINE double2x2 d2x2_div(double2x2 a, double2x2 b);
LLAL_INLINE double2x2 d2x2_div_d(double2x2 a, double b);
LLAL_INLINE double d2x2_clesce_sum(double2x2 a);
LLAL_INLINE double d2x2_clesce_product(double2x2 a);
LLAL_INLINE double d2x2_clesce_min(double2x2 a);
LLAL_INLINE double d2x2_clesce_max(double2x2 a);
LLAL_INLINE double2x2 d2x2_matmult_d2x2(double2x2 a, double2x2 b);
LLAL_INLINE double2 d2x2_matmult_d2c(double2x2 a, double2 b);
LLAL_INLINE double2 d2r_matmult_d2x2(double2 a, double2x2 b);
LLAL_INLINE double2x2 d2x2_transpose(double2x2 a);
LLAL_INLINE double2x2 d2x2_scale(double2 by);

LLAL_INLINE int2x2 i2x2_identity(void);
LLAL_INLINE int2x2 i2x2_add(int2x2 a, int2x2 b);
LLAL_INLINE int2x2 i2x2_add_i(int2x2 a, int b);
LLAL_INLINE int2x2 i2x2_sub(int2x2 a, int2x2 b);
LLAL_INLINE int2x2 i2x2_sub_i(int2x2 a, int b);
LLAL_INLINE int2x2 i2x2_mul(int2x2 a, int2x2 b);
LLAL_INLINE int2x2 i2x2_mul_i(int2x2 a, int b);
LLAL_INLINE int2x2 i2x2_div(int2x2 a, int2x2 b);
LLAL_INLINE int2x2 i2x2_div_i(int2x2 a, int b);
LLAL_INLINE int i2x2_clesce_sum(int2x2 a);
LLAL_INLINE int i2x2_clesce_product(int2x2 a);
LLAL_INLINE int i2x2_clesce_min(int2x2 a);
LLAL_INLINE int i2x2_clesce_max(int2x2 a);
LLAL_INLINE int2x2 i2x2_matmult_i2x2(int2x2 a, int2x2 b);
LLAL_INLINE int2 i2x2_matmult_i2c(int2x2 a, int2 b);
LLAL_INLINE int2 i2r_matmult_i2x2(int2 a, int2x2 b);
LLAL_INLINE int2x2 i2x2_transpose(int2x2 a);
LLAL_INLINE int2x2 i2x2_scale(int2 by);

LLAL_INLINE unsigned2x2 u2x2_identity(void);
LLAL_INLINE unsigned2x2 u2x2_add(unsigned2x2 a, unsigned2x2 b);
LLAL_INLINE unsigned2x2 u2x2_add_u(unsigned2x2 a, unsigned b);
LLAL_INLINE unsigned2x2 u2x2_sub(unsigned2x2 a, unsigned2x2 b);
LLAL_INLINE unsigned2x2 u2x2_sub_u(unsigned2x2 a, unsigned b);
LLAL_INLINE unsigned2x2 u2x2_mul(unsigned2x2 a, unsigned2x2 b);
LLAL_INLINE unsigned2x2 u2x2_mul_u(unsigned2x2 a, unsigned b);
LLAL_INLINE unsigned2x2 u2x2_div(unsigned2x2 a, unsigned2x2 b);
LLAL_INLINE unsigned2x2 u2x2_div_u(unsigned2x2 a, unsigned b);
LLAL_INLINE unsigned u2x2_clesce_sum(unsigned2x2 a);
LLAL_INLINE unsigned u2x2_clesce_product(unsigned2x2 a);
LLAL_INLINE unsigned u2x2_clesce_min(unsigned2x2 a);
LLAL_INLINE unsigned u2x2_clesce_max(unsigned2x2 a);
LLAL_INLINE unsigned2x2 u2x2_matmult_u2x2(unsigned2x2 a, unsigned2x2 b);
LLAL_INLINE unsigned2 u2x2_matmult_u2c(unsigned2x2 a, unsigned2 b);
LLAL_INLINE unsigned2 u2r_matmult_u2x2(unsigned2 a, unsigned2x2 b);
LLAL_INLINE unsigned2x2 u2x2_transpose(unsigned2x2 a);
LLAL_INLINE unsigned2x2 u2x2_scale(unsigned2 by);

LLAL_INLINE float3x3 f3x3_identity(void);
LLAL_INLINE float3x3 f3x3_add(float3x3 a, float3x3 b);
LLAL_INLINE float3x3 f3x3_add_f(float3x3 a, float b);
LLAL_INLINE float3x3 f3x3_sub(float3x3 a, float3x3 b);
LLAL_INLINE float3x3 f3x3_sub_f(float3x3 a, float b);
LLAL_INLINE float3x3 f3x3_mul(float3x3 a, float3x3 b);
LLAL_INLINE float3x3 f3x3_mul_f(float3x3 a, float b);
LLAL_INLINE float3x3 f3x3_div(float3x3 a, float3x3 b);
LLAL_INLINE float3x3 f3x3_div_f(float3x3 a, float b);
LLAL_INLINE float f3x3_clesce_sum(float3x3 a);
LLAL_INLINE float f3x3_clesce_product(float3x3 a);
LLAL_INLINE float f3x3_clesce_min(float3x3 a);
LLAL_INLINE float f3x3_clesce_max(float3x3 a);
LLAL_INLINE float3x3 f3x3_matmult_f3x3(float3x3 a, float3x3 b);
LLAL_INLINE float3 f3x3_matmult_f3c(float3x3 a, float3 b);
LLAL_INLINE float3 f3r_matmult_f3x3(float3 a, float3x3 b);
LLAL_INLINE float3x3 f3x3_transpose(float3x3 a);
LLAL_INLINE float3x3 f3x3_scale(float3 by);
LLAL_INLINE float3x3 f3x3_rotate(float angle, float3 axis);

LLAL_INLINE double3x3 d3x3_identity(void);
LLAL_INLINE double3x3 d3x3_add(double3x3 a, double3x3 b);
LLAL_INLINE double3x3 d3x3_add_d(double3x3 a, double b);
LLAL_INLINE double3x3 d3x3_sub(double3x3 a, double3x3 b);
LLAL_INLINE double3x3 d3x3_sub_d(double3x3 a, double b);
LLAL_INLINE double3x3 d3x3_mul(double3x3 a, double3x3 b);
LLAL_INLINE double3x3 d3x3_mul_d(double3x3 a, double b);
LLAL_INLINE double3x3 d3x3_div(double3x3 a, double3x3 b);
LLAL_INLINE double3x3 d3x3_div_d(double3x3 a, double b);
LLAL_INLINE double d3x3_clesce_sum(double3x3 a);
LLAL_INLINE double d3x3_clesce_product(double3x3 a);
LLAL_INLINE double d3x3_clesce_min(double3x3 a);
LLAL_INLINE double d3x3_clesce_max(double3x3 a);
LLAL_INLINE double3x3 d3x3_matmult_d3x3(double3x3 a, double3x3 b);
LLAL_INLINE double3 d3x3_matmult_d3c(double3x3 a, double3 b);
LLAL_INLINE double3 d3r_matmult_d3x3(double3 a, double3x3 b);
LLAL_INLINE double3x3 d3x3_transpose(double3x3 a);
LLAL_INLINE double3x3 d3x3_scale(double3 by);
LLAL_INLINE double3x3 d3x3_rotate(double angle, double3 axis);

LLAL_INLINE int3x3 i3x3_identity(void);
LLAL_INLINE int3x3 i3x3_add(int3x3 a, int3x3 b);
LLAL_INLINE int3x3 i3x3_add_i(int3x3 a, int b);
LLAL_INLINE int3x3 i3x3_sub(int3x3 a, int3x3 b);
LLAL_INLINE int3x3 i3x3_sub_i(int3x3 a, int b);
LLAL_INLINE int3x3 i3x3_mul(int3x3 a, int3x3 b);
LLAL_INLINE int3x3 i3x3_mul_i(int3x3 a, int b);
LLAL_INLINE int3x3 i3x3_div(int3x3 a, int3x3 b);
LLAL_INLINE int3x3 i3x3_div_i(int3x3 a, int b);
LLAL_INLINE int i3x3_clesce_sum(int3x3 a);
LLAL_INLINE int i3x3_clesce_product(int3x3 a);
LLAL_INLINE int i3x3_clesce_min(int3x3 a);
LLAL_INLINE int i3x3_clesce_max(int3x3 a);
LLAL_INLINE int3x3 i3x3_matmult_i3x3(int3x3 a, int3x3 b);
LLAL_INLINE int3 i3x3_matmult_i3c(int3x3 a, int3 b);
LLAL_INLINE int3 i3r_matmult_i3x3(int3 a, int3x3 b);
LLAL_INLINE int3x3 i3x3_transpose(int3x3 a);
LLAL_INLINE int3x3 i3x3_scale(int3 by);

LLAL_INLINE unsigned3x3 u3x3_identity(void);
LLAL_INLINE unsigned3x3 u3x3_add(unsigned3x3 a, unsigned3x3 b);
LLAL_INLINE unsigned3x3 u3x3_add_u(unsigned3x3 a, unsigned b);
LLAL_INLINE unsigned3x3 u3x3_sub(unsigned3x3 a, unsigned3x3 b);
LLAL_INLINE unsigned3x3 u3x3_sub_u(unsigned3x3 a, unsigned b);
LLAL_INLINE unsigned3x3 u3x3_mul(unsigned3x3 a, unsigned3x3 b);
LLAL_INLINE unsigned3x3 u3x3_mul_u(unsigned3x3 a, unsigned b);
LLAL_INLINE unsigned3x3 u3x3_div(unsigned3x3 a, unsigned3x3 b);
LLAL_INLINE unsigned3x3 u3x3_div_u(unsigned3x3 a, unsigned b);
LLAL_INLINE unsigned u3x3_clesce_sum(unsigned3x3 a);
LLAL_INLINE unsigned u3x3_clesce_product(unsigned3x3 a);
LLAL_INLINE unsigned u3x3_clesce_min(unsigned3x3 a);
LLAL_INLINE unsigned u3x3_clesce_max(unsigned3x3 a);
LLAL_INLINE unsigned3x3 u3x3_matmult_u3x3(unsigned3x3 a, unsigned3x3 b);
LLAL_INLINE unsigned3 u3x3_matmult_u3c(unsigned3x3 a, unsigned3 b);
LLAL_INLINE unsigned3 u3r_matmult_u3x3(unsigned3 a, unsigned3x3 b);
LLAL_INLINE unsigned3x3 u3x3_transpose(unsigned3x3 a);
LLAL_INLINE unsigned3x3 u3x3_scale(unsigned3 by);

LLAL_INLINE float4x4 f4x4_identity(void);
LLAL_INLINE float4x4 f4x4_add(float4x4 a, float4x4 b);
LLAL_INLINE float4x4 f4x4_add_f(float4x4 a, float b);
LLAL_INLINE float4x4 f4x4_sub(float4x4 a, float4x4 b);
LLAL_INLINE float4x4 f4x4_sub_f(float4x4 a, float b);
LLAL_INLINE float4x4 f4x4_mul(float4x4 a, float4x4 b);
LLAL_INLINE float4x4 f4x4_mul_f(float4x4 a, float b);
LLAL_INLINE float4x4 f4x4_div(float4x4 a, float4x4 b);
LLAL_INLINE float4x4 f4x4_div_f(float4x4 a, float b);
LLAL_INLINE float f4x4_clesce_sum(float4x4 a);
LLAL_INLINE float f4x4_clesce_product(float4x4 a);
LLAL_INLINE float f4x4_clesce_min(float4x4 a);
LLAL_INLINE float f4x4_clesce_max(float4x4 a);
LLAL_INLINE float4x4 f4x4_matmult_f4x4(float4x4 a, float4x4 b);
LLAL_INLINE float4 f4x4_matmult_f4c(float4x4 a, float4 b);
LLAL_INLINE float4 f4r_matmult_f4x4(float4 a, float4x4 b);
LLAL_INLINE float4x4 f4x4_transpose(float4x4 a);
LLAL_INLINE float4x4 f4x4_scale(float4 by);
LLAL_INLINE float4x4 f4x4_rotate(float angle, float3 axis);
LLAL_INLINE float4x4 f4x4_translate(float3 by);

LLAL_INLINE double4x4 d4x4_identity(void);
LLAL_INLINE double4x4 d4x4_add(double4x4 a, double4x4 b);
LLAL_INLINE double4x4 d4x4_add_d(double4x4 a, double b);
LLAL_INLINE double4x4 d4x4_sub(double4x4 a, double4x4 b);
LLAL_INLINE double4x4 d4x4_sub_d(double4x4 a, double b);
LLAL_INLINE double4x4 d4x4_mul(double4x4 a, double4x4 b);
LLAL_INLINE double4x4 d4x4_mul_d(double4x4 a, double b);
LLAL_INLINE double4x4 d4x4_div(double4x4 a, double4x4 b);
LLAL_INLINE double4x4 d4x4_div_d(double4x4 a, double b);
LLAL_INLINE double d4x4_clesce_sum(double4x4 a);
LLAL_INLINE double d4x4_clesce_product(double4x4 a);
LLAL_INLINE double d4x4_clesce_min(double4x4 a);
LLAL_INLINE double d4x4_clesce_max(double4x4 a);
LLAL_INLINE double4x4 d4x4_matmult_d4x4(double4x4 a, double4x4 b);
LLAL_INLINE double4 d4x4_matmult_d4c(double4x4 a, double4 b);
LLAL_INLINE double4 d4r_matmult_d4x4(double4 a, double4x4 b);
LLAL_INLINE double4x4 d4x4_transpose(double4x4 a);
LLAL_INLINE double4x4 d4x4_scale(double4 by);
LLAL_INLINE double4x4 d4x4_rotate(double angle, double3 axis);
LLAL_INLINE double4x4 d4x4_translate(double3 by);

LLAL_INLINE int4x4 i4x4_identity(void);
LLAL_INLINE int4x4 i4x4_add(int4x4 a, int4x4 b);
LLAL_INLINE int4x4 i4x4_add_i(int4x4 a, int b);
LLAL_INLINE int4x4 i4x4_sub(int4x4 a, int4x4 b);
LLAL_INLINE int4x4 i4x4_sub_i(int4x4 a, int b);
LLAL_INLINE int4x4 i4x4_mul(int4x4 a, int4x4 b);
LLAL_INLINE int4x4 i4x4_mul_i(int4x4 a, int b);
LLAL_INLINE int4x4 i4x4_div(int4x4 a, int4x4 b);
LLAL_INLINE int4x4 i4x4_div_i(int4x4 a, int b);
LLAL_INLINE int i4x4_clesce_sum(int4x4 a);
LLAL_INLINE int i4x4_clesce_product(int4x4 a);
LLAL_INLINE int i4x4_clesce_min(int4x4 a);
LLAL_INLINE int i4x4_clesce_max(int4x4 a);
LLAL_INLINE int4x4 i4x4_matmult_i4x4(int4x4 a, int4x4 b);
LLAL_INLINE int4 i4x4_matmult_i4c(int4x4 a, int4 b);
LLAL_INLINE int4 i4r_matmult_i4x4(int4 a, int4x4 b);
LLAL_INLINE int4x4 i4x4_transpose(int4x4 a);
LLAL_INLINE int4x4 i4x4_scale(int4 by);
LLAL_INLINE int4x4 i4x4_translate(int3 by);

LLAL_INLINE unsigned4x4 u4x4_identity(void);
LLAL_INLINE unsigned4x4 u4x4_add(unsigned4x4 a, unsigned4x4 b);
LLAL_INLINE unsigned4x4 u4x4_add_u(unsigned4x4 a, unsigned b);
LLAL_INLINE unsigned4x4 u4x4_sub(unsigned4x4 a, unsigned4x4 b);
LLAL_INLINE unsigned4x4 u4x4_sub_u(unsigned4x4 a, unsigned b);
LLAL_INLINE unsigned4x4 u4x4_mul(unsigned4x4 a, unsigned4x4 b);
LLAL_INLINE unsigned4x4 u4x4_mul_u(unsigned4x4 a, unsigned b);
LLAL_INLINE unsigned4x4 u4x4_div(unsigned4x4 a, unsigned4x4 b);
LLAL_INLINE unsigned4x4 u4x4_div_u(unsigned4x4 a, unsigned b);
LLAL_INLINE unsigned u4x4_clesce_sum(unsigned4x4 a);
LLAL_INLINE unsigned u4x4_clesce_product(unsigned4x4 a);
LLAL_INLINE unsigned u4x4_clesce_min(unsigned4x4 a);
LLAL_INLINE unsigned u4x4_clesce_max(unsigned4x4 a);
LLAL_INLINE unsigned4x4 u4x4_matmult_u4x4(unsigned4x4 a, unsigned4x4 b);
LLAL_INLINE unsigned4 u4x4_matmult_u4c(unsigned4x4 a, unsigned4 b);
LLAL_INLINE unsigned4 u4r_matmult_u4x4(unsigned4 a, unsigned4x4 b);
LLAL_INLINE unsigned4x4 u4x4_transpose(unsigned4x4 a);
LLAL_INLINE unsigned4x4 u4x4_scale(unsigned4 by);
LLAL_INLINE unsigned4x4 u4x4_translate(unsigned3 by);

#endif // !LLAL_USE_STATIC_INLINE

#ifdef LLAL_IMPLEMENTATION

LLAL_INLINE float2 f2_ctor_f(float x){
	return (float2){{ x, }};
}

LLAL_INLINE float2 f2_ctor_f2(float2 xy){
	return (float2){{ xy.x, xy.y }};
}

LLAL_INLINE float2 f2_ctor_ff(float x, float y){
	return (float2){{ x, y }};
}

LLAL_INLINE float2 f2_add(float2 a, float2 b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] += b.c[i];
	return a;
}

LLAL_INLINE float2 f2_add_f(float2 a, float b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] += b;
	return a;
}

LLAL_INLINE float2 f2_sub(float2 a, float2 b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] -= b.c[i];
	return a;
}

LLAL_INLINE float2 f2_sub_f(float2 a, float b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] -= b;
	return a;
}

LLAL_INLINE float2 f2_mul(float2 a, float2 b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] *= b.c[i];
	return a;
}

LLAL_INLINE float2 f2_mul_f(float2 a, float b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] *= b;
	return a;
}

LLAL_INLINE float2 f2_div(float2 a, float2 b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] /= b.c[i];
	return a;
}

LLAL_INLINE float2 f2_div_f(float2 a, float b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] /= b;
	return a;
}

LLAL_INLINE float f2_clesce_sum(float2 a) {
	return a.x + a.y;
}

LLAL_INLINE float f2_clesce_product(float2 a) {
	return a.x * a.y;
}

LLAL_INLINE float f2_clesce_min(float2 a) {
	return MIN(a.x, a.y);;
}

LLAL_INLINE float f2_clesce_max(float2 a) {
	return MAX(a.x, a.y);;
}

LLAL_INLINE float f2_dot(float2 a, float2 b) {
	return f2_clesce_sum(f2_mul(a, b));
}

LLAL_INLINE float f2_lensqr(float2 a) {
	return a.x*a.x + a.y*a.y;
}

LLAL_INLINE float f2_len(float2 a) {
	return sqrtf(f2_lensqr(a));
}

LLAL_INLINE float2 f2_normalize(float2 a) {
	return f2_div_f(a, f2_len(a));
}


LLAL_INLINE double2 d2_ctor_d(double x){
	return (double2){{ x, }};
}

LLAL_INLINE double2 d2_ctor_d2(double2 xy){
	return (double2){{ xy.x, xy.y }};
}

LLAL_INLINE double2 d2_ctor_dd(double x, double y){
	return (double2){{ x, y }};
}

LLAL_INLINE double2 d2_add(double2 a, double2 b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] += b.c[i];
	return a;
}

LLAL_INLINE double2 d2_add_d(double2 a, double b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] += b;
	return a;
}

LLAL_INLINE double2 d2_sub(double2 a, double2 b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] -= b.c[i];
	return a;
}

LLAL_INLINE double2 d2_sub_d(double2 a, double b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] -= b;
	return a;
}

LLAL_INLINE double2 d2_mul(double2 a, double2 b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] *= b.c[i];
	return a;
}

LLAL_INLINE double2 d2_mul_d(double2 a, double b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] *= b;
	return a;
}

LLAL_INLINE double2 d2_div(double2 a, double2 b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] /= b.c[i];
	return a;
}

LLAL_INLINE double2 d2_div_d(double2 a, double b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] /= b;
	return a;
}

LLAL_INLINE double d2_clesce_sum(double2 a) {
	return a.x + a.y;
}

LLAL_INLINE double d2_clesce_product(double2 a) {
	return a.x * a.y;
}

LLAL_INLINE double d2_clesce_min(double2 a) {
	return MIN(a.x, a.y);;
}

LLAL_INLINE double d2_clesce_max(double2 a) {
	return MAX(a.x, a.y);;
}

LLAL_INLINE double d2_dot(double2 a, double2 b) {
	return d2_clesce_sum(d2_mul(a, b));
}

LLAL_INLINE double d2_lensqr(double2 a) {
	return a.x*a.x + a.y*a.y;
}

LLAL_INLINE double d2_len(double2 a) {
	return sqrt(d2_lensqr(a));
}

LLAL_INLINE double2 d2_normalize(double2 a) {
	return d2_div_d(a, d2_len(a));
}


LLAL_INLINE int2 i2_ctor_i(int x){
	return (int2){{ x, }};
}

LLAL_INLINE int2 i2_ctor_i2(int2 xy){
	return (int2){{ xy.x, xy.y }};
}

LLAL_INLINE int2 i2_ctor_ii(int x, int y){
	return (int2){{ x, y }};
}

LLAL_INLINE int2 i2_add(int2 a, int2 b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] += b.c[i];
	return a;
}

LLAL_INLINE int2 i2_add_i(int2 a, int b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] += b;
	return a;
}

LLAL_INLINE int2 i2_sub(int2 a, int2 b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] -= b.c[i];
	return a;
}

LLAL_INLINE int2 i2_sub_i(int2 a, int b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] -= b;
	return a;
}

LLAL_INLINE int2 i2_mul(int2 a, int2 b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] *= b.c[i];
	return a;
}

LLAL_INLINE int2 i2_mul_i(int2 a, int b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] *= b;
	return a;
}

LLAL_INLINE int2 i2_div(int2 a, int2 b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] /= b.c[i];
	return a;
}

LLAL_INLINE int2 i2_div_i(int2 a, int b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] /= b;
	return a;
}

LLAL_INLINE int i2_clesce_sum(int2 a) {
	return a.x + a.y;
}

LLAL_INLINE int i2_clesce_product(int2 a) {
	return a.x * a.y;
}

LLAL_INLINE int i2_clesce_min(int2 a) {
	return MIN(a.x, a.y);;
}

LLAL_INLINE int i2_clesce_max(int2 a) {
	return MAX(a.x, a.y);;
}

LLAL_INLINE int i2_dot(int2 a, int2 b) {
	return i2_clesce_sum(i2_mul(a, b));
}

LLAL_INLINE int i2_lensqr(int2 a) {
	return a.x*a.x + a.y*a.y;
}


LLAL_INLINE unsigned2 u2_ctor_u(unsigned x){
	return (unsigned2){{ x, }};
}

LLAL_INLINE unsigned2 u2_ctor_u2(unsigned2 xy){
	return (unsigned2){{ xy.x, xy.y }};
}

LLAL_INLINE unsigned2 u2_ctor_uu(unsigned x, unsigned y){
	return (unsigned2){{ x, y }};
}

LLAL_INLINE unsigned2 u2_add(unsigned2 a, unsigned2 b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] += b.c[i];
	return a;
}

LLAL_INLINE unsigned2 u2_add_u(unsigned2 a, unsigned b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] += b;
	return a;
}

LLAL_INLINE unsigned2 u2_sub(unsigned2 a, unsigned2 b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] -= b.c[i];
	return a;
}

LLAL_INLINE unsigned2 u2_sub_u(unsigned2 a, unsigned b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] -= b;
	return a;
}

LLAL_INLINE unsigned2 u2_mul(unsigned2 a, unsigned2 b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] *= b.c[i];
	return a;
}

LLAL_INLINE unsigned2 u2_mul_u(unsigned2 a, unsigned b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] *= b;
	return a;
}

LLAL_INLINE unsigned2 u2_div(unsigned2 a, unsigned2 b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] /= b.c[i];
	return a;
}

LLAL_INLINE unsigned2 u2_div_u(unsigned2 a, unsigned b) {
	for (unsigned i = 0; i < 2; i++)
		a.c[i] /= b;
	return a;
}

LLAL_INLINE unsigned u2_clesce_sum(unsigned2 a) {
	return a.x + a.y;
}

LLAL_INLINE unsigned u2_clesce_product(unsigned2 a) {
	return a.x * a.y;
}

LLAL_INLINE unsigned u2_clesce_min(unsigned2 a) {
	return MIN(a.x, a.y);;
}

LLAL_INLINE unsigned u2_clesce_max(unsigned2 a) {
	return MAX(a.x, a.y);;
}

LLAL_INLINE unsigned u2_dot(unsigned2 a, unsigned2 b) {
	return u2_clesce_sum(u2_mul(a, b));
}

LLAL_INLINE unsigned u2_lensqr(unsigned2 a) {
	return a.x*a.x + a.y*a.y;
}


LLAL_INLINE float3 f3_ctor_f(float x){
	return (float3){{ x, }};
}

LLAL_INLINE float3 f3_ctor_f3(float3 xyz){
	return (float3){{ xyz.x, xyz.y, xyz.z }};
}

LLAL_INLINE float3 f3_ctor_f2f(float2 xy, float z){
	return (float3){{ xy.x, xy.y, z }};
}

LLAL_INLINE float3 f3_ctor_ff2(float x, float2 yz){
	return (float3){{ x, yz.x, yz.y }};
}

LLAL_INLINE float3 f3_ctor_fff(float x, float y, float z){
	return (float3){{ x, y, z }};
}

LLAL_INLINE float3 f3_add(float3 a, float3 b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] += b.c[i];
	return a;
}

LLAL_INLINE float3 f3_add_f(float3 a, float b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] += b;
	return a;
}

LLAL_INLINE float3 f3_sub(float3 a, float3 b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] -= b.c[i];
	return a;
}

LLAL_INLINE float3 f3_sub_f(float3 a, float b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] -= b;
	return a;
}

LLAL_INLINE float3 f3_mul(float3 a, float3 b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] *= b.c[i];
	return a;
}

LLAL_INLINE float3 f3_mul_f(float3 a, float b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] *= b;
	return a;
}

LLAL_INLINE float3 f3_div(float3 a, float3 b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] /= b.c[i];
	return a;
}

LLAL_INLINE float3 f3_div_f(float3 a, float b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] /= b;
	return a;
}

LLAL_INLINE float f3_clesce_sum(float3 a) {
	return a.x + a.y + a.z;
}

LLAL_INLINE float f3_clesce_product(float3 a) {
	return a.x * a.y * a.z;
}

LLAL_INLINE float f3_clesce_min(float3 a) {
	a.x = MIN(a.x, a.y);
	return MIN(a.x, a.z);;
}

LLAL_INLINE float f3_clesce_max(float3 a) {
	a.x = MAX(a.x, a.y);
	return MAX(a.x, a.z);;
}

LLAL_INLINE float f3_dot(float3 a, float3 b) {
	return f3_clesce_sum(f3_mul(a, b));
}

LLAL_INLINE float3 f3_cross(float3 a, float3 b) {
	return (float3){
		.x = a.y*b.z - a.z*b.y,
		.y = a.z*b.x - a.x*b.z,
		.z = a.x*b.y - a.y*b.x,
	};
}

LLAL_INLINE float f3_lensqr(float3 a) {
	return a.x*a.x + a.y*a.y + a.z*a.z;
}

LLAL_INLINE float f3_len(float3 a) {
	return sqrtf(f3_lensqr(a));
}

LLAL_INLINE float3 f3_normalize(float3 a) {
	return f3_div_f(a, f3_len(a));
}


LLAL_INLINE double3 d3_ctor_d(double x){
	return (double3){{ x, }};
}

LLAL_INLINE double3 d3_ctor_d3(double3 xyz){
	return (double3){{ xyz.x, xyz.y, xyz.z }};
}

LLAL_INLINE double3 d3_ctor_d2d(double2 xy, double z){
	return (double3){{ xy.x, xy.y, z }};
}

LLAL_INLINE double3 d3_ctor_dd2(double x, double2 yz){
	return (double3){{ x, yz.x, yz.y }};
}

LLAL_INLINE double3 d3_ctor_ddd(double x, double y, double z){
	return (double3){{ x, y, z }};
}

LLAL_INLINE double3 d3_add(double3 a, double3 b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] += b.c[i];
	return a;
}

LLAL_INLINE double3 d3_add_d(double3 a, double b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] += b;
	return a;
}

LLAL_INLINE double3 d3_sub(double3 a, double3 b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] -= b.c[i];
	return a;
}

LLAL_INLINE double3 d3_sub_d(double3 a, double b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] -= b;
	return a;
}

LLAL_INLINE double3 d3_mul(double3 a, double3 b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] *= b.c[i];
	return a;
}

LLAL_INLINE double3 d3_mul_d(double3 a, double b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] *= b;
	return a;
}

LLAL_INLINE double3 d3_div(double3 a, double3 b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] /= b.c[i];
	return a;
}

LLAL_INLINE double3 d3_div_d(double3 a, double b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] /= b;
	return a;
}

LLAL_INLINE double d3_clesce_sum(double3 a) {
	return a.x + a.y + a.z;
}

LLAL_INLINE double d3_clesce_product(double3 a) {
	return a.x * a.y * a.z;
}

LLAL_INLINE double d3_clesce_min(double3 a) {
	a.x = MIN(a.x, a.y);
	return MIN(a.x, a.z);;
}

LLAL_INLINE double d3_clesce_max(double3 a) {
	a.x = MAX(a.x, a.y);
	return MAX(a.x, a.z);;
}

LLAL_INLINE double d3_dot(double3 a, double3 b) {
	return d3_clesce_sum(d3_mul(a, b));
}

LLAL_INLINE double3 d3_cross(double3 a, double3 b) {
	return (double3){
		.x = a.y*b.z - a.z*b.y,
		.y = a.z*b.x - a.x*b.z,
		.z = a.x*b.y - a.y*b.x,
	};
}

LLAL_INLINE double d3_lensqr(double3 a) {
	return a.x*a.x + a.y*a.y + a.z*a.z;
}

LLAL_INLINE double d3_len(double3 a) {
	return sqrt(d3_lensqr(a));
}

LLAL_INLINE double3 d3_normalize(double3 a) {
	return d3_div_d(a, d3_len(a));
}


LLAL_INLINE int3 i3_ctor_i(int x){
	return (int3){{ x, }};
}

LLAL_INLINE int3 i3_ctor_i3(int3 xyz){
	return (int3){{ xyz.x, xyz.y, xyz.z }};
}

LLAL_INLINE int3 i3_ctor_i2i(int2 xy, int z){
	return (int3){{ xy.x, xy.y, z }};
}

LLAL_INLINE int3 i3_ctor_ii2(int x, int2 yz){
	return (int3){{ x, yz.x, yz.y }};
}

LLAL_INLINE int3 i3_ctor_iii(int x, int y, int z){
	return (int3){{ x, y, z }};
}

LLAL_INLINE int3 i3_add(int3 a, int3 b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] += b.c[i];
	return a;
}

LLAL_INLINE int3 i3_add_i(int3 a, int b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] += b;
	return a;
}

LLAL_INLINE int3 i3_sub(int3 a, int3 b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] -= b.c[i];
	return a;
}

LLAL_INLINE int3 i3_sub_i(int3 a, int b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] -= b;
	return a;
}

LLAL_INLINE int3 i3_mul(int3 a, int3 b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] *= b.c[i];
	return a;
}

LLAL_INLINE int3 i3_mul_i(int3 a, int b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] *= b;
	return a;
}

LLAL_INLINE int3 i3_div(int3 a, int3 b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] /= b.c[i];
	return a;
}

LLAL_INLINE int3 i3_div_i(int3 a, int b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] /= b;
	return a;
}

LLAL_INLINE int i3_clesce_sum(int3 a) {
	return a.x + a.y + a.z;
}

LLAL_INLINE int i3_clesce_product(int3 a) {
	return a.x * a.y * a.z;
}

LLAL_INLINE int i3_clesce_min(int3 a) {
	a.x = MIN(a.x, a.y);
	return MIN(a.x, a.z);;
}

LLAL_INLINE int i3_clesce_max(int3 a) {
	a.x = MAX(a.x, a.y);
	return MAX(a.x, a.z);;
}

LLAL_INLINE int i3_dot(int3 a, int3 b) {
	return i3_clesce_sum(i3_mul(a, b));
}

LLAL_INLINE int3 i3_cross(int3 a, int3 b) {
	return (int3){
		.x = a.y*b.z - a.z*b.y,
		.y = a.z*b.x - a.x*b.z,
		.z = a.x*b.y - a.y*b.x,
	};
}

LLAL_INLINE int i3_lensqr(int3 a) {
	return a.x*a.x + a.y*a.y + a.z*a.z;
}


LLAL_INLINE unsigned3 u3_ctor_u(unsigned x){
	return (unsigned3){{ x, }};
}

LLAL_INLINE unsigned3 u3_ctor_u3(unsigned3 xyz){
	return (unsigned3){{ xyz.x, xyz.y, xyz.z }};
}

LLAL_INLINE unsigned3 u3_ctor_u2u(unsigned2 xy, unsigned z){
	return (unsigned3){{ xy.x, xy.y, z }};
}

LLAL_INLINE unsigned3 u3_ctor_uu2(unsigned x, unsigned2 yz){
	return (unsigned3){{ x, yz.x, yz.y }};
}

LLAL_INLINE unsigned3 u3_ctor_uuu(unsigned x, unsigned y, unsigned z){
	return (unsigned3){{ x, y, z }};
}

LLAL_INLINE unsigned3 u3_add(unsigned3 a, unsigned3 b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] += b.c[i];
	return a;
}

LLAL_INLINE unsigned3 u3_add_u(unsigned3 a, unsigned b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] += b;
	return a;
}

LLAL_INLINE unsigned3 u3_sub(unsigned3 a, unsigned3 b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] -= b.c[i];
	return a;
}

LLAL_INLINE unsigned3 u3_sub_u(unsigned3 a, unsigned b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] -= b;
	return a;
}

LLAL_INLINE unsigned3 u3_mul(unsigned3 a, unsigned3 b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] *= b.c[i];
	return a;
}

LLAL_INLINE unsigned3 u3_mul_u(unsigned3 a, unsigned b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] *= b;
	return a;
}

LLAL_INLINE unsigned3 u3_div(unsigned3 a, unsigned3 b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] /= b.c[i];
	return a;
}

LLAL_INLINE unsigned3 u3_div_u(unsigned3 a, unsigned b) {
	for (unsigned i = 0; i < 3; i++)
		a.c[i] /= b;
	return a;
}

LLAL_INLINE unsigned u3_clesce_sum(unsigned3 a) {
	return a.x + a.y + a.z;
}

LLAL_INLINE unsigned u3_clesce_product(unsigned3 a) {
	return a.x * a.y * a.z;
}

LLAL_INLINE unsigned u3_clesce_min(unsigned3 a) {
	a.x = MIN(a.x, a.y);
	return MIN(a.x, a.z);;
}

LLAL_INLINE unsigned u3_clesce_max(unsigned3 a) {
	a.x = MAX(a.x, a.y);
	return MAX(a.x, a.z);;
}

LLAL_INLINE unsigned u3_dot(unsigned3 a, unsigned3 b) {
	return u3_clesce_sum(u3_mul(a, b));
}

LLAL_INLINE unsigned u3_lensqr(unsigned3 a) {
	return a.x*a.x + a.y*a.y + a.z*a.z;
}


LLAL_INLINE float4 f4_ctor_f(float x){
	return (float4){{ x, }};
}

LLAL_INLINE float4 f4_ctor_f4(float4 xyzw){
	return (float4){{ xyzw.x, xyzw.y, xyzw.z, xyzw.w }};
}

LLAL_INLINE float4 f4_ctor_f3f(float3 xyz, float w){
	return (float4){{ xyz.x, xyz.y, xyz.z, w }};
}

LLAL_INLINE float4 f4_ctor_f2f2(float2 xy, float2 zw){
	return (float4){{ xy.x, xy.y, zw.x, zw.y }};
}

LLAL_INLINE float4 f4_ctor_ff3(float x, float3 yzw){
	return (float4){{ x, yzw.x, yzw.y, yzw.z }};
}

LLAL_INLINE float4 f4_ctor_f2ff(float2 xy, float z, float w){
	return (float4){{ xy.x, xy.y, z, w }};
}

LLAL_INLINE float4 f4_ctor_ff2f(float x, float2 yz, float w){
	return (float4){{ x, yz.x, yz.y, w }};
}

LLAL_INLINE float4 f4_ctor_fff2(float x, float y, float2 zw){
	return (float4){{ x, y, zw.x, zw.y }};
}

LLAL_INLINE float4 f4_ctor_ffff(float x, float y, float z, float w){
	return (float4){{ x, y, z, w }};
}

LLAL_INLINE float4 f4_add(float4 a, float4 b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] += b.c[i];
	return a;
}

LLAL_INLINE float4 f4_add_f(float4 a, float b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] += b;
	return a;
}

LLAL_INLINE float4 f4_sub(float4 a, float4 b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] -= b.c[i];
	return a;
}

LLAL_INLINE float4 f4_sub_f(float4 a, float b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] -= b;
	return a;
}

LLAL_INLINE float4 f4_mul(float4 a, float4 b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] *= b.c[i];
	return a;
}

LLAL_INLINE float4 f4_mul_f(float4 a, float b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] *= b;
	return a;
}

LLAL_INLINE float4 f4_div(float4 a, float4 b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] /= b.c[i];
	return a;
}

LLAL_INLINE float4 f4_div_f(float4 a, float b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] /= b;
	return a;
}

LLAL_INLINE float f4_clesce_sum(float4 a) {
	return a.x + a.y + a.z + a.w;
}

LLAL_INLINE float f4_clesce_product(float4 a) {
	return a.x * a.y * a.z * a.w;
}

LLAL_INLINE float f4_clesce_min(float4 a) {
	a.x = MIN(a.x, a.y);
	a.z = MIN(a.z, a.w);
	return MIN(a.x, a.z);;
}

LLAL_INLINE float f4_clesce_max(float4 a) {
	a.x = MAX(a.x, a.y);
	a.z = MAX(a.z, a.w);
	return MAX(a.x, a.z);;
}

LLAL_INLINE float f4_dot(float4 a, float4 b) {
	return f4_clesce_sum(f4_mul(a, b));
}

LLAL_INLINE float f4_lensqr(float4 a) {
	return a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w;
}

LLAL_INLINE float f4_len(float4 a) {
	return sqrtf(f4_lensqr(a));
}

LLAL_INLINE float4 f4_normalize(float4 a) {
	return f4_div_f(a, f4_len(a));
}


LLAL_INLINE double4 d4_ctor_d(double x){
	return (double4){{ x, }};
}

LLAL_INLINE double4 d4_ctor_d4(double4 xyzw){
	return (double4){{ xyzw.x, xyzw.y, xyzw.z, xyzw.w }};
}

LLAL_INLINE double4 d4_ctor_d3d(double3 xyz, double w){
	return (double4){{ xyz.x, xyz.y, xyz.z, w }};
}

LLAL_INLINE double4 d4_ctor_d2d2(double2 xy, double2 zw){
	return (double4){{ xy.x, xy.y, zw.x, zw.y }};
}

LLAL_INLINE double4 d4_ctor_dd3(double x, double3 yzw){
	return (double4){{ x, yzw.x, yzw.y, yzw.z }};
}

LLAL_INLINE double4 d4_ctor_d2dd(double2 xy, double z, double w){
	return (double4){{ xy.x, xy.y, z, w }};
}

LLAL_INLINE double4 d4_ctor_dd2d(double x, double2 yz, double w){
	return (double4){{ x, yz.x, yz.y, w }};
}

LLAL_INLINE double4 d4_ctor_ddd2(double x, double y, double2 zw){
	return (double4){{ x, y, zw.x, zw.y }};
}

LLAL_INLINE double4 d4_ctor_dddd(double x, double y, double z, double w){
	return (double4){{ x, y, z, w }};
}

LLAL_INLINE double4 d4_add(double4 a, double4 b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] += b.c[i];
	return a;
}

LLAL_INLINE double4 d4_add_d(double4 a, double b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] += b;
	return a;
}

LLAL_INLINE double4 d4_sub(double4 a, double4 b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] -= b.c[i];
	return a;
}

LLAL_INLINE double4 d4_sub_d(double4 a, double b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] -= b;
	return a;
}

LLAL_INLINE double4 d4_mul(double4 a, double4 b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] *= b.c[i];
	return a;
}

LLAL_INLINE double4 d4_mul_d(double4 a, double b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] *= b;
	return a;
}

LLAL_INLINE double4 d4_div(double4 a, double4 b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] /= b.c[i];
	return a;
}

LLAL_INLINE double4 d4_div_d(double4 a, double b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] /= b;
	return a;
}

LLAL_INLINE double d4_clesce_sum(double4 a) {
	return a.x + a.y + a.z + a.w;
}

LLAL_INLINE double d4_clesce_product(double4 a) {
	return a.x * a.y * a.z * a.w;
}

LLAL_INLINE double d4_clesce_min(double4 a) {
	a.x = MIN(a.x, a.y);
	a.z = MIN(a.z, a.w);
	return MIN(a.x, a.z);;
}

LLAL_INLINE double d4_clesce_max(double4 a) {
	a.x = MAX(a.x, a.y);
	a.z = MAX(a.z, a.w);
	return MAX(a.x, a.z);;
}

LLAL_INLINE double d4_dot(double4 a, double4 b) {
	return d4_clesce_sum(d4_mul(a, b));
}

LLAL_INLINE double d4_lensqr(double4 a) {
	return a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w;
}

LLAL_INLINE double d4_len(double4 a) {
	return sqrt(d4_lensqr(a));
}

LLAL_INLINE double4 d4_normalize(double4 a) {
	return d4_div_d(a, d4_len(a));
}


LLAL_INLINE int4 i4_ctor_i(int x){
	return (int4){{ x, }};
}

LLAL_INLINE int4 i4_ctor_i4(int4 xyzw){
	return (int4){{ xyzw.x, xyzw.y, xyzw.z, xyzw.w }};
}

LLAL_INLINE int4 i4_ctor_i3i(int3 xyz, int w){
	return (int4){{ xyz.x, xyz.y, xyz.z, w }};
}

LLAL_INLINE int4 i4_ctor_i2i2(int2 xy, int2 zw){
	return (int4){{ xy.x, xy.y, zw.x, zw.y }};
}

LLAL_INLINE int4 i4_ctor_ii3(int x, int3 yzw){
	return (int4){{ x, yzw.x, yzw.y, yzw.z }};
}

LLAL_INLINE int4 i4_ctor_i2ii(int2 xy, int z, int w){
	return (int4){{ xy.x, xy.y, z, w }};
}

LLAL_INLINE int4 i4_ctor_ii2i(int x, int2 yz, int w){
	return (int4){{ x, yz.x, yz.y, w }};
}

LLAL_INLINE int4 i4_ctor_iii2(int x, int y, int2 zw){
	return (int4){{ x, y, zw.x, zw.y }};
}

LLAL_INLINE int4 i4_ctor_iiii(int x, int y, int z, int w){
	return (int4){{ x, y, z, w }};
}

LLAL_INLINE int4 i4_add(int4 a, int4 b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] += b.c[i];
	return a;
}

LLAL_INLINE int4 i4_add_i(int4 a, int b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] += b;
	return a;
}

LLAL_INLINE int4 i4_sub(int4 a, int4 b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] -= b.c[i];
	return a;
}

LLAL_INLINE int4 i4_sub_i(int4 a, int b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] -= b;
	return a;
}

LLAL_INLINE int4 i4_mul(int4 a, int4 b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] *= b.c[i];
	return a;
}

LLAL_INLINE int4 i4_mul_i(int4 a, int b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] *= b;
	return a;
}

LLAL_INLINE int4 i4_div(int4 a, int4 b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] /= b.c[i];
	return a;
}

LLAL_INLINE int4 i4_div_i(int4 a, int b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] /= b;
	return a;
}

LLAL_INLINE int i4_clesce_sum(int4 a) {
	return a.x + a.y + a.z + a.w;
}

LLAL_INLINE int i4_clesce_product(int4 a) {
	return a.x * a.y * a.z * a.w;
}

LLAL_INLINE int i4_clesce_min(int4 a) {
	a.x = MIN(a.x, a.y);
	a.z = MIN(a.z, a.w);
	return MIN(a.x, a.z);;
}

LLAL_INLINE int i4_clesce_max(int4 a) {
	a.x = MAX(a.x, a.y);
	a.z = MAX(a.z, a.w);
	return MAX(a.x, a.z);;
}

LLAL_INLINE int i4_dot(int4 a, int4 b) {
	return i4_clesce_sum(i4_mul(a, b));
}

LLAL_INLINE int i4_lensqr(int4 a) {
	return a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w;
}


LLAL_INLINE unsigned4 u4_ctor_u(unsigned x){
	return (unsigned4){{ x, }};
}

LLAL_INLINE unsigned4 u4_ctor_u4(unsigned4 xyzw){
	return (unsigned4){{ xyzw.x, xyzw.y, xyzw.z, xyzw.w }};
}

LLAL_INLINE unsigned4 u4_ctor_u3u(unsigned3 xyz, unsigned w){
	return (unsigned4){{ xyz.x, xyz.y, xyz.z, w }};
}

LLAL_INLINE unsigned4 u4_ctor_u2u2(unsigned2 xy, unsigned2 zw){
	return (unsigned4){{ xy.x, xy.y, zw.x, zw.y }};
}

LLAL_INLINE unsigned4 u4_ctor_uu3(unsigned x, unsigned3 yzw){
	return (unsigned4){{ x, yzw.x, yzw.y, yzw.z }};
}

LLAL_INLINE unsigned4 u4_ctor_u2uu(unsigned2 xy, unsigned z, unsigned w){
	return (unsigned4){{ xy.x, xy.y, z, w }};
}

LLAL_INLINE unsigned4 u4_ctor_uu2u(unsigned x, unsigned2 yz, unsigned w){
	return (unsigned4){{ x, yz.x, yz.y, w }};
}

LLAL_INLINE unsigned4 u4_ctor_uuu2(unsigned x, unsigned y, unsigned2 zw){
	return (unsigned4){{ x, y, zw.x, zw.y }};
}

LLAL_INLINE unsigned4 u4_ctor_uuuu(unsigned x, unsigned y, unsigned z, unsigned w){
	return (unsigned4){{ x, y, z, w }};
}

LLAL_INLINE unsigned4 u4_add(unsigned4 a, unsigned4 b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] += b.c[i];
	return a;
}

LLAL_INLINE unsigned4 u4_add_u(unsigned4 a, unsigned b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] += b;
	return a;
}

LLAL_INLINE unsigned4 u4_sub(unsigned4 a, unsigned4 b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] -= b.c[i];
	return a;
}

LLAL_INLINE unsigned4 u4_sub_u(unsigned4 a, unsigned b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] -= b;
	return a;
}

LLAL_INLINE unsigned4 u4_mul(unsigned4 a, unsigned4 b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] *= b.c[i];
	return a;
}

LLAL_INLINE unsigned4 u4_mul_u(unsigned4 a, unsigned b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] *= b;
	return a;
}

LLAL_INLINE unsigned4 u4_div(unsigned4 a, unsigned4 b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] /= b.c[i];
	return a;
}

LLAL_INLINE unsigned4 u4_div_u(unsigned4 a, unsigned b) {
	for (unsigned i = 0; i < 4; i++)
		a.c[i] /= b;
	return a;
}

LLAL_INLINE unsigned u4_clesce_sum(unsigned4 a) {
	return a.x + a.y + a.z + a.w;
}

LLAL_INLINE unsigned u4_clesce_product(unsigned4 a) {
	return a.x * a.y * a.z * a.w;
}

LLAL_INLINE unsigned u4_clesce_min(unsigned4 a) {
	a.x = MIN(a.x, a.y);
	a.z = MIN(a.z, a.w);
	return MIN(a.x, a.z);;
}

LLAL_INLINE unsigned u4_clesce_max(unsigned4 a) {
	a.x = MAX(a.x, a.y);
	a.z = MAX(a.z, a.w);
	return MAX(a.x, a.z);;
}

LLAL_INLINE unsigned u4_dot(unsigned4 a, unsigned4 b) {
	return u4_clesce_sum(u4_mul(a, b));
}

LLAL_INLINE unsigned u4_lensqr(unsigned4 a) {
	return a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w;
}


LLAL_INLINE float2x2 f2x2_identity(void) {
	return (float2x2){
		.x = {{ 1, 0, }},
		.y = {{ 0, 1, }},
	};
}

LLAL_INLINE float2x2 f2x2_add(float2x2 a, float2x2 b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] += b.v[j].c[i];
	return a;
}

LLAL_INLINE float2x2 f2x2_add_f(float2x2 a, float b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] += b;
	return a;
}

LLAL_INLINE float2x2 f2x2_sub(float2x2 a, float2x2 b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] -= b.v[j].c[i];
	return a;
}

LLAL_INLINE float2x2 f2x2_sub_f(float2x2 a, float b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] -= b;
	return a;
}

LLAL_INLINE float2x2 f2x2_mul(float2x2 a, float2x2 b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] *= b.v[j].c[i];
	return a;
}

LLAL_INLINE float2x2 f2x2_mul_f(float2x2 a, float b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] *= b;
	return a;
}

LLAL_INLINE float2x2 f2x2_div(float2x2 a, float2x2 b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] /= b.v[j].c[i];
	return a;
}

LLAL_INLINE float2x2 f2x2_div_f(float2x2 a, float b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] /= b;
	return a;
}

LLAL_INLINE float f2x2_clesce_sum(float2x2 a) {
	return (
		f2_clesce_sum(a.x) +
		f2_clesce_sum(a.y)
	);
}

LLAL_INLINE float f2x2_clesce_product(float2x2 a) {
	return (
		f2_clesce_product(a.x) *
		f2_clesce_product(a.y)
	);
}

LLAL_INLINE float f2x2_clesce_min(float2x2 a) {
	return f2_clesce_min(f2_ctor_ff(
		f2_clesce_min(a.x),
		f2_clesce_min(a.y)
	));
}

LLAL_INLINE float f2x2_clesce_max(float2x2 a) {
	return f2_clesce_max(f2_ctor_ff(
		f2_clesce_max(a.x),
		f2_clesce_max(a.y)
	));
}

LLAL_INLINE float2x2 f2x2_matmult_f2x2(float2x2 a, float2x2 b) {
	float2x2 c = {0};
	for (unsigned j = 0; j < 2; j++) {
		for (unsigned i = 0; i < 2; i++) {
			for (unsigned k = 0; k < 2; k++) {
				c.v[j].c[i] += a.v[k].c[i]*b.v[j].c[k];
			}
		}
	}
	return c;
}

LLAL_INLINE float2 f2x2_matmult_f2c(float2x2 a, float2 b) {
	return (float2){{
		f2_dot((float2){{ a.xx, a.yx }}, b),
		f2_dot((float2){{ a.xy, a.yy }}, b),
	}};
}

LLAL_INLINE float2 f2r_matmult_f2x2(float2 a, float2x2 b) {
	return (float2){{
		f2_dot(a, b.x),
		f2_dot(a, b.y),
	}};
}

LLAL_INLINE float2x2 f2x2_transpose(float2x2 a) {
	return (float2x2){
		.x = {{ a.xx, a.yx, }},
		.y = {{ a.xy, a.yy, }},
	};
}

LLAL_INLINE float2x2 f2x2_scale(float2 by) {
	float2x2 mat = {0};
	mat.xx = by.x;
	mat.yy = by.y;
	return mat;
}


LLAL_INLINE double2x2 d2x2_identity(void) {
	return (double2x2){
		.x = {{ 1, 0, }},
		.y = {{ 0, 1, }},
	};
}

LLAL_INLINE double2x2 d2x2_add(double2x2 a, double2x2 b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] += b.v[j].c[i];
	return a;
}

LLAL_INLINE double2x2 d2x2_add_d(double2x2 a, double b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] += b;
	return a;
}

LLAL_INLINE double2x2 d2x2_sub(double2x2 a, double2x2 b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] -= b.v[j].c[i];
	return a;
}

LLAL_INLINE double2x2 d2x2_sub_d(double2x2 a, double b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] -= b;
	return a;
}

LLAL_INLINE double2x2 d2x2_mul(double2x2 a, double2x2 b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] *= b.v[j].c[i];
	return a;
}

LLAL_INLINE double2x2 d2x2_mul_d(double2x2 a, double b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] *= b;
	return a;
}

LLAL_INLINE double2x2 d2x2_div(double2x2 a, double2x2 b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] /= b.v[j].c[i];
	return a;
}

LLAL_INLINE double2x2 d2x2_div_d(double2x2 a, double b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] /= b;
	return a;
}

LLAL_INLINE double d2x2_clesce_sum(double2x2 a) {
	return (
		d2_clesce_sum(a.x) +
		d2_clesce_sum(a.y)
	);
}

LLAL_INLINE double d2x2_clesce_product(double2x2 a) {
	return (
		d2_clesce_product(a.x) *
		d2_clesce_product(a.y)
	);
}

LLAL_INLINE double d2x2_clesce_min(double2x2 a) {
	return d2_clesce_min(d2_ctor_dd(
		d2_clesce_min(a.x),
		d2_clesce_min(a.y)
	));
}

LLAL_INLINE double d2x2_clesce_max(double2x2 a) {
	return d2_clesce_max(d2_ctor_dd(
		d2_clesce_max(a.x),
		d2_clesce_max(a.y)
	));
}

LLAL_INLINE double2x2 d2x2_matmult_d2x2(double2x2 a, double2x2 b) {
	double2x2 c = {0};
	for (unsigned j = 0; j < 2; j++) {
		for (unsigned i = 0; i < 2; i++) {
			for (unsigned k = 0; k < 2; k++) {
				c.v[j].c[i] += a.v[k].c[i]*b.v[j].c[k];
			}
		}
	}
	return c;
}

LLAL_INLINE double2 d2x2_matmult_d2c(double2x2 a, double2 b) {
	return (double2){{
		d2_dot((double2){{ a.xx, a.yx }}, b),
		d2_dot((double2){{ a.xy, a.yy }}, b),
	}};
}

LLAL_INLINE double2 d2r_matmult_d2x2(double2 a, double2x2 b) {
	return (double2){{
		d2_dot(a, b.x),
		d2_dot(a, b.y),
	}};
}

LLAL_INLINE double2x2 d2x2_transpose(double2x2 a) {
	return (double2x2){
		.x = {{ a.xx, a.yx, }},
		.y = {{ a.xy, a.yy, }},
	};
}

LLAL_INLINE double2x2 d2x2_scale(double2 by) {
	double2x2 mat = {0};
	mat.xx = by.x;
	mat.yy = by.y;
	return mat;
}


LLAL_INLINE int2x2 i2x2_identity(void) {
	return (int2x2){
		.x = {{ 1, 0, }},
		.y = {{ 0, 1, }},
	};
}

LLAL_INLINE int2x2 i2x2_add(int2x2 a, int2x2 b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] += b.v[j].c[i];
	return a;
}

LLAL_INLINE int2x2 i2x2_add_i(int2x2 a, int b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] += b;
	return a;
}

LLAL_INLINE int2x2 i2x2_sub(int2x2 a, int2x2 b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] -= b.v[j].c[i];
	return a;
}

LLAL_INLINE int2x2 i2x2_sub_i(int2x2 a, int b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] -= b;
	return a;
}

LLAL_INLINE int2x2 i2x2_mul(int2x2 a, int2x2 b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] *= b.v[j].c[i];
	return a;
}

LLAL_INLINE int2x2 i2x2_mul_i(int2x2 a, int b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] *= b;
	return a;
}

LLAL_INLINE int2x2 i2x2_div(int2x2 a, int2x2 b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] /= b.v[j].c[i];
	return a;
}

LLAL_INLINE int2x2 i2x2_div_i(int2x2 a, int b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] /= b;
	return a;
}

LLAL_INLINE int i2x2_clesce_sum(int2x2 a) {
	return (
		i2_clesce_sum(a.x) +
		i2_clesce_sum(a.y)
	);
}

LLAL_INLINE int i2x2_clesce_product(int2x2 a) {
	return (
		i2_clesce_product(a.x) *
		i2_clesce_product(a.y)
	);
}

LLAL_INLINE int i2x2_clesce_min(int2x2 a) {
	return i2_clesce_min(i2_ctor_ii(
		i2_clesce_min(a.x),
		i2_clesce_min(a.y)
	));
}

LLAL_INLINE int i2x2_clesce_max(int2x2 a) {
	return i2_clesce_max(i2_ctor_ii(
		i2_clesce_max(a.x),
		i2_clesce_max(a.y)
	));
}

LLAL_INLINE int2x2 i2x2_matmult_i2x2(int2x2 a, int2x2 b) {
	int2x2 c = {0};
	for (unsigned j = 0; j < 2; j++) {
		for (unsigned i = 0; i < 2; i++) {
			for (unsigned k = 0; k < 2; k++) {
				c.v[j].c[i] += a.v[k].c[i]*b.v[j].c[k];
			}
		}
	}
	return c;
}

LLAL_INLINE int2 i2x2_matmult_i2c(int2x2 a, int2 b) {
	return (int2){{
		i2_dot((int2){{ a.xx, a.yx }}, b),
		i2_dot((int2){{ a.xy, a.yy }}, b),
	}};
}

LLAL_INLINE int2 i2r_matmult_i2x2(int2 a, int2x2 b) {
	return (int2){{
		i2_dot(a, b.x),
		i2_dot(a, b.y),
	}};
}

LLAL_INLINE int2x2 i2x2_transpose(int2x2 a) {
	return (int2x2){
		.x = {{ a.xx, a.yx, }},
		.y = {{ a.xy, a.yy, }},
	};
}

LLAL_INLINE int2x2 i2x2_scale(int2 by) {
	int2x2 mat = {0};
	mat.xx = by.x;
	mat.yy = by.y;
	return mat;
}


LLAL_INLINE unsigned2x2 u2x2_identity(void) {
	return (unsigned2x2){
		.x = {{ 1, 0, }},
		.y = {{ 0, 1, }},
	};
}

LLAL_INLINE unsigned2x2 u2x2_add(unsigned2x2 a, unsigned2x2 b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] += b.v[j].c[i];
	return a;
}

LLAL_INLINE unsigned2x2 u2x2_add_u(unsigned2x2 a, unsigned b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] += b;
	return a;
}

LLAL_INLINE unsigned2x2 u2x2_sub(unsigned2x2 a, unsigned2x2 b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] -= b.v[j].c[i];
	return a;
}

LLAL_INLINE unsigned2x2 u2x2_sub_u(unsigned2x2 a, unsigned b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] -= b;
	return a;
}

LLAL_INLINE unsigned2x2 u2x2_mul(unsigned2x2 a, unsigned2x2 b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] *= b.v[j].c[i];
	return a;
}

LLAL_INLINE unsigned2x2 u2x2_mul_u(unsigned2x2 a, unsigned b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] *= b;
	return a;
}

LLAL_INLINE unsigned2x2 u2x2_div(unsigned2x2 a, unsigned2x2 b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] /= b.v[j].c[i];
	return a;
}

LLAL_INLINE unsigned2x2 u2x2_div_u(unsigned2x2 a, unsigned b) {
	for (unsigned j = 0; j < 2; j++)
		for (unsigned i = 0; i < 2; i++)
			a.v[j].c[i] /= b;
	return a;
}

LLAL_INLINE unsigned u2x2_clesce_sum(unsigned2x2 a) {
	return (
		u2_clesce_sum(a.x) +
		u2_clesce_sum(a.y)
	);
}

LLAL_INLINE unsigned u2x2_clesce_product(unsigned2x2 a) {
	return (
		u2_clesce_product(a.x) *
		u2_clesce_product(a.y)
	);
}

LLAL_INLINE unsigned u2x2_clesce_min(unsigned2x2 a) {
	return u2_clesce_min(u2_ctor_uu(
		u2_clesce_min(a.x),
		u2_clesce_min(a.y)
	));
}

LLAL_INLINE unsigned u2x2_clesce_max(unsigned2x2 a) {
	return u2_clesce_max(u2_ctor_uu(
		u2_clesce_max(a.x),
		u2_clesce_max(a.y)
	));
}

LLAL_INLINE unsigned2x2 u2x2_matmult_u2x2(unsigned2x2 a, unsigned2x2 b) {
	unsigned2x2 c = {0};
	for (unsigned j = 0; j < 2; j++) {
		for (unsigned i = 0; i < 2; i++) {
			for (unsigned k = 0; k < 2; k++) {
				c.v[j].c[i] += a.v[k].c[i]*b.v[j].c[k];
			}
		}
	}
	return c;
}

LLAL_INLINE unsigned2 u2x2_matmult_u2c(unsigned2x2 a, unsigned2 b) {
	return (unsigned2){{
		u2_dot((unsigned2){{ a.xx, a.yx }}, b),
		u2_dot((unsigned2){{ a.xy, a.yy }}, b),
	}};
}

LLAL_INLINE unsigned2 u2r_matmult_u2x2(unsigned2 a, unsigned2x2 b) {
	return (unsigned2){{
		u2_dot(a, b.x),
		u2_dot(a, b.y),
	}};
}

LLAL_INLINE unsigned2x2 u2x2_transpose(unsigned2x2 a) {
	return (unsigned2x2){
		.x = {{ a.xx, a.yx, }},
		.y = {{ a.xy, a.yy, }},
	};
}

LLAL_INLINE unsigned2x2 u2x2_scale(unsigned2 by) {
	unsigned2x2 mat = {0};
	mat.xx = by.x;
	mat.yy = by.y;
	return mat;
}


LLAL_INLINE float3x3 f3x3_identity(void) {
	return (float3x3){
		.x = {{ 1, 0, 0, }},
		.y = {{ 0, 1, 0, }},
		.z = {{ 0, 0, 1, }},
	};
}

LLAL_INLINE float3x3 f3x3_add(float3x3 a, float3x3 b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] += b.v[j].c[i];
	return a;
}

LLAL_INLINE float3x3 f3x3_add_f(float3x3 a, float b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] += b;
	return a;
}

LLAL_INLINE float3x3 f3x3_sub(float3x3 a, float3x3 b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] -= b.v[j].c[i];
	return a;
}

LLAL_INLINE float3x3 f3x3_sub_f(float3x3 a, float b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] -= b;
	return a;
}

LLAL_INLINE float3x3 f3x3_mul(float3x3 a, float3x3 b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] *= b.v[j].c[i];
	return a;
}

LLAL_INLINE float3x3 f3x3_mul_f(float3x3 a, float b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] *= b;
	return a;
}

LLAL_INLINE float3x3 f3x3_div(float3x3 a, float3x3 b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] /= b.v[j].c[i];
	return a;
}

LLAL_INLINE float3x3 f3x3_div_f(float3x3 a, float b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] /= b;
	return a;
}

LLAL_INLINE float f3x3_clesce_sum(float3x3 a) {
	return (
		f3_clesce_sum(a.x) +
		f3_clesce_sum(a.y) +
		f3_clesce_sum(a.z)
	);
}

LLAL_INLINE float f3x3_clesce_product(float3x3 a) {
	return (
		f3_clesce_product(a.x) *
		f3_clesce_product(a.y) *
		f3_clesce_product(a.z)
	);
}

LLAL_INLINE float f3x3_clesce_min(float3x3 a) {
	return f3_clesce_min(f3_ctor_fff(
		f3_clesce_min(a.x),
		f3_clesce_min(a.y),
		f3_clesce_min(a.z)
	));
}

LLAL_INLINE float f3x3_clesce_max(float3x3 a) {
	return f3_clesce_max(f3_ctor_fff(
		f3_clesce_max(a.x),
		f3_clesce_max(a.y),
		f3_clesce_max(a.z)
	));
}

LLAL_INLINE float3x3 f3x3_matmult_f3x3(float3x3 a, float3x3 b) {
	float3x3 c = {0};
	for (unsigned j = 0; j < 3; j++) {
		for (unsigned i = 0; i < 3; i++) {
			for (unsigned k = 0; k < 3; k++) {
				c.v[j].c[i] += a.v[k].c[i]*b.v[j].c[k];
			}
		}
	}
	return c;
}

LLAL_INLINE float3 f3x3_matmult_f3c(float3x3 a, float3 b) {
	return (float3){{
		f3_dot((float3){{ a.xx, a.yx, a.zx }}, b),
		f3_dot((float3){{ a.xy, a.yy, a.zy }}, b),
		f3_dot((float3){{ a.xz, a.yz, a.zz }}, b),
	}};
}

LLAL_INLINE float3 f3r_matmult_f3x3(float3 a, float3x3 b) {
	return (float3){{
		f3_dot(a, b.x),
		f3_dot(a, b.y),
		f3_dot(a, b.z),
	}};
}

LLAL_INLINE float3x3 f3x3_transpose(float3x3 a) {
	return (float3x3){
		.x = {{ a.xx, a.yx, a.zx, }},
		.y = {{ a.xy, a.yy, a.zy, }},
		.z = {{ a.xz, a.yz, a.zz, }},
	};
}

LLAL_INLINE float3x3 f3x3_scale(float3 by) {
	float3x3 mat = {0};
	mat.xx = by.x;
	mat.yy = by.y;
	mat.zz = by.z;
	return mat;
}

LLAL_INLINE float3x3 f3x3_rotate(float angle, float3 axis) {
	float cosangle = cosf(angle);
	float sinangle = sinf(angle);
	float3x3 mat = {
		.x = {{ axis.x*axis.x*(1.0f-cosangle), axis.x*axis.y*(1.0f-cosangle), axis.x*axis.z*(1.0f-cosangle), }},
		.y = {{ axis.y*axis.x*(1.0f-cosangle), axis.y*axis.y*(1.0f-cosangle), axis.y*axis.z*(1.0f-cosangle), }},
		.z = {{ axis.z*axis.x*(1.0f-cosangle), axis.z*axis.y*(1.0f-cosangle), axis.z*axis.z*(1.0f-cosangle), }},
	};
	return f3x3_add(mat, (float3x3){
		.x = {{         cosangle,  axis.z*sinangle, -axis.y*sinangle, }},
		.y = {{ -axis.z*sinangle,         cosangle,  axis.x*sinangle, }},
		.z = {{  axis.y*sinangle, -axis.x*sinangle,         cosangle, }},
	});
}


LLAL_INLINE double3x3 d3x3_identity(void) {
	return (double3x3){
		.x = {{ 1, 0, 0, }},
		.y = {{ 0, 1, 0, }},
		.z = {{ 0, 0, 1, }},
	};
}

LLAL_INLINE double3x3 d3x3_add(double3x3 a, double3x3 b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] += b.v[j].c[i];
	return a;
}

LLAL_INLINE double3x3 d3x3_add_d(double3x3 a, double b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] += b;
	return a;
}

LLAL_INLINE double3x3 d3x3_sub(double3x3 a, double3x3 b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] -= b.v[j].c[i];
	return a;
}

LLAL_INLINE double3x3 d3x3_sub_d(double3x3 a, double b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] -= b;
	return a;
}

LLAL_INLINE double3x3 d3x3_mul(double3x3 a, double3x3 b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] *= b.v[j].c[i];
	return a;
}

LLAL_INLINE double3x3 d3x3_mul_d(double3x3 a, double b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] *= b;
	return a;
}

LLAL_INLINE double3x3 d3x3_div(double3x3 a, double3x3 b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] /= b.v[j].c[i];
	return a;
}

LLAL_INLINE double3x3 d3x3_div_d(double3x3 a, double b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] /= b;
	return a;
}

LLAL_INLINE double d3x3_clesce_sum(double3x3 a) {
	return (
		d3_clesce_sum(a.x) +
		d3_clesce_sum(a.y) +
		d3_clesce_sum(a.z)
	);
}

LLAL_INLINE double d3x3_clesce_product(double3x3 a) {
	return (
		d3_clesce_product(a.x) *
		d3_clesce_product(a.y) *
		d3_clesce_product(a.z)
	);
}

LLAL_INLINE double d3x3_clesce_min(double3x3 a) {
	return d3_clesce_min(d3_ctor_ddd(
		d3_clesce_min(a.x),
		d3_clesce_min(a.y),
		d3_clesce_min(a.z)
	));
}

LLAL_INLINE double d3x3_clesce_max(double3x3 a) {
	return d3_clesce_max(d3_ctor_ddd(
		d3_clesce_max(a.x),
		d3_clesce_max(a.y),
		d3_clesce_max(a.z)
	));
}

LLAL_INLINE double3x3 d3x3_matmult_d3x3(double3x3 a, double3x3 b) {
	double3x3 c = {0};
	for (unsigned j = 0; j < 3; j++) {
		for (unsigned i = 0; i < 3; i++) {
			for (unsigned k = 0; k < 3; k++) {
				c.v[j].c[i] += a.v[k].c[i]*b.v[j].c[k];
			}
		}
	}
	return c;
}

LLAL_INLINE double3 d3x3_matmult_d3c(double3x3 a, double3 b) {
	return (double3){{
		d3_dot((double3){{ a.xx, a.yx, a.zx }}, b),
		d3_dot((double3){{ a.xy, a.yy, a.zy }}, b),
		d3_dot((double3){{ a.xz, a.yz, a.zz }}, b),
	}};
}

LLAL_INLINE double3 d3r_matmult_d3x3(double3 a, double3x3 b) {
	return (double3){{
		d3_dot(a, b.x),
		d3_dot(a, b.y),
		d3_dot(a, b.z),
	}};
}

LLAL_INLINE double3x3 d3x3_transpose(double3x3 a) {
	return (double3x3){
		.x = {{ a.xx, a.yx, a.zx, }},
		.y = {{ a.xy, a.yy, a.zy, }},
		.z = {{ a.xz, a.yz, a.zz, }},
	};
}

LLAL_INLINE double3x3 d3x3_scale(double3 by) {
	double3x3 mat = {0};
	mat.xx = by.x;
	mat.yy = by.y;
	mat.zz = by.z;
	return mat;
}

LLAL_INLINE double3x3 d3x3_rotate(double angle, double3 axis) {
	double cosangle = cos(angle);
	double sinangle = sin(angle);
	double3x3 mat = {
		.x = {{ axis.x*axis.x*(1.0-cosangle), axis.x*axis.y*(1.0-cosangle), axis.x*axis.z*(1.0-cosangle), }},
		.y = {{ axis.y*axis.x*(1.0-cosangle), axis.y*axis.y*(1.0-cosangle), axis.y*axis.z*(1.0-cosangle), }},
		.z = {{ axis.z*axis.x*(1.0-cosangle), axis.z*axis.y*(1.0-cosangle), axis.z*axis.z*(1.0-cosangle), }},
	};
	return d3x3_add(mat, (double3x3){
		.x = {{         cosangle,  axis.z*sinangle, -axis.y*sinangle, }},
		.y = {{ -axis.z*sinangle,         cosangle,  axis.x*sinangle, }},
		.z = {{  axis.y*sinangle, -axis.x*sinangle,         cosangle, }},
	});
}


LLAL_INLINE int3x3 i3x3_identity(void) {
	return (int3x3){
		.x = {{ 1, 0, 0, }},
		.y = {{ 0, 1, 0, }},
		.z = {{ 0, 0, 1, }},
	};
}

LLAL_INLINE int3x3 i3x3_add(int3x3 a, int3x3 b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] += b.v[j].c[i];
	return a;
}

LLAL_INLINE int3x3 i3x3_add_i(int3x3 a, int b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] += b;
	return a;
}

LLAL_INLINE int3x3 i3x3_sub(int3x3 a, int3x3 b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] -= b.v[j].c[i];
	return a;
}

LLAL_INLINE int3x3 i3x3_sub_i(int3x3 a, int b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] -= b;
	return a;
}

LLAL_INLINE int3x3 i3x3_mul(int3x3 a, int3x3 b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] *= b.v[j].c[i];
	return a;
}

LLAL_INLINE int3x3 i3x3_mul_i(int3x3 a, int b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] *= b;
	return a;
}

LLAL_INLINE int3x3 i3x3_div(int3x3 a, int3x3 b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] /= b.v[j].c[i];
	return a;
}

LLAL_INLINE int3x3 i3x3_div_i(int3x3 a, int b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] /= b;
	return a;
}

LLAL_INLINE int i3x3_clesce_sum(int3x3 a) {
	return (
		i3_clesce_sum(a.x) +
		i3_clesce_sum(a.y) +
		i3_clesce_sum(a.z)
	);
}

LLAL_INLINE int i3x3_clesce_product(int3x3 a) {
	return (
		i3_clesce_product(a.x) *
		i3_clesce_product(a.y) *
		i3_clesce_product(a.z)
	);
}

LLAL_INLINE int i3x3_clesce_min(int3x3 a) {
	return i3_clesce_min(i3_ctor_iii(
		i3_clesce_min(a.x),
		i3_clesce_min(a.y),
		i3_clesce_min(a.z)
	));
}

LLAL_INLINE int i3x3_clesce_max(int3x3 a) {
	return i3_clesce_max(i3_ctor_iii(
		i3_clesce_max(a.x),
		i3_clesce_max(a.y),
		i3_clesce_max(a.z)
	));
}

LLAL_INLINE int3x3 i3x3_matmult_i3x3(int3x3 a, int3x3 b) {
	int3x3 c = {0};
	for (unsigned j = 0; j < 3; j++) {
		for (unsigned i = 0; i < 3; i++) {
			for (unsigned k = 0; k < 3; k++) {
				c.v[j].c[i] += a.v[k].c[i]*b.v[j].c[k];
			}
		}
	}
	return c;
}

LLAL_INLINE int3 i3x3_matmult_i3c(int3x3 a, int3 b) {
	return (int3){{
		i3_dot((int3){{ a.xx, a.yx, a.zx }}, b),
		i3_dot((int3){{ a.xy, a.yy, a.zy }}, b),
		i3_dot((int3){{ a.xz, a.yz, a.zz }}, b),
	}};
}

LLAL_INLINE int3 i3r_matmult_i3x3(int3 a, int3x3 b) {
	return (int3){{
		i3_dot(a, b.x),
		i3_dot(a, b.y),
		i3_dot(a, b.z),
	}};
}

LLAL_INLINE int3x3 i3x3_transpose(int3x3 a) {
	return (int3x3){
		.x = {{ a.xx, a.yx, a.zx, }},
		.y = {{ a.xy, a.yy, a.zy, }},
		.z = {{ a.xz, a.yz, a.zz, }},
	};
}

LLAL_INLINE int3x3 i3x3_scale(int3 by) {
	int3x3 mat = {0};
	mat.xx = by.x;
	mat.yy = by.y;
	mat.zz = by.z;
	return mat;
}


LLAL_INLINE unsigned3x3 u3x3_identity(void) {
	return (unsigned3x3){
		.x = {{ 1, 0, 0, }},
		.y = {{ 0, 1, 0, }},
		.z = {{ 0, 0, 1, }},
	};
}

LLAL_INLINE unsigned3x3 u3x3_add(unsigned3x3 a, unsigned3x3 b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] += b.v[j].c[i];
	return a;
}

LLAL_INLINE unsigned3x3 u3x3_add_u(unsigned3x3 a, unsigned b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] += b;
	return a;
}

LLAL_INLINE unsigned3x3 u3x3_sub(unsigned3x3 a, unsigned3x3 b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] -= b.v[j].c[i];
	return a;
}

LLAL_INLINE unsigned3x3 u3x3_sub_u(unsigned3x3 a, unsigned b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] -= b;
	return a;
}

LLAL_INLINE unsigned3x3 u3x3_mul(unsigned3x3 a, unsigned3x3 b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] *= b.v[j].c[i];
	return a;
}

LLAL_INLINE unsigned3x3 u3x3_mul_u(unsigned3x3 a, unsigned b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] *= b;
	return a;
}

LLAL_INLINE unsigned3x3 u3x3_div(unsigned3x3 a, unsigned3x3 b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] /= b.v[j].c[i];
	return a;
}

LLAL_INLINE unsigned3x3 u3x3_div_u(unsigned3x3 a, unsigned b) {
	for (unsigned j = 0; j < 3; j++)
		for (unsigned i = 0; i < 3; i++)
			a.v[j].c[i] /= b;
	return a;
}

LLAL_INLINE unsigned u3x3_clesce_sum(unsigned3x3 a) {
	return (
		u3_clesce_sum(a.x) +
		u3_clesce_sum(a.y) +
		u3_clesce_sum(a.z)
	);
}

LLAL_INLINE unsigned u3x3_clesce_product(unsigned3x3 a) {
	return (
		u3_clesce_product(a.x) *
		u3_clesce_product(a.y) *
		u3_clesce_product(a.z)
	);
}

LLAL_INLINE unsigned u3x3_clesce_min(unsigned3x3 a) {
	return u3_clesce_min(u3_ctor_uuu(
		u3_clesce_min(a.x),
		u3_clesce_min(a.y),
		u3_clesce_min(a.z)
	));
}

LLAL_INLINE unsigned u3x3_clesce_max(unsigned3x3 a) {
	return u3_clesce_max(u3_ctor_uuu(
		u3_clesce_max(a.x),
		u3_clesce_max(a.y),
		u3_clesce_max(a.z)
	));
}

LLAL_INLINE unsigned3x3 u3x3_matmult_u3x3(unsigned3x3 a, unsigned3x3 b) {
	unsigned3x3 c = {0};
	for (unsigned j = 0; j < 3; j++) {
		for (unsigned i = 0; i < 3; i++) {
			for (unsigned k = 0; k < 3; k++) {
				c.v[j].c[i] += a.v[k].c[i]*b.v[j].c[k];
			}
		}
	}
	return c;
}

LLAL_INLINE unsigned3 u3x3_matmult_u3c(unsigned3x3 a, unsigned3 b) {
	return (unsigned3){{
		u3_dot((unsigned3){{ a.xx, a.yx, a.zx }}, b),
		u3_dot((unsigned3){{ a.xy, a.yy, a.zy }}, b),
		u3_dot((unsigned3){{ a.xz, a.yz, a.zz }}, b),
	}};
}

LLAL_INLINE unsigned3 u3r_matmult_u3x3(unsigned3 a, unsigned3x3 b) {
	return (unsigned3){{
		u3_dot(a, b.x),
		u3_dot(a, b.y),
		u3_dot(a, b.z),
	}};
}

LLAL_INLINE unsigned3x3 u3x3_transpose(unsigned3x3 a) {
	return (unsigned3x3){
		.x = {{ a.xx, a.yx, a.zx, }},
		.y = {{ a.xy, a.yy, a.zy, }},
		.z = {{ a.xz, a.yz, a.zz, }},
	};
}

LLAL_INLINE unsigned3x3 u3x3_scale(unsigned3 by) {
	unsigned3x3 mat = {0};
	mat.xx = by.x;
	mat.yy = by.y;
	mat.zz = by.z;
	return mat;
}


LLAL_INLINE float4x4 f4x4_identity(void) {
	return (float4x4){
		.x = {{ 1, 0, 0, 0, }},
		.y = {{ 0, 1, 0, 0, }},
		.z = {{ 0, 0, 1, 0, }},
		.w = {{ 0, 0, 0, 1, }},
	};
}

LLAL_INLINE float4x4 f4x4_add(float4x4 a, float4x4 b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] += b.v[j].c[i];
	return a;
}

LLAL_INLINE float4x4 f4x4_add_f(float4x4 a, float b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] += b;
	return a;
}

LLAL_INLINE float4x4 f4x4_sub(float4x4 a, float4x4 b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] -= b.v[j].c[i];
	return a;
}

LLAL_INLINE float4x4 f4x4_sub_f(float4x4 a, float b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] -= b;
	return a;
}

LLAL_INLINE float4x4 f4x4_mul(float4x4 a, float4x4 b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] *= b.v[j].c[i];
	return a;
}

LLAL_INLINE float4x4 f4x4_mul_f(float4x4 a, float b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] *= b;
	return a;
}

LLAL_INLINE float4x4 f4x4_div(float4x4 a, float4x4 b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] /= b.v[j].c[i];
	return a;
}

LLAL_INLINE float4x4 f4x4_div_f(float4x4 a, float b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] /= b;
	return a;
}

LLAL_INLINE float f4x4_clesce_sum(float4x4 a) {
	return (
		f4_clesce_sum(a.x) +
		f4_clesce_sum(a.y) +
		f4_clesce_sum(a.z) +
		f4_clesce_sum(a.w)
	);
}

LLAL_INLINE float f4x4_clesce_product(float4x4 a) {
	return (
		f4_clesce_product(a.x) *
		f4_clesce_product(a.y) *
		f4_clesce_product(a.z) *
		f4_clesce_product(a.w)
	);
}

LLAL_INLINE float f4x4_clesce_min(float4x4 a) {
	return f4_clesce_min(f4_ctor_ffff(
		f4_clesce_min(a.x),
		f4_clesce_min(a.y),
		f4_clesce_min(a.z),
		f4_clesce_min(a.w)
	));
}

LLAL_INLINE float f4x4_clesce_max(float4x4 a) {
	return f4_clesce_max(f4_ctor_ffff(
		f4_clesce_max(a.x),
		f4_clesce_max(a.y),
		f4_clesce_max(a.z),
		f4_clesce_max(a.w)
	));
}

LLAL_INLINE float4x4 f4x4_matmult_f4x4(float4x4 a, float4x4 b) {
	float4x4 c = {0};
	for (unsigned j = 0; j < 4; j++) {
		for (unsigned i = 0; i < 4; i++) {
			for (unsigned k = 0; k < 4; k++) {
				c.v[j].c[i] += a.v[k].c[i]*b.v[j].c[k];
			}
		}
	}
	return c;
}

LLAL_INLINE float4 f4x4_matmult_f4c(float4x4 a, float4 b) {
	return (float4){{
		f4_dot((float4){{ a.xx, a.yx, a.zx, a.wx }}, b),
		f4_dot((float4){{ a.xy, a.yy, a.zy, a.wy }}, b),
		f4_dot((float4){{ a.xz, a.yz, a.zz, a.wz }}, b),
		f4_dot((float4){{ a.xw, a.yw, a.zw, a.ww }}, b),
	}};
}

LLAL_INLINE float4 f4r_matmult_f4x4(float4 a, float4x4 b) {
	return (float4){{
		f4_dot(a, b.x),
		f4_dot(a, b.y),
		f4_dot(a, b.z),
		f4_dot(a, b.w),
	}};
}

LLAL_INLINE float4x4 f4x4_transpose(float4x4 a) {
	return (float4x4){
		.x = {{ a.xx, a.yx, a.zx, a.wx, }},
		.y = {{ a.xy, a.yy, a.zy, a.wy, }},
		.z = {{ a.xz, a.yz, a.zz, a.wz, }},
		.w = {{ a.xw, a.yw, a.zw, a.ww, }},
	};
}

LLAL_INLINE float4x4 f4x4_scale(float4 by) {
	float4x4 mat = {0};
	mat.xx = by.x;
	mat.yy = by.y;
	mat.zz = by.z;
	mat.ww = by.w;
	return mat;
}

LLAL_INLINE float4x4 f4x4_rotate(float angle, float3 axis) {
	float cosangle = cosf(angle);
	float sinangle = sinf(angle);
	float4x4 mat = {
		.x = {{ axis.x*axis.x*(1.0f-cosangle), axis.x*axis.y*(1.0f-cosangle), axis.x*axis.z*(1.0f-cosangle), 0.0f, }},
		.y = {{ axis.y*axis.x*(1.0f-cosangle), axis.y*axis.y*(1.0f-cosangle), axis.y*axis.z*(1.0f-cosangle), 0.0f, }},
		.z = {{ axis.z*axis.x*(1.0f-cosangle), axis.z*axis.y*(1.0f-cosangle), axis.z*axis.z*(1.0f-cosangle), 0.0f, }},
		.w = {{ 0.0f, 0.0f, 0.0f, 1.0f, }},
	};
	return f4x4_add(mat, (float4x4){
		.x = {{         cosangle,  axis.z*sinangle, -axis.y*sinangle, 0.0f, }},
		.y = {{ -axis.z*sinangle,         cosangle,  axis.x*sinangle, 0.0f, }},
		.z = {{  axis.y*sinangle, -axis.x*sinangle,         cosangle, 0.0f, }},
		.w = {{ 0.0f, 0.0f, 0.0f, 0.0f, }},
	});
}

LLAL_INLINE float4x4 f4x4_translate(float3 by) {
	float4x4 mat = {0};
	mat.xx = 1.0;
	mat.yy = 1.0;
	mat.zz = 1.0;
	mat.w = (float4){{ by.x, by.y, by.z, 1.0 }};
	return mat;
}


LLAL_INLINE double4x4 d4x4_identity(void) {
	return (double4x4){
		.x = {{ 1, 0, 0, 0, }},
		.y = {{ 0, 1, 0, 0, }},
		.z = {{ 0, 0, 1, 0, }},
		.w = {{ 0, 0, 0, 1, }},
	};
}

LLAL_INLINE double4x4 d4x4_add(double4x4 a, double4x4 b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] += b.v[j].c[i];
	return a;
}

LLAL_INLINE double4x4 d4x4_add_d(double4x4 a, double b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] += b;
	return a;
}

LLAL_INLINE double4x4 d4x4_sub(double4x4 a, double4x4 b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] -= b.v[j].c[i];
	return a;
}

LLAL_INLINE double4x4 d4x4_sub_d(double4x4 a, double b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] -= b;
	return a;
}

LLAL_INLINE double4x4 d4x4_mul(double4x4 a, double4x4 b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] *= b.v[j].c[i];
	return a;
}

LLAL_INLINE double4x4 d4x4_mul_d(double4x4 a, double b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] *= b;
	return a;
}

LLAL_INLINE double4x4 d4x4_div(double4x4 a, double4x4 b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] /= b.v[j].c[i];
	return a;
}

LLAL_INLINE double4x4 d4x4_div_d(double4x4 a, double b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] /= b;
	return a;
}

LLAL_INLINE double d4x4_clesce_sum(double4x4 a) {
	return (
		d4_clesce_sum(a.x) +
		d4_clesce_sum(a.y) +
		d4_clesce_sum(a.z) +
		d4_clesce_sum(a.w)
	);
}

LLAL_INLINE double d4x4_clesce_product(double4x4 a) {
	return (
		d4_clesce_product(a.x) *
		d4_clesce_product(a.y) *
		d4_clesce_product(a.z) *
		d4_clesce_product(a.w)
	);
}

LLAL_INLINE double d4x4_clesce_min(double4x4 a) {
	return d4_clesce_min(d4_ctor_dddd(
		d4_clesce_min(a.x),
		d4_clesce_min(a.y),
		d4_clesce_min(a.z),
		d4_clesce_min(a.w)
	));
}

LLAL_INLINE double d4x4_clesce_max(double4x4 a) {
	return d4_clesce_max(d4_ctor_dddd(
		d4_clesce_max(a.x),
		d4_clesce_max(a.y),
		d4_clesce_max(a.z),
		d4_clesce_max(a.w)
	));
}

LLAL_INLINE double4x4 d4x4_matmult_d4x4(double4x4 a, double4x4 b) {
	double4x4 c = {0};
	for (unsigned j = 0; j < 4; j++) {
		for (unsigned i = 0; i < 4; i++) {
			for (unsigned k = 0; k < 4; k++) {
				c.v[j].c[i] += a.v[k].c[i]*b.v[j].c[k];
			}
		}
	}
	return c;
}

LLAL_INLINE double4 d4x4_matmult_d4c(double4x4 a, double4 b) {
	return (double4){{
		d4_dot((double4){{ a.xx, a.yx, a.zx, a.wx }}, b),
		d4_dot((double4){{ a.xy, a.yy, a.zy, a.wy }}, b),
		d4_dot((double4){{ a.xz, a.yz, a.zz, a.wz }}, b),
		d4_dot((double4){{ a.xw, a.yw, a.zw, a.ww }}, b),
	}};
}

LLAL_INLINE double4 d4r_matmult_d4x4(double4 a, double4x4 b) {
	return (double4){{
		d4_dot(a, b.x),
		d4_dot(a, b.y),
		d4_dot(a, b.z),
		d4_dot(a, b.w),
	}};
}

LLAL_INLINE double4x4 d4x4_transpose(double4x4 a) {
	return (double4x4){
		.x = {{ a.xx, a.yx, a.zx, a.wx, }},
		.y = {{ a.xy, a.yy, a.zy, a.wy, }},
		.z = {{ a.xz, a.yz, a.zz, a.wz, }},
		.w = {{ a.xw, a.yw, a.zw, a.ww, }},
	};
}

LLAL_INLINE double4x4 d4x4_scale(double4 by) {
	double4x4 mat = {0};
	mat.xx = by.x;
	mat.yy = by.y;
	mat.zz = by.z;
	mat.ww = by.w;
	return mat;
}

LLAL_INLINE double4x4 d4x4_rotate(double angle, double3 axis) {
	double cosangle = cos(angle);
	double sinangle = sin(angle);
	double4x4 mat = {
		.x = {{ axis.x*axis.x*(1.0-cosangle), axis.x*axis.y*(1.0-cosangle), axis.x*axis.z*(1.0-cosangle), 0.0, }},
		.y = {{ axis.y*axis.x*(1.0-cosangle), axis.y*axis.y*(1.0-cosangle), axis.y*axis.z*(1.0-cosangle), 0.0, }},
		.z = {{ axis.z*axis.x*(1.0-cosangle), axis.z*axis.y*(1.0-cosangle), axis.z*axis.z*(1.0-cosangle), 0.0, }},
		.w = {{ 0.0, 0.0, 0.0, 1.0, }},
	};
	return d4x4_add(mat, (double4x4){
		.x = {{         cosangle,  axis.z*sinangle, -axis.y*sinangle, 0.0, }},
		.y = {{ -axis.z*sinangle,         cosangle,  axis.x*sinangle, 0.0, }},
		.z = {{  axis.y*sinangle, -axis.x*sinangle,         cosangle, 0.0, }},
		.w = {{ 0.0, 0.0, 0.0, 0.0, }},
	});
}

LLAL_INLINE double4x4 d4x4_translate(double3 by) {
	double4x4 mat = {0};
	mat.xx = 1.0;
	mat.yy = 1.0;
	mat.zz = 1.0;
	mat.w = (double4){{ by.x, by.y, by.z, 1.0 }};
	return mat;
}


LLAL_INLINE int4x4 i4x4_identity(void) {
	return (int4x4){
		.x = {{ 1, 0, 0, 0, }},
		.y = {{ 0, 1, 0, 0, }},
		.z = {{ 0, 0, 1, 0, }},
		.w = {{ 0, 0, 0, 1, }},
	};
}

LLAL_INLINE int4x4 i4x4_add(int4x4 a, int4x4 b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] += b.v[j].c[i];
	return a;
}

LLAL_INLINE int4x4 i4x4_add_i(int4x4 a, int b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] += b;
	return a;
}

LLAL_INLINE int4x4 i4x4_sub(int4x4 a, int4x4 b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] -= b.v[j].c[i];
	return a;
}

LLAL_INLINE int4x4 i4x4_sub_i(int4x4 a, int b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] -= b;
	return a;
}

LLAL_INLINE int4x4 i4x4_mul(int4x4 a, int4x4 b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] *= b.v[j].c[i];
	return a;
}

LLAL_INLINE int4x4 i4x4_mul_i(int4x4 a, int b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] *= b;
	return a;
}

LLAL_INLINE int4x4 i4x4_div(int4x4 a, int4x4 b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] /= b.v[j].c[i];
	return a;
}

LLAL_INLINE int4x4 i4x4_div_i(int4x4 a, int b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] /= b;
	return a;
}

LLAL_INLINE int i4x4_clesce_sum(int4x4 a) {
	return (
		i4_clesce_sum(a.x) +
		i4_clesce_sum(a.y) +
		i4_clesce_sum(a.z) +
		i4_clesce_sum(a.w)
	);
}

LLAL_INLINE int i4x4_clesce_product(int4x4 a) {
	return (
		i4_clesce_product(a.x) *
		i4_clesce_product(a.y) *
		i4_clesce_product(a.z) *
		i4_clesce_product(a.w)
	);
}

LLAL_INLINE int i4x4_clesce_min(int4x4 a) {
	return i4_clesce_min(i4_ctor_iiii(
		i4_clesce_min(a.x),
		i4_clesce_min(a.y),
		i4_clesce_min(a.z),
		i4_clesce_min(a.w)
	));
}

LLAL_INLINE int i4x4_clesce_max(int4x4 a) {
	return i4_clesce_max(i4_ctor_iiii(
		i4_clesce_max(a.x),
		i4_clesce_max(a.y),
		i4_clesce_max(a.z),
		i4_clesce_max(a.w)
	));
}

LLAL_INLINE int4x4 i4x4_matmult_i4x4(int4x4 a, int4x4 b) {
	int4x4 c = {0};
	for (unsigned j = 0; j < 4; j++) {
		for (unsigned i = 0; i < 4; i++) {
			for (unsigned k = 0; k < 4; k++) {
				c.v[j].c[i] += a.v[k].c[i]*b.v[j].c[k];
			}
		}
	}
	return c;
}

LLAL_INLINE int4 i4x4_matmult_i4c(int4x4 a, int4 b) {
	return (int4){{
		i4_dot((int4){{ a.xx, a.yx, a.zx, a.wx }}, b),
		i4_dot((int4){{ a.xy, a.yy, a.zy, a.wy }}, b),
		i4_dot((int4){{ a.xz, a.yz, a.zz, a.wz }}, b),
		i4_dot((int4){{ a.xw, a.yw, a.zw, a.ww }}, b),
	}};
}

LLAL_INLINE int4 i4r_matmult_i4x4(int4 a, int4x4 b) {
	return (int4){{
		i4_dot(a, b.x),
		i4_dot(a, b.y),
		i4_dot(a, b.z),
		i4_dot(a, b.w),
	}};
}

LLAL_INLINE int4x4 i4x4_transpose(int4x4 a) {
	return (int4x4){
		.x = {{ a.xx, a.yx, a.zx, a.wx, }},
		.y = {{ a.xy, a.yy, a.zy, a.wy, }},
		.z = {{ a.xz, a.yz, a.zz, a.wz, }},
		.w = {{ a.xw, a.yw, a.zw, a.ww, }},
	};
}

LLAL_INLINE int4x4 i4x4_scale(int4 by) {
	int4x4 mat = {0};
	mat.xx = by.x;
	mat.yy = by.y;
	mat.zz = by.z;
	mat.ww = by.w;
	return mat;
}

LLAL_INLINE int4x4 i4x4_translate(int3 by) {
	int4x4 mat = {0};
	mat.xx = 1.0;
	mat.yy = 1.0;
	mat.zz = 1.0;
	mat.w = (int4){{ by.x, by.y, by.z, 1.0 }};
	return mat;
}


LLAL_INLINE unsigned4x4 u4x4_identity(void) {
	return (unsigned4x4){
		.x = {{ 1, 0, 0, 0, }},
		.y = {{ 0, 1, 0, 0, }},
		.z = {{ 0, 0, 1, 0, }},
		.w = {{ 0, 0, 0, 1, }},
	};
}

LLAL_INLINE unsigned4x4 u4x4_add(unsigned4x4 a, unsigned4x4 b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] += b.v[j].c[i];
	return a;
}

LLAL_INLINE unsigned4x4 u4x4_add_u(unsigned4x4 a, unsigned b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] += b;
	return a;
}

LLAL_INLINE unsigned4x4 u4x4_sub(unsigned4x4 a, unsigned4x4 b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] -= b.v[j].c[i];
	return a;
}

LLAL_INLINE unsigned4x4 u4x4_sub_u(unsigned4x4 a, unsigned b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] -= b;
	return a;
}

LLAL_INLINE unsigned4x4 u4x4_mul(unsigned4x4 a, unsigned4x4 b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] *= b.v[j].c[i];
	return a;
}

LLAL_INLINE unsigned4x4 u4x4_mul_u(unsigned4x4 a, unsigned b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] *= b;
	return a;
}

LLAL_INLINE unsigned4x4 u4x4_div(unsigned4x4 a, unsigned4x4 b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] /= b.v[j].c[i];
	return a;
}

LLAL_INLINE unsigned4x4 u4x4_div_u(unsigned4x4 a, unsigned b) {
	for (unsigned j = 0; j < 4; j++)
		for (unsigned i = 0; i < 4; i++)
			a.v[j].c[i] /= b;
	return a;
}

LLAL_INLINE unsigned u4x4_clesce_sum(unsigned4x4 a) {
	return (
		u4_clesce_sum(a.x) +
		u4_clesce_sum(a.y) +
		u4_clesce_sum(a.z) +
		u4_clesce_sum(a.w)
	);
}

LLAL_INLINE unsigned u4x4_clesce_product(unsigned4x4 a) {
	return (
		u4_clesce_product(a.x) *
		u4_clesce_product(a.y) *
		u4_clesce_product(a.z) *
		u4_clesce_product(a.w)
	);
}

LLAL_INLINE unsigned u4x4_clesce_min(unsigned4x4 a) {
	return u4_clesce_min(u4_ctor_uuuu(
		u4_clesce_min(a.x),
		u4_clesce_min(a.y),
		u4_clesce_min(a.z),
		u4_clesce_min(a.w)
	));
}

LLAL_INLINE unsigned u4x4_clesce_max(unsigned4x4 a) {
	return u4_clesce_max(u4_ctor_uuuu(
		u4_clesce_max(a.x),
		u4_clesce_max(a.y),
		u4_clesce_max(a.z),
		u4_clesce_max(a.w)
	));
}

LLAL_INLINE unsigned4x4 u4x4_matmult_u4x4(unsigned4x4 a, unsigned4x4 b) {
	unsigned4x4 c = {0};
	for (unsigned j = 0; j < 4; j++) {
		for (unsigned i = 0; i < 4; i++) {
			for (unsigned k = 0; k < 4; k++) {
				c.v[j].c[i] += a.v[k].c[i]*b.v[j].c[k];
			}
		}
	}
	return c;
}

LLAL_INLINE unsigned4 u4x4_matmult_u4c(unsigned4x4 a, unsigned4 b) {
	return (unsigned4){{
		u4_dot((unsigned4){{ a.xx, a.yx, a.zx, a.wx }}, b),
		u4_dot((unsigned4){{ a.xy, a.yy, a.zy, a.wy }}, b),
		u4_dot((unsigned4){{ a.xz, a.yz, a.zz, a.wz }}, b),
		u4_dot((unsigned4){{ a.xw, a.yw, a.zw, a.ww }}, b),
	}};
}

LLAL_INLINE unsigned4 u4r_matmult_u4x4(unsigned4 a, unsigned4x4 b) {
	return (unsigned4){{
		u4_dot(a, b.x),
		u4_dot(a, b.y),
		u4_dot(a, b.z),
		u4_dot(a, b.w),
	}};
}

LLAL_INLINE unsigned4x4 u4x4_transpose(unsigned4x4 a) {
	return (unsigned4x4){
		.x = {{ a.xx, a.yx, a.zx, a.wx, }},
		.y = {{ a.xy, a.yy, a.zy, a.wy, }},
		.z = {{ a.xz, a.yz, a.zz, a.wz, }},
		.w = {{ a.xw, a.yw, a.zw, a.ww, }},
	};
}

LLAL_INLINE unsigned4x4 u4x4_scale(unsigned4 by) {
	unsigned4x4 mat = {0};
	mat.xx = by.x;
	mat.yy = by.y;
	mat.zz = by.z;
	mat.ww = by.w;
	return mat;
}

LLAL_INLINE unsigned4x4 u4x4_translate(unsigned3 by) {
	unsigned4x4 mat = {0};
	mat.xx = 1.0;
	mat.yy = 1.0;
	mat.zz = 1.0;
	mat.w = (unsigned4){{ by.x, by.y, by.z, 1.0 }};
	return mat;
}

#endif // ifdef LLAL_IMPLEMENTATION
#endif // ifndef LLAL_H