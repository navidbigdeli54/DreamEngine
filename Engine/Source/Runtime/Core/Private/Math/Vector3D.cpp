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

bool FVector3D::operator==(const FVector3D& Other) const
{
	return X == Other.X && Y == Other.Y && Z == Other.Z;
}

//-------------------------------------------------------------------------------------------------

bool FVector3D::operator!=(const FVector3D& Other) const
{
	return X != Other.X || Y != Other.Y || Z != Other.Z;
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

float FVector3D::MagnitudeSquared() const
{
	return X * X + Y * Y + Z * Z;
}

//-------------------------------------------------------------------------------------------------

FVector3D FVector3D::Normalize() const
{
	return (FVector3D(*this) / Magnitude());
}

//-------------------------------------------------------------------------------------------------

FVector3D FVector3D::Project(const FVector3D& Onto) const
{
	/*
	* Mathmatical Note:
	* The formula for projecting the vector A onto vector B is: Project(A->B) = ((A.B) / (||B||B||)) * B
	* Since the Dot product of a vector to iself would be the square maginitude of itself, we can rewrite "||B||||B||" part as the dot product of B*B
	* So the formula become Project(A->B) = (A.B / B.B)B;
	*/

	return Onto * (DotProduct(*this, Onto) / DotProduct(Onto, Onto));
}

//-------------------------------------------------------------------------------------------------

FVector3D FVector3D::Reject(const FVector3D& From) const
{
	/*
	* Mathmatical Note:
	* Rejection is part of the vector A that is not projected to vector B!
	* We can calculate the rejection of A from B by removing A from the projection A onto B.
	*/

	return *this - Project(From);
}

//-------------------------------------------------------------------------------------------------

float FVector3D::DotProduct(const FVector3D& Left, const FVector3D& Right)
{
	return Left * Right;
}

//-------------------------------------------------------------------------------------------------

FVector3D FVector3D::CrossProduct(const FVector3D& Left, const FVector3D& Right)
{
	return Left ^ Right;
}

//-------------------------------------------------------------------------------------------------