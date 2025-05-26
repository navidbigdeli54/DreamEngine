#pragma once

#define NEAR_ZERO_NUMBER (1e-5f)
#define FLOAT_PRECESION_THRESHOLD 0.01f

struct GenericPlatformMath
{
public:

	template<typename T>
	static T Abs(const T Value);

	static float Sqrt(const float Value);

	static float Square(const float Value);

	static bool AlmostEqual(const float Left, const float Right);
};
