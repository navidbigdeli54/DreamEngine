#include "Math/Matrix3D.h"

//-------------------------------------------------------------------------------------------------

FMatrix3D::FMatrix3D(const FVector3D& First, const FVector3D& Second, const FVector3D& Third)
{
	Entries[0][0] = First.X; Entries[0][1] = First.Y; Entries[0][2] = First.Z;

	Entries[1][0] = Second.X; Entries[1][1] = Second.Y; Entries[1][2] = Second.Z;

	Entries[2][0] = Third.X; Entries[2][1] = Third.Y; Entries[2][2] = Third.Z;
}

//-------------------------------------------------------------------------------------------------

FMatrix3D::FMatrix3D(float M00, float M01, float M02, float M10, float M11, float M12, float M20, float M21, float M22)
{
	Entries[0][0] = M00; Entries[0][1] = M01; Entries[0][2] = M02;

	Entries[1][0] = M10; Entries[1][1] = M11; Entries[1][2] = M12;

	Entries[2][0] = M20; Entries[2][1] = M21; Entries[2][2] = M22;
}

//-------------------------------------------------------------------------------------------------

float& FMatrix3D::operator()(int Row, int Column)
{
	return Entries[Column][Row];
}

//-------------------------------------------------------------------------------------------------

const float& FMatrix3D::operator()(int Row, int Column) const
{
	return Entries[Column][Row];
}

//-------------------------------------------------------------------------------------------------

FVector3D& FMatrix3D::operator[](int Index)
{
	return *reinterpret_cast<FVector3D*>(Entries[Index]);
}

//-------------------------------------------------------------------------------------------------

const FVector3D& FMatrix3D::operator[](int Index) const
{
	return *reinterpret_cast<const FVector3D*>(Entries[Index]);
}

//-------------------------------------------------------------------------------------------------

float FMatrix3D::Determinant() const
{
	/*
	* Determinant of a matrix is the hypervolume of the n-dimensional parallelepiped created by the vector in each column (or row in fact).
	* The determinant can be calculated by the expansion by minors formula with for M3*3 is M00(M11M22-M12M21) + M01(M12M20-M10M22) + M02(M10M21-M11M20).
	*/

	return ((0, 0) * ((1, 1) * (2, 2) - (1, 2) * (2, 1))
		+ ((0, 1) * ((1, 2) * (2, 0) - (1, 0) * (2, 2)))
		+ (2, 0) * ((1, 0) * (2, 1) - (1, 1) * (2, 0)));
}

//-------------------------------------------------------------------------------------------------
