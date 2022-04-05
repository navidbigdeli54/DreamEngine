#pragma once

#define NEAR_ZERO_NUMBER (1e-5f)
#define FLOAT_PRECESION_THRESHOLD 0.01f

#include <math.h>

struct GenericPlatformMath
{
public:

	template<typename T>
	FORCEINLINE static T Abs(const T value);

	FORCEINLINE static float Sqrt(const float value);

	FORCEINLINE static float Square(const float value);

	FORCEINLINE static bool AlmostEqual(const float lhs, const float rhs);
};

template<typename T>
FORCEINLINE T GenericPlatformMath::Abs(const T value)
{
	return value < 0 ? value * -1 : value;
}

template<>
FORCEINLINE float GenericPlatformMath::Abs(const float value)
{
	return fabsf(value);
}

FORCEINLINE float GenericPlatformMath::Sqrt(const float value)
{
	return sqrtf(value);
}

FORCEINLINE float GenericPlatformMath::Square(const float value)
{
	return value * value;
}

FORCEINLINE bool GenericPlatformMath::AlmostEqual(const float lhs, const float rhs)
{
	return GenericPlatformMath::Abs(lhs - rhs) < NEAR_ZERO_NUMBER;
}
