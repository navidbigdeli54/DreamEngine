#include "Math/Quaternion.h"

//-------------------------------------------------------------------------------------------------

FQuaternion::FQuaternion(const FVector3D& Vector, float Scalar) : X(Vector.X), Y(Vector.Y), Z(Vector.Z), W(Scalar)
{

}

//-------------------------------------------------------------------------------------------------

FQuaternion::FQuaternion(float InX, float InY, float InZ, float InW) : X(InX), Y(InY), Z(InZ), W(InW)
{

}

//-------------------------------------------------------------------------------------------------

const FVector3D& FQuaternion::GetVectorPart() const
{
	return reinterpret_cast<const FVector3D&>(X);
}

//-------------------------------------------------------------------------------------------------

FMatrix3D FQuaternion::GetRotationMatrix() const
{
	return FMatrix3D();
}

//-------------------------------------------------------------------------------------------------

void FQuaternion::SetRotationMatrix(const FMatrix3D& Matrix)
{
}

//-------------------------------------------------------------------------------------------------

FQuaternion operator*(const FQuaternion& Left, const FQuaternion& Right)
{
	return FQuaternion(
		Left.W * Right.X + Left.X * Right.W + Left.Y * Right.Z - Left.Z * Right.Y,
		Left.W * Right.Y - Left.X * Right.Z + Left.Y * Right.W + Left.Z * Right.X,
		Left.W * Right.Z + Left.X * Right.Y - Left.Y * Right.X + Left.Z * Right.W,
		Left.W * Right.W - Left.X * Right.X - Left.Y * Right.Y - Left.Z * Right.Z);
}

//-------------------------------------------------------------------------------------------------
