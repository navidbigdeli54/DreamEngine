#pragma once

#include "Platform/Platform.h"
#include "Platform/PlatformMath.h"

struct Vector2D
{
public:
	float X;

	float Y;

public:
	static const Vector2D Zero;

	static const Vector2D One;

	static const Vector2D Up;

	static const Vector2D Right;

public:
	FORCEINLINE Vector2D();

	FORCEINLINE explicit Vector2D(float f);

	FORCEINLINE Vector2D(float x, float y);

	FORCEINLINE Vector2D(const Vector2D &vector);

public:
	FORCEINLINE Vector2D operator*(const float scale) const;

	FORCEINLINE Vector2D operator*=(const float scale);

	FORCEINLINE Vector2D operator/(const float scale) const;

	FORCEINLINE Vector2D operator/=(const float scale);

	FORCEINLINE bool operator==(const Vector2D &rhs) const;

	FORCEINLINE bool operator!=(const Vector2D &rhs) const;

public:
	FORCEINLINE void Set(float x, float y);

	FORCEINLINE float Magnitude() const;

	FORCEINLINE float MagnitudeSquared() const;

	FORCEINLINE bool IsZero() const;

	FORCEINLINE bool IsNearlyZero(float tolerance = NEAR_ZERO_NUMBER) const;
};

const Vector2D Vector2D::Zero = Vector2D();

const Vector2D Vector2D::One = Vector2D(1);

const Vector2D Vector2D::Up = Vector2D(0, 1);

const Vector2D Vector2D::Right = Vector2D(1, 0);

FORCEINLINE Vector2D::Vector2D() : X(0), Y(0) {}

FORCEINLINE Vector2D::Vector2D(float f) : X(f), Y(f) {}

FORCEINLINE Vector2D::Vector2D(float x, float y) : X(x), Y(y) {}

FORCEINLINE Vector2D::Vector2D(const Vector2D &vector) : X(vector.X), Y(vector.Y) {}

FORCEINLINE Vector2D Vector2D::operator*(const float scale) const
{
	return Vector2D(X * scale, Y * scale);
}

FORCEINLINE Vector2D Vector2D::operator*=(const float scale)
{
	X *= scale;
	Y *= scale;
	return *this;
}

FORCEINLINE Vector2D Vector2D::operator/(const float scale) const
{
	const float reversedScale = 1.f / scale;

	return Vector2D(X * reversedScale, Y * reversedScale);
}

FORCEINLINE Vector2D Vector2D::operator/=(const float scale)
{
	const float reversedScale = 1.f / scale;

	X *= reversedScale;
	Y *= reversedScale;

	return *this;
}

FORCEINLINE bool Vector2D::operator==(const Vector2D &rhs) const
{
	return X == rhs.X && Y == rhs.Y;
}

FORCEINLINE bool Vector2D::operator!=(const Vector2D &rhs) const
{
	return X != rhs.X || Y != rhs.Y;
}

FORCEINLINE void Vector2D::Set(float x, float y)
{
	X = x;
	Y = y;
}

FORCEINLINE float Vector2D::Magnitude() const
{
	return Math::Sqrt(MagnitudeSquared());
}

FORCEINLINE float Vector2D::MagnitudeSquared() const
{
	return X * X + Y * Y;
}

FORCEINLINE bool Vector2D::IsZero() const
{
	return X == 0 && Y == 0;
}

FORCEINLINE bool Vector2D::IsNearlyZero(float tolerance) const
{
	return Math::Abs(X <= tolerance) && Math::Abs(Y <= tolerance);
}
