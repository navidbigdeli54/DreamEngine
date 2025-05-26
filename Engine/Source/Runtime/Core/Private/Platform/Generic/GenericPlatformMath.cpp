#include "Platform/Generic/GenericPlatformMath.h"

#include <math.h>

//-------------------------------------------------------------------------------------------------

template<typename T>
T GenericPlatformMath::Abs(const T Value)
{
	return Value < 0 ? Value * -1 : Value;
}

//-------------------------------------------------------------------------------------------------

template<>
float GenericPlatformMath::Abs(const float Value)
{
	return fabsf(Value);
}

//-------------------------------------------------------------------------------------------------

float GenericPlatformMath::Sqrt(const float Value)
{
	return sqrtf(Value);
}

//-------------------------------------------------------------------------------------------------

float GenericPlatformMath::Square(const float Value)
{
	return Value * Value;
}

//-------------------------------------------------------------------------------------------------

bool GenericPlatformMath::AlmostEqual(const float Left, const float Right)
{
	return GenericPlatformMath::Abs(Left - Right) < NEAR_ZERO_NUMBER;
}

//-------------------------------------------------------------------------------------------------