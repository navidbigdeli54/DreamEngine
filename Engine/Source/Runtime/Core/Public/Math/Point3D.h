#pragma once

#include "Vector3D.h"

//-------------------------------------------------------------------------------------------------

struct FPoint3D : public FVector3D
{

public:

	FPoint3D() = default;

	FPoint3D(float X, float Y, float Z) : FVector3D(X, Y, Z) { }

};

//-------------------------------------------------------------------------------------------------

FORCEINLINE FPoint3D operator + (const FPoint3D& Left, const FPoint3D& Right)
{
	return FPoint3D(Left.X + Right.X, Left.Y + Right.Y, Left.Z + Right.Z);
}

//-------------------------------------------------------------------------------------------------

FORCEINLINE FPoint3D operator - (const FPoint3D& Left, const FPoint3D& Right)
{
	return FPoint3D(Left.X - Right.X, Left.Y - Right.Y, Left.Z - Right.Z);
}

//-------------------------------------------------------------------------------------------------