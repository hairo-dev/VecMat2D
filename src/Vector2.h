#pragma once
#ifdef __cplusplus
#include <math.h>
#include "Utility.h"
extern "C" {
#endif

	typedef struct {
		float x;
		float y;
	}Vector2;

	inline Vector2 V2_zero(void) {
		Vector2 v = { 0.0f,0.0f };
		return v;
	};

	inline Vector2 V2_one(void) {
		Vector2 v = { 1.0f,1.0f };
		return v;
	}

	inline Vector2 V2_add(const Vector2 &v1,const Vector2 &v2) {
		Vector2 v;
		v.x = v1.x + v2.x;
		v.y = v1.y + v2.y;
		return v;
	}

	inline Vector2 V2_addFloat(const Vector2& v1, float f) {
		Vector2 v;
		v.x = v1.x + f;
		v.y = v1.y + f;
		return v;
	}

	inline Vector2 V2_subtract(const Vector2& v1, const Vector2& v2) {
		Vector2 v;
		v.x = v1.x - v2.x;
		v.y = v1.y - v2.y;
		return v;
	}

	inline Vector2 V2_SubtractFloat(const Vector2 &v1, float f) {
		Vector2 v;
		v.x = v1.x - f;
		v.y = v1.y - f;
		return v;
	};
	inline float V2_Length(const Vector2 &v) {
		float sqr = v.x * v.x + v.y * v.y;
		return sqrt(sqr);
	};
	inline float V2_LengthSqrt(const Vector2 &v) {
		float sqrt = v.x * v.x + v.y * v.y;
		return sqrt;
	};

	inline float V2_DotProduct(const Vector2 &v1,const Vector2 &v2) {
		float dot = v1.x * v2.x + v1.y * v2.y;
		return dot;
	};

	inline float V2_Distance(const Vector2 &v1,const Vector2 &v2) {
		Vector2 v = { v1.x - v2.x,v1.y - v2.y };
		return V2_Length(v);
	};

	inline float V2_DistanceSqrt(const Vector2 &v1,const Vector2 &v2) {
		Vector2 v = { v1.x - v2.x,v1.y - v2.y };
		return V2_LengthSqrt(v);
	};

	float V2_Angle(const Vector2 &v1,const Vector2 &v2) {
		float line1 = V2_DotProduct(v1, v2);
		float line2 = V2_Length(v1) * V2_Length(v2);

		if (line2 == 0.0f) return 0.0f;

		float ratio = line1 / line2;

		ratio = Clamp(ratio, -1.0f, 1.0f);

		return acos(ratio);
	};

	inline Vector2 V2_Scale(const Vector2& v1, float scale) {
		Vector2 v;
		v.x = v1.x * scale;
		v.y = v1.y * scale;
		return v;
	};

	inline Vector2 V2_Multiply(const Vector2 &v1,const Vector2 &v2) {
		Vector2 v;
		v.x = v1.x * v2.x;
		v.y = v1.y * v2.y;
		return v;
	};

	inline Vector2 V2_Divide(const Vector2& v1, const Vector2& v2) {
		Vector2 v = { v1.x / v2.x,v1.y / v2.y };
		return v;
	};

	inline Vector2 V2_Normalize(const Vector2& v1) {
		float length = V2_Length(v1);
		if (length < 0.000001f) return { 0.0f, 0.0f };
		Vector2 v = {v1.x/length,v1.y/length};
		return v;
	};
	Vector2 V2_Transform(const Vector2& v, const Matrix3& mat) {
		Vector2 result = V2_zero();

		result.x = (v.x * mat.Xx) + (v.y * mat.Xy) + mat.Tx*mat.m2;
		result.y = (v.x * mat.Yx) + (v.y * mat.Yy) + mat.Ty*mat.m2;

		return result;
	};
	Vector2 V2_Lerp(const Vector2 &v1,const Vector2 &v2,float &amount) {
		if (amount < 0.0f) amount = 0.0f;
		if (amount > 1.0f) amount = 1.0f;
		return { v1.x + (v2.x - v1.x) * amount,v1.y + (v2.y - v1.y) * amount };
	};
	Vector2 V2_Reflect(const Vector2 &v,const Vector2 &normal) {
		
		float dot = V2_DotProduct(v, normal);
		Vector2 sub = { 2.0f * dot * normal.x,2.0f * dot * normal.y };

		return {v.x - sub.x , v.y - sub.y};
	};
	Vector2 V2_Rotate(const Vector2 &v,const float angle) {
		Vector2 nv;

		nv.x = v.x * cos(angle) - v.y * sin(angle);
		nv.y = v.x * sin(angle) + v.y * cos(angle);

		return nv;
	};
	Vector2 V2_MoveTo(const Vector2 &begin,const Vector2 &end,float maxDistance) {
		Vector2 diff = V2_subtract(end, begin);
		float dist = V2_Length(diff);

		if (dist <= maxDistance || dist == 0.0f)
			return end;

		Vector2 dir = V2_Normalize(diff);
		return V2_add(begin, V2_Scale(dir, maxDistance));
	};
	Vector2 V2_Invert(Vector2 v) {
		return { -v.x,-v.y };
	};

	Vector2 V2_Clamp(Vector2 v, Vector2 min, Vector2 max) {
		if (v.x < min.x) v.x = min.x;
		if (v.x > max.x) v.x = max.x;

		if (v.y < min.y) v.y = min.y;
		if (v.y > max.y) v.y = max.y;

		return v;
	}
	Vector2 V2_ClampValue(Vector2 v, float min, float max) {
		return {
		Clamp(v.x, min, max),
		Clamp(v.y, min, max)
		};
	};
	int V2_Equal(Vector2 p, Vector2 q) {
		float gap = 0.00001f;
		if (fabs(p.x - q.x) < gap && fabs(p.y - q.y) < gap) return 1;
		return 0;
	};
#ifdef __cplusplus
}
#endif
