#include "Platform/Generic/GenericPlatformMath.h"

#include <math.h>

//-------------------------------------------------------------------------------------------------

template<typename T>
T FGenericPlatformMath::Abs(const T Value)
{
	return Value < 0 ? Value * -1 : Value;
}

//-------------------------------------------------------------------------------------------------

template<>
float FGenericPlatformMath::Abs(const float Value)
{
	return fabsf(Value);
}

//-------------------------------------------------------------------------------------------------

float FGenericPlatformMath::Sqrt(const float Value)
{
	return sqrtf(Value);
}

//-------------------------------------------------------------------------------------------------

float FGenericPlatformMath::Square(const float Value)
{
	return Value * Value;
}

//-------------------------------------------------------------------------------------------------

bool FGenericPlatformMath::AlmostEqual(const float Left, const float Right)
{
	return FGenericPlatformMath::Abs(Left - Right) < NEAR_ZERO_NUMBER;
}

//-------------------------------------------------------------------------------------------------