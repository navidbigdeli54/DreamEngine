#include "Math/Quaternion.h"
#include "Platform/PlatformMath.h"
#include <catch2/catch_test_macros.hpp>

//-------------------------------------------------------------------------------------------------

TEST_CASE("Quaternion::operator*(const Quaternion&, const Quaterion&)", "[Quaternion]")
{
	srand(static_cast<unsigned int>(time(nullptr)));

	FQuaternion Left((float)rand(), (float)rand(), (float)rand(), (float)rand());
	FQuaternion Right((float)rand(), (float)rand(), (float)rand(), (float)rand());

	FVector3D VectorPart = FVector3D::CrossProduct(Left.GetVectorPart(), Right.GetVectorPart()) + (Right.GetVectorPart() * Left.W) + (Left.GetVectorPart() * Right.W);
	float ScalarPart = Left.W * Right.W - FVector3D::DotProduct(Left.GetVectorPart(), Right.GetVectorPart());

	FQuaternion Multiplication = Left * Right;

	REQUIRE(Multiplication.GetVectorPart() == VectorPart);
	REQUIRE(Multiplication.W == ScalarPart);
}

//-------------------------------------------------------------------------------------------------