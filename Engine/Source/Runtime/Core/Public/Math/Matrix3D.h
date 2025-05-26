#pragma once

#include "Platform/Platform.h"
#include "Vector3D.h"

//-------------------------------------------------------------------------------------------------

struct Matrix3D
{
private:

	/*
	* I've implememted Matrix3D as colummed vector matrix
	* IM order to be able to access vectors quickly, we store the entries as [colum row] order.
	*/
	float Entries[3][3];

public:

	Matrix3D() = default;

	Matrix3D(const Vector3D& First, const Vector3D& Second, const Vector3D& Third);

	Matrix3D(float M00, float M01, float M02, float M10, float M11, float M12, float M20, float M21, float M22);

public:

	float& operator()(int Row, int Column);

	const float& operator()(int Row, int Column) const;

	Vector3D& operator[](int Index);

	const Vector3D& operator[](int Index) const;
};

//-------------------------------------------------------------------------------------------------

FORCEINLINE Matrix3D operator*(const Matrix3D& Left, const Matrix3D& Right)
{
	return Matrix3D(
		/*M00*/ Left(0, 0) * Right(0, 0) + Left(0, 1) * Right(1, 0) + Left(0, 2) * Right(2, 0),
		/*M01*/ Left(0, 0) * Right(0, 1) + Left(0, 1) * Right(1, 1) + Left(0, 2) * Right(2, 1),
		/*M02*/ Left(0, 0) * Right(0, 2) + Left(0, 1) * Right(1, 2) + Left(0, 2) * Right(2, 2),
		/*M10*/ Left(1, 0) * Right(0, 0) + Left(1, 1) * Right(1, 0) + Left(1, 2) * Right(2, 0),
		/*M11*/ Left(1, 0) * Right(0, 1) + Left(1, 1) * Right(1, 1) + Left(1, 2) * Right(2, 1),
		/*M12*/ Left(1, 0) * Right(0, 2) + Left(1, 1) * Right(1, 2) + Left(1, 2) * Right(2, 2),
		/*M20*/ Left(2, 0) * Right(0, 0) + Left(2, 1) * Right(1, 0) + Left(2, 2) * Right(2, 0),
		/*M21*/ Left(2, 0) * Right(0, 1) + Left(2, 1) * Right(1, 1) + Left(2, 2) * Right(2, 1),
		/*M22*/ Left(2, 0) * Right(0, 2) + Left(2, 1) * Right(1, 2) + Left(2, 2) * Right(2, 2)
	);
}

//-------------------------------------------------------------------------------------------------

FORCEINLINE Vector3D operator*(const Matrix3D& Left, const Vector3D& Right)
{
	return Vector3D(
		Left(0, 0) * Right.X + Left(0, 1) * Right.Y + Left(0, 2) * Right.Z,
		Left(1, 0) * Right.X + Left(1, 1) * Right.Y + Left(1, 2) * Right.Z,
		Left(2, 0) * Right.X + Left(2, 1) * Right.Y + Left(2, 2) * Right.Z
	);
}

//-------------------------------------------------------------------------------------------------