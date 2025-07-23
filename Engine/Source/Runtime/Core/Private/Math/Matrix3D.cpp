#include "Math/Matrix3D.h"
#include "Platform/PlatformMath.h"

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
	* We can also calculate the determinant of a 3×3 matrix as the scalar triple product of its component vectors.
	*/

	const FMatrix3D& M = *this;

	return (M(0, 0) * (M(1, 1) * M(2, 2) - M(1, 2) * M(2, 1))
		+ (M(0, 1) * (M(1, 2) * M(2, 0) - M(1, 0) * M(2, 2)))
		+ M(0, 2) * (M(1, 0) * M(2, 1) - M(1, 1) * M(2, 0)));
}

//-------------------------------------------------------------------------------------------------

FMatrix3D FMatrix3D::InverseMatrix() const
{
	const FMatrix3D& M = *this;

	FVector3D VectorA = M[0];
	FVector3D VectorB = M[1];
	FVector3D VectorC = M[2];

	FVector3D Row1 = VectorB ^ VectorC;
	FVector3D Row2 = VectorC ^ VectorA;
	FVector3D Row3 = VectorA ^ VectorB;

	float InverseDeterminant = 1.f / (Row3 * VectorC);

	FMatrix3D CofactorTranspose(Row1, Row2, Row3);

	return CofactorTranspose * InverseDeterminant;
}

//-------------------------------------------------------------------------------------------------

FMatrix3D FMatrix3D::MakeRotationX(const float Angle) const
{
	const float Cos = FMath::Cos(Angle);
	const float Sin = FMath::Sin(Angle);

	return FMatrix3D(1.f, 0.f, 0.f
		, 0.f, Cos, -Sin
		, 0.f, Sin, Cos
	);
}

//-------------------------------------------------------------------------------------------------

FMatrix3D FMatrix3D::MakeRotationY(const float Angle) const
{
	const float Cos = FMath::Cos(Angle);
	const float Sin = FMath::Sin(Angle);

	return FMatrix3D(Cos, 0.f, Sin
		, 0.f, 1.f, 0.f
		, -Sin, 0.f, Cos
	);
}

//-------------------------------------------------------------------------------------------------

FMatrix3D FMatrix3D::MakeRotationZ(const float Angle) const
{
	const float Cos = FMath::Cos(Angle);
	const float Sin = FMath::Sin(Angle);

	return FMatrix3D(Cos, -Sin, 0.f
		, Sin, Cos, 0.f
		, 0.f, 0.f, 1.f
	);
}

//-------------------------------------------------------------------------------------------------

FMatrix3D FMatrix3D::MakeRotation(const float Angle, const FVector3D& Around) const
{
	const FVector3D Axis = Around.Normalize();

	const float Cos = FMath::Cos(Angle);
	const float Sin = FMath::Sin(Angle);
	const float Diff = 1.f - Cos;

	const float X = Axis.X * Diff;
	const float Y = Axis.Y * Diff;
	const float Z = Axis.Z * Diff;

	const float AXAY = X * Axis.Y;
	const float AXAZ = X * Axis.Z;
	const float AYAZ = Y * Axis.Z;

	return FMatrix3D(Cos + X * Axis.X, AXAY - Sin * Axis.Z, AXAZ + Sin * Axis.Y
		, AXAY + Sin * Axis.Z, Cos + Y * Axis.Y, AYAZ - Sin * Axis.X
		, AXAZ - Sin * Axis.Y, AYAZ + Sin * Axis.X, Cos + Z * Axis.Z
	);
}

//-------------------------------------------------------------------------------------------------