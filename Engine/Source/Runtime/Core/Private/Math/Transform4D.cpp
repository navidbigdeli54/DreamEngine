#include "Math/Transform4D.h"

//-------------------------------------------------------------------------------------------------

FTransform4D::FTransform4D(float M00, float M01, float M02, float M03, float M10, float M11, float M12, float M13, float M20, float M21, float M22, float M23)
{
	Entries[0][0] = M00; Entries[0][1] = M10; Entries[0][2] = M20; Entries[0][3] = 0.f;

	Entries[1][0] = M01; Entries[1][1] = M11; Entries[1][2] = M21; Entries[1][3] = 0.f;

	Entries[2][0] = M02; Entries[2][1] = M12; Entries[2][2] = M22; Entries[2][3] = 0.f;

	Entries[3][0] = M03; Entries[3][1] = M13; Entries[3][2] = M23; Entries[3][3] = 1.f;
}

//-------------------------------------------------------------------------------------------------

FTransform4D::FTransform4D(const FVector3D& First, const FVector3D& Second, const FVector3D& Third, const FPoint3D& Point)
{
	Entries[0][0] = First.X; Entries[0][1] = First.Y; Entries[0][2] = First.Z; Entries[0][3] = 0.f;

	Entries[1][0] = Second.X; Entries[1][1] = Second.Y; Entries[1][2] = Second.Z; Entries[1][3] = 0.f;

	Entries[2][0] = Third.X; Entries[2][1] = Third.Y; Entries[2][2] = Third.Z; Entries[2][3] = 0.f;

	Entries[3][0] = Point.X; Entries[3][1] = Point.Y; Entries[3][2] = Point.Z; Entries[3][3] = 1.f;
}

//-------------------------------------------------------------------------------------------------

FVector3D& FTransform4D::operator[](int Column)
{
	return *reinterpret_cast<FVector3D*>(Entries[Column]);
}

//-------------------------------------------------------------------------------------------------

const FVector3D& FTransform4D::operator[](int Column) const
{
	return *reinterpret_cast<const FVector3D*>(Entries[Column]);
}

//-------------------------------------------------------------------------------------------------

const FPoint3D& FTransform4D::GetTranslation() const
{
	return *reinterpret_cast<const FPoint3D*>(Entries[3]);
}

//-------------------------------------------------------------------------------------------------

void FTransform4D::SetTranslation(const FPoint3D& Point)
{
	Entries[3][0] = Point.X;
	Entries[3][1] = Point.Y;
	Entries[3][2] = Point.Z;
}

//-------------------------------------------------------------------------------------------------

FTransform4D FTransform4D::Inverse() const
{
	const FTransform4D& M = *this;

	const FVector3D& A = M[0];
	const FVector3D& B = M[1];
	const FVector3D& C = M[2];
	const FVector3D& D = M[3];

	FVector3D S = A.CrossProduct(B);
	FVector3D T = C.CrossProduct(D);

	const float InvertedDeterminant = 1.0f / S.DotProduct(C);

	S *= InvertedDeterminant;
	T *= InvertedDeterminant;

	const FVector3D V = C * InvertedDeterminant;

	const FVector3D R0 = B.CrossProduct(V);
	const FVector3D R1 = V.CrossProduct(A);

	return FTransform4D(R0.X, R0.Y, R0.Z, -B.DotProduct(T),
		R1.X, R1.Y, R1.Z, A.DotProduct(T),
		S.X, S.Y, S.Z, -D.DotProduct(S));
}

//-------------------------------------------------------------------------------------------------