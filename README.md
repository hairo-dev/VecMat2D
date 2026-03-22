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
V2_Add                                                                                                                                                 
V2_Subtract                                                                         
V2_Scale                                                     
V2_Length                                                 
V2_Normalize                                                
V2_Distance                                                
V2_Lerp                                                
V2_MoveTo                                                
V2_Invert                                                
V2_Clamp                                                
V2_ClampValue                                                
                                                
C++ Operator Overloads:                                                
operator+                                                
operator-                                                
operator*                                                
operator/                                                
operator+=                                                
operator-=                                                
operator*=                                                
operator/=                                                
                                                
--- Matrix3x3 Functions ---                                                
M3_Identity                                                
M3_Rotate                                                
M3_Scale                                                
M3_Translate                                                
M3_Multiply                                                
M3_Transform                                                
M3_Determinant                                                
M3_Inverse                                                
M3_Transpose                                                
                                                
C++ Operator Overloads:                                                
operator*                                                
operator*=                                                
operator+                                                
operator+=                                                






