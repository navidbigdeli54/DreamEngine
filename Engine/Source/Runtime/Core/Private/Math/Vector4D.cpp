#include "Math/Vector4D.h"

//-------------------------------------------------------------------------------------------------

FVector4D::FVector4D(float InX, float InY, float InZ, float InW) : X(InX), Y(InY), Z(InZ), W(InW)
{

}

//-------------------------------------------------------------------------------------------------

bool FVector4D::operator==(const FVector4D& Other) const
{
	return X == Other.X && Y == Other.Y && Z == Other.Z && W == Other.W;
}

//-------------------------------------------------------------------------------------------------

bool FVector4D::operator!=(const FVector4D& Other) const
{
	return X != Other.X || Y != Other.Y || Z != Other.Z || W != Other.W;
}

//-------------------------------------------------------------------------------------------------

float& FVector4D::operator[](int Component)
{
	return ((&X)[Component]);
}

//-------------------------------------------------------------------------------------------------

const float& FVector4D::operator[](int Component) const
{
	return ((&X)[Component]);
}

//-------------------------------------------------------------------------------------------------

FVector4D& FVector4D::operator*=(float Scalar)
{
	X *= Scalar;
	Y *= Scalar;
	Z *= Scalar;
	W *= Scalar;

	return *this;
}

//-------------------------------------------------------------------------------------------------

FVector4D& FVector4D::operator/=(float Scalar)
{
	const float Factor = 1.f / Scalar;

	X *= Factor;
	Y *= Factor;
	Z *= Factor;
	W *= Factor;

	return *this;
}

//-------------------------------------------------------------------------------------------------

FVector4D& FVector4D::operator+=(const FVector4D& Other)
{
	X += Other.X;
	Y += Other.Y;
	Z += Other.Z;
	W += Other.W;

	return *this;
}

//-------------------------------------------------------------------------------------------------

FVector4D& FVector4D::operator-=(const FVector4D& Other)
{
	X -= Other.X;
	Y -= Other.Y;
	Z -= Other.Z;
	W -= Other.W;

	return *this;
}

//-------------------------------------------------------------------------------------------------