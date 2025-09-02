#pragma once

#include "Math/Matrix3D.h"

//-------------------------------------------------------------------------------------------------

struct FQuaternion
{
public:

	float X, Y, Z, W;

public:

	FQuaternion() = default;

	FQuaternion(const FVector3D& Vector, float Scalar);

	FQuaternion(float InX, float InY, float InZ, float InW);

public:

	const FVector3D& GetVectorPart() const;

	FMatrix3D GetRotationMatrix() const;

	void SetRotationMatrix(const FMatrix3D& Matrix);
};

//-------------------------------------------------------------------------------------------------

FQuaternion operator*(const FQuaternion& Left, const FQuaternion& Right);

//-------------------------------------------------------------------------------------------------