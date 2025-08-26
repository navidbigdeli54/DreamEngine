#pragma once

#include "Math/Vector4D.h"

//-------------------------------------------------------------------------------------------------

struct FMatrix4D
{

protected:

	float Entries[4][4];

public:

	FMatrix4D() = default;

	FMatrix4D(const FVector4D& First, const FVector4D& Second, const FVector4D& Third, const FVector4D& Fourth);

	FMatrix4D(float M00, float M01, float M02, float M03, float M10, float M11, float M12, float M13, float M20, float M21, float M22, float M23, float M30, float M31, float M32, float M33);

public:

	float& operator()(int Row, int Column);

	const float& operator()(int Row, int Column) const;

	FVector4D& operator[](int Column);

	const FVector4D& operator[](int Column) const;
};

//-------------------------------------------------------------------------------------------------