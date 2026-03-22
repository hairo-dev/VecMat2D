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
Vector2 V2_zero(void) // - Returns the zero vector (0, 0)                                                   
Vector2 V2_one(void) // - Returns the one vector (1, 1)                                                  
Vector2 V2_add(const Vector2 &v1,const Vector2 &v2) // - Adds two vectors component-wise                                                  
Vector2 V2_addFloat(const Vector2& v1, float f) // - Adds a float value to each component of the vector                                                  
Vector2 V2_subtract(const Vector2& v1, const Vector2& v2) // - Subtracts two vectors component-wise                                                  
Vector2 V2_SubtractFloat(const Vector2 &v1, float f) // - Subtracts a float value from each component of the vector                                                 
float V2_Length(const Vector2 &v) // - Returns the length (magnitude) of the vector (with sqrt)                                                  
float V2_LengthSqrt(const Vector2 &v) // - Returns the length of the vector using sqrt (performance-oriented naming)                                                
float V2_DotProduct(const Vector2 &v1,const Vector2 &v2) // - Computes the dot product of two vectors                                                  
float V2_Distance(const Vector2 &v1,const Vector2 &v2) // - Returns the distance between two vectors (with sqrt)                                                  
float V2_DistanceSqr(const Vector2 &v1,const Vector2 &v2) // - Returns the squared distance between two vectors                                                  
float V2_Angle(const Vector2 &v1,const Vector2 &v2) // - Returns the angle (in radians) between two vectors                                                  
Vector2 V2_Scale(const Vector2& v1, float scale) // - Scales the vector by a uniform factor                                                  
Vector2 V2_Multiply(const Vector2 &v1,const Vector2 &v2) // - Multiplies two vectors component-wise                                                  
Vector2 V2_Divide(const Vector2& v1, const Vector2& v2) // - Divides two vectors component-wise                                                  
Vector2 V2_Normalize(const Vector2& v1) // - Returns the normalized (unit length) version of the vector                                                  
Vector2 V2_Transform(const Vector2& v, const Matrix3& mat) // - Transforms a vector by a 3×3 affine matrix                                                  
Vector2 V2_Lerp(const Vector2 &v1,const Vector2 &v2,const float &amount) // - Linearly interpolates between two vectors                                             
Vector2 V2_Reflect(const Vector2 &v,const Vector2 &normal) // - Reflects a vector over a given normal                                                  
Vector2 V2_Rotate(const Vector2 &v,const float angle) // - Rotates a vector by the given angle (in radians)                                                  
Vector2 V2_MoveTo(const Vector2 &begin,const Vector2 &end,float maxDistance) // - Moves from begin toward end by at most maxDistance                                
Vector2 V2_Invert(Vector2 v) // - Returns the inverted vector (-x, -y)                                                  
Vector2 V2_Clamp(Vector2 v, Vector2 min, Vector2 max) // - Clamps each component of the vector between min and max vectors                                          
Vector2 V2_ClampValue(Vector2 v, float min, float max) // - Clamps each component of the vector to the same min/max values                                          
int V2_Equal(Vector2 p, Vector2 q) // - Checks if two vectors are approximately equal (using epsilon tolerance)                                                  
                                                  
--- Matrix3x3 Functions ---                                                  
float M3_Determinant(const Matrix3 &m) // - Computes the determinant of a 3×3 matrix                                                  
float M3_Trace(const Matrix3& m) // - Computes the trace of the matrix                                                   
Matrix3 M3_Invert(const Matrix3 &mat) // - Returns the inverse of the matrix (returns identity if determinant is zero)                                              
Matrix3 M3_IdentityStart(void) // - Creates and returns an identity matrix                                                  
Matrix3 M3_Add(const Matrix3& M3left, const Matrix3& M3right) // - Adds two matrices component-wise                                                  
Matrix3 M3_Subtract(const Matrix3& M3left, const Matrix3& M3right) // - Subtracts two matrices component-wise                                                  
Matrix3 M3_Multiply(const Matrix3& M3left, const Matrix3& M3right) // - Multiplies two 3×3 matrices (correct affine multiplication)                                 
Matrix3 M3_Transform(float x, float y) // - Creates a translation (transform) matrix for (x, y)                                                  
Matrix3 M3_Rotate(float angle) // - Creates a rotation matrix (clockwise, angle in radians)                                                  
Matrix3 M3_Scale(float x, float y) // - Creates a scale matrix with independent x and y factors                                                  
