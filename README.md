# VecMat2D

A lightweight 2D math library for vectors and matrices in C/C++.

This repository contains utilities for Vector2 and 3×3 Matrix transforms with operator overloads for C++ and C‑compatible interfaces for working in both C and C++ codebases.

------

Include the headers in your C++ project:

#include "include/config.h"

-------------                                                
Matrix3x3:                                                
| Xx  Yx  Tx |                                                
| Xy  Yy  Ty |                                                
|  0   0   1 |                                                

--- Vector2 Functions ---                                                                                                                                 
Vector2 V2_zero(void)                                                                                                         
Vector2 V2_one(void)                                                                         
Vector2 V2_add(const Vector2 &v1,const Vector2 &v2)                                                     
Vector2 V2_addFloat(const Vector2& v1, float f)                                                 
Vector2 V2_subtract(const Vector2& v1, const Vector2& v2)                                                
Vector2 V2_SubtractFloat(const Vector2 &v1, float f)                                                
float V2_Length(const Vector2 &v)                                                
float V2_LengthSqrt(const Vector2 &v)                                                
float V2_DotProduct(const Vector2 &v1,const Vector2 &v2)                                                
float V2_Distance(const Vector2 &v1,const Vector2 &v2)                                                
float V2_DistanceSqr(const Vector2 &v1,const Vector2 &v2)                                                
float V2_Angle(const Vector2 &v1,const Vector2 &v2)                                                
Vector2 V2_Scale(const Vector2& v1, float scale)                                               
Vector2 V2_Multiply(const Vector2 &v1,const Vector2 &v2)                                               
Vector2 V2_Divide(const Vector2& v1, const Vector2& v2)                                               
Vector2 V2_Normalize(const Vector2& v1)                                               
Vector2 V2_Transform(const Vector2& v, const Matrix3& mat)                                               
Vector2 V2_Lerp(const Vector2 &v1,const Vector2 &v2,const float &amount)                                               
Vector2 V2_Reflect(const Vector2 &v,const Vector2 &normal)                                               
Vector2 V2_Rotate(const Vector2 &v,const float angle)                                               
Vector2 V2_MoveTo(const Vector2 &begin,const Vector2 &end,float maxDistance)                                               
Vector2 V2_Invert(Vector2 v)                                               
Vector2 V2_Clamp(Vector2 v, Vector2 min, Vector2 max)                                               
Vector2 V2_ClampValue(Vector2 v, float min, float max)                                               
int V2_Equal(Vector2 p, Vector2 q)                                               
                                                                                                                                    
--- Matrix3x3 Functions ---                                                
M3_Determinant(const Matrix3 &m)                                               
float M3_Trace(const Matrix3& m)                                                
Matrix3 M3_Invert(const Matrix3 &mat)                                                
Matrix3 M3_IdentityStart(void)                                                
Matrix3 M3_Add(const Matrix3& M3left, const Matrix3& M3right)                                                
Matrix3 M3_Subtract(const Matrix3& M3left, const Matrix3& M3right)                                                
Matrix3 M3_Multiply(const Matrix3& M3left, const Matrix3& M3right)                                                
Matrix3 M3_Transform(float x, float y)                                                
Matrix3 M3_Rotate(float angle)                                                
Matrix3 M3_Scale(float x, float y)                                                                                              






