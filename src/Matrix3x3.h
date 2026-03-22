#pragma once
#ifdef __cplusplus
#include <math.h>
#include "Utility.h"
extern "C" {
#endif

    typedef union {
        struct {
            float Xx, Yx, Tx;
            float Xy, Yy, Ty;
            float m0, m1, m2;
        };
        float m[3][3];
        float v[9];
    } Matrix3;


inline float M3_Determinant(const Matrix3 &m) {
    return (m.Xx * m.Yy) - (m.Yx * m.Xy);
}
inline float M3_Trace(const Matrix3& m) {
    return m.Xx + m.Yy + m.m2;
}


inline Matrix3 M3_Invert(const Matrix3 &mat) {

    Matrix3 inv = M3_IdentityStart();
    float det = M3_Determinant(mat);

    if (det <= 0.000001f) return mat; 

    float invDet = 1.0f / det;

    inv.Xx = mat.Yy * invDet;
    inv.Yx = -mat.Yx * invDet;
    inv.Xy = -mat.Xy * invDet;
    inv.Yy = mat.Xx * invDet;

    inv.Tx = -(inv.Xx * mat.Tx + inv.Yx * mat.Ty);
    inv.Ty = -(inv.Xy * mat.Tx + inv.Yy * mat.Ty);

    inv.m0 = 0.0f;
    inv.m1 = 0.0f;
    inv.m2 = 1.0f;

    return inv;
}
Matrix3 M3_IdentityStart(void) {
    Matrix3 mat;
    mat.Xx = 1.0f; mat.Yx = 0.0f; mat.Tx = 0.0f;
    mat.Xy = 0.0f; mat.Yy = 1.0f; mat.Ty = 0.0f;
    mat.m0 = 0.0f; mat.m1 = 0.0f; mat.m2 = 1.0f;
    return mat;
}
Matrix3 M3_Add(const Matrix3& M3left, const Matrix3& M3right) {
    Matrix3 result = M3_IdentityStart();
    for (int i = 0; i < 9; i++)
    {
        result.v[i] = M3left.v[i] + M3right.v[i];
    }
    return result;
}

Matrix3 M3_Subtract(const Matrix3& M3left, const Matrix3& M3right) {
    Matrix3 result = M3_IdentityStart();
    for (int i = 0; i < 9; i++)
    {
        result.v[i] += M3left.v[i] - M3right.v[i];
    }
    return result;
}

Matrix3 M3_Multiply(const Matrix3& M3left, const Matrix3& M3right) {
    Matrix3 result = M3_IdentityStart();

    result.Xx = M3left.Xx * M3right.Xx + M3left.Yx * M3right.Xy;//1
    result.Yx = M3left.Xx * M3right.Yx + M3left.Yx * M3right.Yy;//2
    result.Tx = M3left.Xx * M3right.Tx + M3left.Yx * M3right.Ty + M3left.Tx;

    result.Xy = M3left.Xy * M3right.Xx + M3left.Yy * M3right.Xy;
    result.Yy = M3left.Xy * M3right.Yx + M3left.Yy * M3right.Yy;
    result.Ty = M3left.Xy * M3right.Tx + M3left.Yy * M3right.Ty + M3left.Ty;

    result.m0 = 0.0f;
    result.m1 = 0.0f;
    result.m2 = 1.0f;

    return result;
}

Matrix3 M3_Transform(float x, float y) {
    Matrix3 Tm = M3_IdentityStart();
    Tm.Tx = x;
    Tm.Ty = y;
    return Tm;
};

Matrix3 M3_Rotate(float angle) {
    Matrix3 mat = M3_IdentityStart();

    float c = cosf(angle);
    float s = sinf(angle);

    mat.Xx = c;   mat.Yx = -s;   mat.Tx = 0.0f;
    mat.Xy = s;   mat.Yy = c;   mat.Ty = 0.0f;
    mat.m0 = 0.0f; mat.m1 = 0.0f; mat.m2 = 1.0f;

    return mat;
};
Matrix3 M3_Scale(float x, float y) {
    Matrix3 Tm = M3_IdentityStart();

    Tm.Xx *= x;
    Tm.Yy *= y;

    return Tm;
};

#ifdef __cplusplus
}
#endif
