#include "Math/Matrix3D.h"

//-------------------------------------------------------------------------------------------------

Matrix3D::Matrix3D(const Vector3D& First, const Vector3D& Second, const Vector3D& Third)
{
	Entries[0][0] = First.X; Entries[0][1] = First.Y; Entries[0][2] = First.Z;

	Entries[1][0] = Second.X; Entries[1][1] = Second.Y; Entries[1][2] = Second.Z;

	Entries[2][0] = Third.X; Entries[2][1] = Third.Y; Entries[2][2] = Third.Z;
}

//-------------------------------------------------------------------------------------------------

Matrix3D::Matrix3D(float M00, float M01, float M02, float M10, float M11, float M12, float M20, float M21, float M22)
{
	Entries[0][0] = M00; Entries[0][1] = M01; Entries[0][2] = M02;

	Entries[1][0] = M10; Entries[1][1] = M11; Entries[1][2] = M12;

	Entries[2][0] = M20; Entries[2][1] = M21; Entries[2][2] = M22;
}

//-------------------------------------------------------------------------------------------------

float& Matrix3D::operator()(int Row, int Column)
{
	return Entries[Column][Row];
}

//-------------------------------------------------------------------------------------------------

const float& Matrix3D::operator()(int Row, int Column) const
{
	return Entries[Column][Row];
}

//-------------------------------------------------------------------------------------------------

Vector3D& Matrix3D::operator[](int Index)
{
	return *reinterpret_cast<Vector3D*>(Entries[Index]);
}

//-------------------------------------------------------------------------------------------------

const Vector3D& Matrix3D::operator[](int Index) const
{
	return *reinterpret_cast<const Vector3D*>(Entries[Index]);
}

//-------------------------------------------------------------------------------------------------
