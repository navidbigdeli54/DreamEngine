#pragma once

#include "Platform/Platform.h"

#define NEAR_ZERO_NUMBER (1e-5f)
#define FLOAT_PRECESION_THRESHOLD 0.01f

struct GenericPlatformMath
{
public:

	template<typename T>
	FORCEINLINE static T Abs(const T value);

	FORCEINLINE static float Sqrt(const float value);

	FORCEINLINE static float Square(const float value);

	FORCEINLINE static bool AlmostEqual(const float lhs, const float rhs);
};
