#include "Platform/Generic/GenericPlatformMath.h"

#include <math.h>

//-------------------------------------------------------------------------------------------------

template<typename T>
FORCEINLINE T GenericPlatformMath::Abs(const T value)
{
	return value < 0 ? value * -1 : value;
}

//-------------------------------------------------------------------------------------------------

template<>
FORCEINLINE float GenericPlatformMath::Abs(const float value)
{
	return fabsf(value);
}

//-------------------------------------------------------------------------------------------------

FORCEINLINE float GenericPlatformMath::Sqrt(const float value)
{
	return sqrtf(value);
}

//-------------------------------------------------------------------------------------------------

FORCEINLINE float GenericPlatformMath::Square(const float value)
{
	return value * value;
}

//-------------------------------------------------------------------------------------------------

FORCEINLINE bool GenericPlatformMath::AlmostEqual(const float lhs, const float rhs)
{
	return GenericPlatformMath::Abs(lhs - rhs) < NEAR_ZERO_NUMBER;
}

//-------------------------------------------------------------------------------------------------