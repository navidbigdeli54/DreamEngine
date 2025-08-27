#pragma once

struct FVector4D
{

public:

	float X, Y, Z, W;

public:

	FVector4D() = default;

	FVector4D(float InX, float InY, float InZ, float InW);

public:

	float& operator[](int Component);

	const float& operator[](int Component) const;

	FVector4D& operator*=(float Scalar);

	FVector4D& operator/=(float Scalar);

	FVector4D& operator +=(const FVector4D& Other);

	FVector4D& operator -=(const FVector4D& Other);
};