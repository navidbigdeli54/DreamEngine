#include "Math/Vector3D.h"
#include "Platform/PlatformMath.h"

//-------------------------------------------------------------------------------------------------

Vector3D Vector3D::Zero = Vector3D(0.f);

Vector3D Vector3D::One = Vector3D(1.f);

Vector3D Vector3D::Forward = Vector3D(1.0f, 0.f, 0.f);

Vector3D Vector3D::Right = Vector3D(0.0f, 1.f, 0.f);

Vector3D Vector3D::Up = Vector3D(0.0f, 0.f, 1.f);

//-------------------------------------------------------------------------------------------------

Vector3D::Vector3D(const Vector3D& InVector)
{
	X = InVector.X;
	Y = InVector.Y;
	Z = InVector.Z;
}

//-------------------------------------------------------------------------------------------------

float& Vector3D::operator[](int Index)
{
	return ((&X)[Index]);
}

//-------------------------------------------------------------------------------------------------

const float& Vector3D::operator[](int Index) const
{
	return ((&X)[Index]);
}

//-------------------------------------------------------------------------------------------------

Vector3D& Vector3D::operator*=(float Scalar)
{
	X *= Scalar;
	Y *= Scalar;
	Z *= Scalar;
	return *this;
}

//-------------------------------------------------------------------------------------------------

Vector3D& Vector3D::operator/=(float Scalar)
{
	Scalar = 1.0f / Scalar;
	X *= Scalar;
	Y *= Scalar;
	Z *= Scalar;
	return *this;
}

//-------------------------------------------------------------------------------------------------

Vector3D& Vector3D::operator+=(const Vector3D& InOther)
{
	X += InOther.X;
	Y += InOther.Y;
	Z += InOther.Z;
	return *this;
}

//-------------------------------------------------------------------------------------------------

Vector3D& Vector3D::operator-=(const Vector3D& InOther)
{
	X -= InOther.X;
	Y -= InOther.Y;
	Z -= InOther.Z;
	return *this;
}

//-------------------------------------------------------------------------------------------------

float Vector3D::Magnitude() const
{
	return Math::Sqrt(X * X + Y * Y + Z * Z);
}

//-------------------------------------------------------------------------------------------------

Vector3D Vector3D::Normalize() const
{
	return (Vector3D(*this) / Magnitude());
}

//-------------------------------------------------------------------------------------------------

float Vector3D::DotProduct(const Vector3D& Other) const
{
	return *this * Other;
}

//-------------------------------------------------------------------------------------------------

Vector3D Vector3D::CrossProduct(const Vector3D& Other) const
{
	return *this ^ Other;
}

//-------------------------------------------------------------------------------------------------