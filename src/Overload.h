#pragma once
#include "Vector2.h"
#include "Matrix3x3.h"
#include "Utility.h"

inline Vector2 operator+(const Vector2& v1, const Vector2& v2) {
	return { v1.x + v2.x , v1.y + v2.y };
}
inline Vector2 operator*(const Vector2& v1, const Vector2& v2) {
	return { v1.x * v2.x , v1.y * v2.y };
}
inline Vector2 operator-(const Vector2& v1, const Vector2& v2) {
	return { v1.x - v2.x , v1.y - v2.y };
}
inline Vector2 operator*(const Vector2& v, float s) {
	return { v.x * s, v.y * s };
}
inline Vector2 operator*(float s, const Vector2& v) {
	return { v.x * s, v.y * s };
}

inline Vector2 operator*(const Matrix3& m, const Vector2& v) {
	return{
		m.Xx * v.x + m.Xy * v.y + m.Tx,
		m.Yx * v.x + m.Yy * v.y + m.Ty
	};
}

inline Vector2 operator*(const Vector2& v, const Matrix3& m) {
	return{
		m.Xx * v.x + m.Xy * v.y + m.Tx,
		m.Yx * v.x + m.Yy * v.y + m.Ty
	};
}

inline Matrix3 operator*(const Matrix3& a, const Matrix3& b) {
	Matrix3 r;

	r.Xx = a.Xx * b.Xx + a.Yx * b.Xy;//1
	r.Yx = a.Xx * b.Yx + a.Yx * b.Yy;//2
	r.Tx = a.Xx * b.Tx + a.Yx * b.Ty + a.Tx;

	r.Xy = a.Xy * b.Xx + a.Yy * b.Xy;
	r.Yy = a.Xy * b.Yx + a.Yy * b.Yy;
	r.Ty = a.Xy * b.Tx + a.Yy * b.Ty + a.Ty;

	r.m0 = 0.0f;
	r.m1 = 0.0f;
	r.m2 = 1.0f;

	return r;
}
