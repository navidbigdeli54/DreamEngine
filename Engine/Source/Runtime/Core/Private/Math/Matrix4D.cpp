#include "Math/Matrix4D.h"

//-------------------------------------------------------------------------------------------------

FMatrix4D::FMatrix4D(const FVector4D& First, const FVector4D& Second, const FVector4D& Third, const FVector4D& Fourth)
{
	Entries[0][0] = First.X; Entries[0][1] = First.Y; Entries[0][2] = First.Z; Entries[0][3] = First.W;

	Entries[1][0] = Second.X; Entries[1][1] = Second.Y; Entries[1][2] = Second.Z; Entries[1][3] = Second.W;

	Entries[2][0] = Third.X; Entries[2][1] = Third.Y; Entries[2][2] = Third.Z; Entries[2][3] = Third.W;

	Entries[3][0] = Fourth.X; Entries[3][1] = Fourth.Y; Entries[3][2] = Fourth.Z; Entries[3][3] = Fourth.W;
}

//-------------------------------------------------------------------------------------------------

FMatrix4D::FMatrix4D(float M00, float M01, float M02, float M03, float M10, float M11, float M12, float M13, float M20, float M21, float M22, float M23, float M30, float M31, float M32, float M33)
{
	Entries[0][0] = M00; Entries[0][1] = M10; Entries[0][2] = M20; Entries[0][3] = M30;

	Entries[1][0] = M01; Entries[1][1] = M11; Entries[1][2] = M21; Entries[1][3] = M31;

	Entries[2][0] = M02; Entries[2][1] = M12; Entries[2][2] = M22; Entries[2][3] = M32;

	Entries[3][0] = M03; Entries[3][1] = M13; Entries[3][2] = M23; Entries[3][3] = M33;
}

//-------------------------------------------------------------------------------------------------

float& FMatrix4D::operator()(int Row, int Column)
{
	return Entries[Column][Row];
}

//-------------------------------------------------------------------------------------------------

const float& FMatrix4D::operator()(int Row, int Column) const
{
	return Entries[Column][Row];
}

//-------------------------------------------------------------------------------------------------

FVector4D& FMatrix4D::operator[](int Column)
{
	return *reinterpret_cast<FVector4D*>(Entries[Column]);
}

//-------------------------------------------------------------------------------------------------

const FVector4D& FMatrix4D::operator[](int Column) const
{
	return *reinterpret_cast<const FVector4D*>(Entries[Column]);
}

//-------------------------------------------------------------------------------------------------