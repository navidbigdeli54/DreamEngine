#pragma once

#include "Platform/Platform.h"

//-------------------------------------------------------------------------------------------------

struct FVector3D
{

public:

	float X;

	float Y;

	float Z;

public:

	static FVector3D Zero;

	static FVector3D One;

	static FVector3D Forward;

	static FVector3D Right;

	static FVector3D Up;

public:

	FVector3D() : X(0.f), Y(0.f), Z(0.f) {}

	explicit FVector3D(float Value) : X(Value), Y(Value), Z(Value) {}

	FVector3D(float InX, float InY, float InZ) : X(InX), Y(InY), Z(InZ) {}

	FVector3D(const FVector3D& InVector);

public:

	bool operator==(const FVector3D& Other) const;

	bool operator!=(const FVector3D& Other) const;

	float& operator [](int Index);

	const float& operator [](int Index) const;

	FVector3D& operator *=(float Scalar);

	FVector3D& operator /=(float Scalar);

	FVector3D& operator +=(const FVector3D& InOther);

	FVector3D& operator -=(const FVector3D& InOther);

public:

	float Magnitude() const;

	float MagnitudeSquared() const;

	FVector3D Normalize() const;

	float DotProduct(const FVector3D& Other) const;

	FVector3D CrossProduct(const FVector3D& Other) const;

	FVector3D Project(const FVector3D& Onto) const;

	FVector3D Reject(const FVector3D& From) const;
};

//-------------------------------------------------------------------------------------------------

FORCEINLINE FVector3D operator*(const FVector3D& Vector, float Scalar)
{
	return FVector3D(Vector.X * Scalar, Vector.Y * Scalar, Vector.Z * Scalar);
}

//-------------------------------------------------------------------------------------------------

FORCEINLINE FVector3D operator/(const FVector3D& Vector, float Scalar)
{
	Scalar = 1.0f / Scalar;

	return FVector3D(Vector.X * Scalar, Vector.Y * Scalar, Vector.Z * Scalar);
}

//-------------------------------------------------------------------------------------------------

FORCEINLINE FVector3D operator+(const FVector3D& Left, const FVector3D& Right)
{
	return FVector3D(Left.X + Right.X, Left.Y + Right.Y, Left.Z + Right.Z);
}

//-------------------------------------------------------------------------------------------------

FORCEINLINE FVector3D operator-(const FVector3D& Left, const FVector3D& Right)
{
	return FVector3D(Left.X - Right.X, Left.Y - Right.Y, Left.Z - Right.Z);
}

//-------------------------------------------------------------------------------------------------

FORCEINLINE float operator*(const FVector3D& Left, const FVector3D& Right)
{
	/*
	* Mathmatical Note:
	* We can also calculate the dot product by the equation ||A.B||=|A||B|cosɑ
	* Also A.B = Transpose(B) * A
	*/

	return Left.X * Right.X + Left.Y * Right.Y + Left.Z * Right.Z;
}

//-------------------------------------------------------------------------------------------------

FORCEINLINE FVector3D operator^(const FVector3D& Left, const FVector3D& Right)
{
	/*
	* Mathmatical Note:
	* We can also calculate the cross product by the equation ||A*B||=|A||B|sinɑ
	*/

	return FVector3D(
		/*X*/ Left.Y * Right.Z - Left.Z * Right.Y,
		/*Y*/ Left.Z * Right.X - Left.X * Right.Z,
		/*Z*/ Left.X * Right.Y - Left.Y * Right.X
	);
}

//-------------------------------------------------------------------------------------------------
