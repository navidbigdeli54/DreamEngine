#pragma once

#include "Math/Vector2D.h"
#include "Platform/Platform.h"
#include "Platform/PlatformMath.h"

struct Vector3D
{
public:

	float X;

	float Y;

	float Z;

public:

	static const Vector3D Zero;

	static const Vector3D One;

	static const Vector3D Up;

	static const Vector3D Forward;

	static const Vector3D Right;

public:

	FORCEINLINE Vector3D();

	FORCEINLINE explicit Vector3D(float f);

	FORCEINLINE Vector3D(float x, float y, float z);

	FORCEINLINE Vector3D(const Vector3D &vector);

	FORCEINLINE explicit Vector3D(const Vector2D &vector);

	FORCEINLINE explicit Vector3D(const Vector2D &vector, float z);

public:

	FORCEINLINE Vector3D operator^(const Vector3D &rhs) const;

	FORCEINLINE float operator*(const Vector3D &rhs) const;

	FORCEINLINE Vector3D operator*(const float scale) const;

	FORCEINLINE Vector3D operator*=(const float scale);

	FORCEINLINE Vector3D operator/ (const float scale) const;

	FORCEINLINE Vector3D operator/=(const float scale);

	FORCEINLINE bool operator==(const Vector3D &rhs) const;

	FORCEINLINE bool operator!=(const Vector3D &rhs) const;

public:

	FORCEINLINE void Set(float x, float y, float z);

	FORCEINLINE float Size() const;

	FORCEINLINE float SizeSquared() const;

	FORCEINLINE bool IsZero() const;

	FORCEINLINE bool IsNearlyZero(float tolerance = NEAR_ZERO_NUMBER) const;

	FORCEINLINE bool Normalize(float tolerance = NEAR_ZERO_NUMBER);

	FORCEINLINE bool IsNormalize() const;

	FORCEINLINE Vector3D GetUnsafeNormal() const;

	FORCEINLINE Vector3D GetSafeNormal(float tolerance = NEAR_ZERO_NUMBER) const;

public:
	FORCEINLINE static Vector3D CrossProduct(const Vector3D &a, const Vector3D &b);

	FORCEINLINE static float DotProduct(const Vector3D &a, const Vector3D &b);

	FORCEINLINE static float Distance(const Vector3D &a, const Vector3D &b);

	FORCEINLINE static float DistanceSquared(const Vector3D &a, const Vector3D &b);
};

const Vector3D Vector3D::Zero = Vector3D();

const Vector3D Vector3D::One = Vector3D(1);

const Vector3D Vector3D::Up = Vector3D(0, 1, 0);

const Vector3D Vector3D::Forward = Vector3D(0, 0, 1);

const Vector3D Vector3D::Right = Vector3D(1, 0, 0);


FORCEINLINE Vector3D::Vector3D() : X(0), Y(0), Z(0) { }

FORCEINLINE Vector3D::Vector3D(float f) : X(f), Y(f), Z(f) { }

FORCEINLINE Vector3D::Vector3D(float x, float y, float z) : X(x), Y(y), Z(z) { }

FORCEINLINE Vector3D::Vector3D(const Vector3D &vector) : X(vector.X), Y(vector.Y), Z(vector.Z) { }

FORCEINLINE Vector3D::Vector3D(const Vector2D &vector) : X(vector.X), Y(vector.Y), Z(0) { }

FORCEINLINE Vector3D::Vector3D(const Vector2D &vector, float inZ) : X(vector.X), Y(vector.Y), Z(inZ) { }

FORCEINLINE Vector3D Vector3D::operator^(const Vector3D &rhs) const
{
	return Vector3D(
		Y * rhs.Z - Z * rhs.Y,
		Z * rhs.X - X * rhs.Z,
		X * rhs.Y - Y * rhs.X
	);
}

FORCEINLINE float Vector3D::operator*(const Vector3D &rhs) const
{
	return X * rhs.X + Y * rhs.Y + Z * rhs.Z;
}

FORCEINLINE Vector3D Vector3D::operator*(const float scale) const
{
	return Vector3D(X * scale, Y * scale, X * scale);
}

FORCEINLINE Vector3D Vector3D::operator*=(const float scale)
{
	X *= scale;
	Y *= scale;
	Z *= scale;
	return *this;
}

FORCEINLINE Vector3D Vector3D::operator/(const float scale) const
{
	const float reversedScale = 1.f / scale;

	return Vector3D(X * reversedScale, Y * reversedScale, X * reversedScale);
}

FORCEINLINE Vector3D Vector3D::operator/=(const float scale)
{
	const float reversedScale = 1.f / scale;

	X *= reversedScale;
	Y *= reversedScale;
	Z *= reversedScale;

	return *this;
}

FORCEINLINE bool Vector3D::operator==(const Vector3D &rhs) const
{
	return X == rhs.X && Y == rhs.Y && Z == rhs.Z;
}

FORCEINLINE bool Vector3D::operator!=(const Vector3D &rhs) const
{
	return X != rhs.X || Y != rhs.Y || Z != rhs.Z;
}

FORCEINLINE void Vector3D::Set(float inX, float inY, float inZ)
{
	X = inX;
	Y = inY;
	Z = inZ;
}

FORCEINLINE float Vector3D::Size() const
{
	return Math::Sqrt(SizeSquared());
}

FORCEINLINE float Vector3D::SizeSquared() const
{
	return X * X + Y * Y + Z * Z;
}

FORCEINLINE bool Vector3D::IsZero() const
{
	return X == 0 && Y == 0 && Z == 0;
}

FORCEINLINE bool Vector3D::IsNearlyZero(float tolerance) const
{
	return Math::Abs(X) <= tolerance && Math::Abs(Y) <= tolerance && Math::Abs(Z) <= tolerance;
}

FORCEINLINE bool Vector3D::Normalize(float tolerance)
{
	float sqrtSize = SizeSquared();

	if (sqrtSize > tolerance)
	{
		const float reversedScale = 1.f / Math::Sqrt(sqrtSize);

		*this = *this / reversedScale;

		return true;
	}

	return false;
}

FORCEINLINE bool Vector3D::IsNormalize() const
{
	return Math::Abs(1.f - SizeSquared()) < FLOAT_PRECESION_THRESHOLD;
}

FORCEINLINE Vector3D Vector3D::GetUnsafeNormal() const
{
	const float reversedScale = 1.f / Size();

	return *this / reversedScale;
}

FORCEINLINE Vector3D Vector3D::GetSafeNormal(float tolerance) const
{
	const float sqrtSize = SizeSquared();

	if (sqrtSize == 1) return *this;
	else if (sqrtSize < tolerance) return Zero;

	const float reversedScale = 1.f / Math::Sqrt(sqrtSize);

	return *this / reversedScale;
}

FORCEINLINE Vector3D Vector3D::CrossProduct(const Vector3D &a, const  Vector3D &b)
{
	return a ^ b;
}

FORCEINLINE float Vector3D::DotProduct(const Vector3D &a, const Vector3D &b)
{
	return a * b;
}

FORCEINLINE float Vector3D::Distance(const Vector3D &a, const Vector3D &b)
{
	return Math::Sqrt(DistanceSquared(a, b));
}

FORCEINLINE float Vector3D::DistanceSquared(const Vector3D &a, const Vector3D &b)
{
	return Math::Square(b.X - a.X) + Math::Square(b.Y - a.Y) + Math::Sqrt(b.Z - a.Z);
}

FORCEINLINE Vector2D::Vector2D(const Vector3D &inVector) : X(inVector.X), Y(inVector.Y) { }
