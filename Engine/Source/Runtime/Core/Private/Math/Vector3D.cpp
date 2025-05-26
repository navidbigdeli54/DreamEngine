#include "Math/Vector3D.h"
#include "Platform/PlatformMath.h"

//-------------------------------------------------------------------------------------------------

FVector3D FVector3D::Zero = FVector3D(0.f);

FVector3D FVector3D::One = FVector3D(1.f);

FVector3D FVector3D::Forward = FVector3D(1.0f, 0.f, 0.f);

FVector3D FVector3D::Right = FVector3D(0.0f, 1.f, 0.f);

FVector3D FVector3D::Up = FVector3D(0.0f, 0.f, 1.f);

//-------------------------------------------------------------------------------------------------

FVector3D::FVector3D(const FVector3D& InVector)
{
	X = InVector.X;
	Y = InVector.Y;
	Z = InVector.Z;
}

//-------------------------------------------------------------------------------------------------

float& FVector3D::operator[](int Index)
{
	return ((&X)[Index]);
}

//-------------------------------------------------------------------------------------------------

const float& FVector3D::operator[](int Index) const
{
	return ((&X)[Index]);
}

//-------------------------------------------------------------------------------------------------

FVector3D& FVector3D::operator*=(float Scalar)
{
	X *= Scalar;
	Y *= Scalar;
	Z *= Scalar;
	return *this;
}

//-------------------------------------------------------------------------------------------------

FVector3D& FVector3D::operator/=(float Scalar)
{
	Scalar = 1.0f / Scalar;
	X *= Scalar;
	Y *= Scalar;
	Z *= Scalar;
	return *this;
}

//-------------------------------------------------------------------------------------------------

FVector3D& FVector3D::operator+=(const FVector3D& InOther)
{
	X += InOther.X;
	Y += InOther.Y;
	Z += InOther.Z;
	return *this;
}

//-------------------------------------------------------------------------------------------------

FVector3D& FVector3D::operator-=(const FVector3D& InOther)
{
	X -= InOther.X;
	Y -= InOther.Y;
	Z -= InOther.Z;
	return *this;
}

//-------------------------------------------------------------------------------------------------

float FVector3D::Magnitude() const
{
	return FMath::Sqrt(X * X + Y * Y + Z * Z);
}

//-------------------------------------------------------------------------------------------------

FVector3D FVector3D::Normalize() const
{
	return (FVector3D(*this) / Magnitude());
}

//-------------------------------------------------------------------------------------------------

float FVector3D::DotProduct(const FVector3D& Other) const
{
	return *this * Other;
}

//-------------------------------------------------------------------------------------------------

FVector3D FVector3D::CrossProduct(const FVector3D& Other) const
{
	return *this ^ Other;
}

//-------------------------------------------------------------------------------------------------