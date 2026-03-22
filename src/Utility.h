#pragma once
#include <math.h>
#include "Utility.h"
#ifdef __cplusplus
extern "C" {
#endif 
	inline float Clamp(float f, float min, float max) {
		if (f < min) return min;
		if (f > max) return max;
		return f;
	}
	inline float Lerp(float start, float end, float ratio_amount) {
		return start + ((end - start) * ratio_amount);
	};
	inline float Normalize(float value, float start, float end) {
		return (value - start) / (end - start);
	};
	inline float Remap(float value, float Nstart, float Nend, float oStart, float oEnd) {
		float ratio = Normalize(value, Nstart, Nend);
		return oStart + (ratio * (oEnd - oStart));
	};
	inline float Wrap(float value, float min, float max) {
		float range = max - min;
		return min + fmod((value - min + range), range);
	}
	inline int FloatEquals(float x, float y) {
		float gap = 0.00001f;
		if (fabs(x - y) < gap) {
			return 1;
		};
		return 0;
	}

#ifdef __cplusplus
}
#endif 