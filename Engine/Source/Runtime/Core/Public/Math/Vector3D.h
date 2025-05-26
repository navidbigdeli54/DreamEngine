#pragma once

#include "Platform/Platform.h"

//-------------------------------------------------------------------------------------------------

struct Vector3D
{

public:

	float X;

	float Y;

	float Z;

public:

	static Vector3D Zero;

	static Vector3D One;

	static Vector3D Forward;

	static Vector3D Right;

	static Vector3D Up;

public:

	Vector3D() : X(0.f), Y(0.f), Z(0.f) {}

	Vector3D(float Value) : X(Value), Y(Value), Z(Value) {}

	Vector3D(float InX, float InY, float InZ) : X(InX), Y(InY), Z(InZ) {}

	Vector3D(const Vector3D& InVector);

public:

	float& operator [](int Index);

	const float& operator [](int Index) const;

	Vector3D& operator *=(float Scalar);

	Vector3D& operator /=(float Scalar);

	Vector3D& operator +=(const Vector3D& InOther);

	Vector3D& operator -=(const Vector3D& InOther);

public:

	float Magnitude() const;

	Vector3D Normalize() const;

	float DotProduct(const Vector3D& Other) const;

	Vector3D CrossProduct(const Vector3D& Other) const;
};

//-------------------------------------------------------------------------------------------------

FORCEINLINE Vector3D operator*(const Vector3D& Vector, float Scalar)
{
	return Vector3D(Vector.X * Scalar, Vector.Y * Scalar, Vector.Z * Scalar);
}

//-------------------------------------------------------------------------------------------------

FORCEINLINE Vector3D operator/(const Vector3D& Vector, float Scalar)
{
	Scalar = 1.0f / Scalar;

	return Vector3D(Vector.X * Scalar, Vector.Y * Scalar, Vector.Z * Scalar);
}

//-------------------------------------------------------------------------------------------------

FORCEINLINE Vector3D operator+(const Vector3D& Left, const Vector3D& Right)
{
	return Vector3D(Left.X + Right.X, Left.Y + Right.Y, Left.Z + Right.Z);
}

//-------------------------------------------------------------------------------------------------

FORCEINLINE Vector3D operator-(const Vector3D& Left, const Vector3D& Right)
{
	return Vector3D(Left.X - Right.X, Left.Y - Right.Y, Left.Z - Right.Z);
}

//-------------------------------------------------------------------------------------------------

FORCEINLINE float operator*(const Vector3D& Left, const Vector3D& Right)
{
	return Left.X * Right.X + Left.Y * Right.Y + Left.Z * Right.Z;
}

//-------------------------------------------------------------------------------------------------

FORCEINLINE Vector3D operator^(const Vector3D& Left, const Vector3D& Right)
{
	return Vector3D(
		/*X*/ Left.Y * Right.Z - Left.Z * Right.Y,
		/*Y*/ Left.Z * Right.X - Left.X - Right.Z,
		/*Z*/ Left.X * Right.Y - Left.Y * Right.X
	);
}

//-------------------------------------------------------------------------------------------------
