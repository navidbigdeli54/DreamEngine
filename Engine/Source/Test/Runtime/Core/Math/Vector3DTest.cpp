#include "Math/Vector3D.h"
#include "Platform/PlatformMath.h"
#include <catch2/catch_test_macros.hpp>

//-------------------------------------------------------------------------------------------------

TEST_CASE("Vector3D::Zero", "[Vector3D]")
{
	FVector3D Vector = FVector3D::Zero;
	REQUIRE(Vector.X == 0);
	REQUIRE(Vector.Y == 0);
	REQUIRE(Vector.Z == 0);
}

//-------------------------------------------------------------------------------------------------

TEST_CASE("Vector3D::One", "[Vector3D]")
{
	FVector3D Vector = FVector3D::One;
	REQUIRE(Vector.X == 1);
	REQUIRE(Vector.Y == 1);
	REQUIRE(Vector.Z == 1);
}

//-------------------------------------------------------------------------------------------------

TEST_CASE("Vector3D::Up", "[Vector3D]")
{
	FVector3D Vector = FVector3D::Up;
	REQUIRE(Vector.X == 0.f);
	REQUIRE(Vector.Y == 0.f);
	REQUIRE(Vector.Z == 1.f);
}

//-------------------------------------------------------------------------------------------------

TEST_CASE("Vector3D::Forward", "[Vector3D]")
{
	FVector3D Vector = FVector3D::Forward;
	REQUIRE(Vector.X == 1.f);
	REQUIRE(Vector.Y == 0.f);
	REQUIRE(Vector.Z == 0.f);
}

//-------------------------------------------------------------------------------------------------

TEST_CASE("Vector3D::Right", "[Vector3D]")
{
	FVector3D Vector = FVector3D::Right;
	REQUIRE(Vector.X == 0.f);
	REQUIRE(Vector.Y == 1.f);
	REQUIRE(Vector.Z == 0.f);
}

//-------------------------------------------------------------------------------------------------

TEST_CASE("Vector3D::Vector3D(float)", "[Vector3D]")
{
	srand(static_cast<unsigned int>(time(nullptr)));
	float Random = static_cast<float>(rand());
	FVector3D Vector(Random);
	REQUIRE(Vector.X == Random);
	REQUIRE(Vector.Y == Random);
	REQUIRE(Vector.Z == Random);
}

//-------------------------------------------------------------------------------------------------

TEST_CASE("Vector3D::Vector3D(float, float, float)", "[Vector3D]")
{
	srand(static_cast<unsigned int>(time(nullptr)));
	float RandX = static_cast<float>(rand());
	float RandY = static_cast<float>(rand());
	float RandZ = static_cast<float>(rand());

	FVector3D Vector(RandX, RandY, RandZ);
	REQUIRE(Vector.X == RandX);
	REQUIRE(Vector.Y == RandY);
	REQUIRE(Vector.Z == RandZ);
}

//-------------------------------------------------------------------------------------------------

TEST_CASE("Vector3D::Vector3D(&Vector3D)", "[Vector3D]")
{
	srand(static_cast<unsigned int>(time(nullptr)));
	float RandX = static_cast<float>(rand());
	float RandY = static_cast<float>(rand());
	float RandZ = static_cast<float>(rand());

	FVector3D Vector(RandX, RandY, RandZ);

	FVector3D CopyVector(Vector);

	REQUIRE(CopyVector.X == RandX);
	REQUIRE(CopyVector.Y == RandY);
	REQUIRE(CopyVector.Z == RandZ);
}

//-------------------------------------------------------------------------------------------------

TEST_CASE("Vector3D::CrossProduct(&Vector3D)", "[Vector3D]")
{
	srand(static_cast<unsigned int>(time(nullptr)));
	float Vector1RandX = static_cast<float>(rand());
	float Vector1RandY = static_cast<float>(rand());
	float Vector1RandZ = static_cast<float>(rand());
	FVector3D Vector1(Vector1RandX, Vector1RandY, Vector1RandZ);

	float Vector2RandX = static_cast<float>(rand());
	float Vector2RandY = static_cast<float>(rand());
	float Vector2RandZ = static_cast<float>(rand());
	FVector3D Vector2(Vector2RandX, Vector2RandY, Vector2RandZ);

	FVector3D CrossProduct = Vector1 ^ Vector2;

	REQUIRE(FMath::AlmostEqual(CrossProduct.X, Vector1.Y * Vector2.Z - Vector1.Z * Vector2.Y));
	REQUIRE(FMath::AlmostEqual(CrossProduct.Y, Vector1.Z * Vector2.X - Vector1.X * Vector2.Z));
	REQUIRE(FMath::AlmostEqual(CrossProduct.Z, Vector1.X * Vector2.Y - Vector1.Y * Vector2.X));
}

//-------------------------------------------------------------------------------------------------

TEST_CASE("Vector3D::DotProduct(&Vector3D)", "[Vector3D]")
{
	srand(static_cast<unsigned int>(time(nullptr)));
	float Vector1RandX = static_cast<float>(rand());
	float Vector1RandY = static_cast<float>(rand());
	float Vector1RandZ = static_cast<float>(rand());
	FVector3D Vector1(Vector1RandX, Vector1RandY, Vector1RandZ);

	float Vector2RandX = static_cast<float>(rand());
	float Vector2RandY = static_cast<float>(rand());
	float Vector2RandZ = static_cast<float>(rand());

	FVector3D Vector2(Vector2RandX, Vector2RandY, Vector2RandZ);

	float DotProduct = Vector1 * Vector2;

	REQUIRE(FMath::AlmostEqual(DotProduct, Vector1.X * Vector2.X + Vector1.Y * Vector2.Y + Vector1.Z * Vector2.Z));
}

//-------------------------------------------------------------------------------------------------

TEST_CASE("Vector3D::Scale(float)", "[Vector3D]")
{
	srand(static_cast<unsigned int>(time(nullptr)));
	float RandX = static_cast<float>(rand());
	float RandY = static_cast<float>(rand());
	float RandZ = static_cast<float>(rand());
	FVector3D Vector(RandX, RandY, RandZ);

	float RandScale = static_cast<float>(rand());

	FVector3D ScaledVector = Vector * RandScale;

	REQUIRE(FMath::AlmostEqual(ScaledVector.X, Vector.X * RandScale));
	REQUIRE(FMath::AlmostEqual(ScaledVector.Y, Vector.Y * RandScale));
	REQUIRE(FMath::AlmostEqual(ScaledVector.Z, Vector.Z * RandScale));
}

//-------------------------------------------------------------------------------------------------

TEST_CASE("Vector3D::ScaleAndAssign(float)", "[Vector3D]")
{
	srand(static_cast<unsigned int>(time(nullptr)));
	float RandX = static_cast<float>(rand());
	float RandY = static_cast<float>(rand());
	float RandZ = static_cast<float>(rand());
	FVector3D Vector(RandX, RandY, RandZ);

	FVector3D CopyVector(Vector);

	float RandScale = static_cast<float>(rand());
	CopyVector *= RandScale;

	REQUIRE(FMath::AlmostEqual(CopyVector.X, Vector.X * RandScale));
	REQUIRE(FMath::AlmostEqual(CopyVector.Y, Vector.Y * RandScale));
	REQUIRE(FMath::AlmostEqual(CopyVector.Z, Vector.Z * RandScale));
}

//-------------------------------------------------------------------------------------------------

TEST_CASE("Vector3D::Divide(float)", "[Vector3D]")
{
	srand(static_cast<unsigned int>(time(nullptr)));
	float RandX = static_cast<float>(rand());
	float RandY = static_cast<float>(rand());
	float RandZ = static_cast<float>(rand());

	FVector3D Vector(RandX, RandY, RandZ);

	float RandScale = static_cast<float>(rand());
	FVector3D ScaledVector = Vector / RandScale;

	REQUIRE(FMath::AlmostEqual(ScaledVector.X, Vector.X / RandScale));
	REQUIRE(FMath::AlmostEqual(ScaledVector.Y, Vector.Y / RandScale));
	REQUIRE(FMath::AlmostEqual(ScaledVector.Z, Vector.Z / RandScale));
}

//-------------------------------------------------------------------------------------------------

TEST_CASE("Vector3D::DivideAndAssign(float)", "[Vector3D]")
{
	srand(static_cast<unsigned int>(time(nullptr)));
	float RandX = static_cast<float>(rand());
	float RandY = static_cast<float>(rand());
	float RandZ = static_cast<float>(rand());
	FVector3D Vector(RandX, RandY, RandZ);

	FVector3D CopyVector(Vector);

	float RandScale = static_cast<float>(rand());
	CopyVector /= RandScale;

	REQUIRE(FMath::AlmostEqual(CopyVector.X, Vector.X / RandScale));
	REQUIRE(FMath::AlmostEqual(CopyVector.Y, Vector.Y / RandScale));
	REQUIRE(FMath::AlmostEqual(CopyVector.Z, Vector.Z / RandScale));
}

//-------------------------------------------------------------------------------------------------

TEST_CASE("Vector3D::Magnitude", "[Vector3D]")
{
	srand(static_cast<unsigned int>(time(nullptr)));
	float RandX = static_cast<float>(rand());
	float RandY = static_cast<float>(rand());
	float RandZ = static_cast<float>(rand());
	FVector3D Vectpr(RandX, RandY, RandZ);
	REQUIRE(FMath::AlmostEqual(Vectpr.Magnitude(), FMath::Sqrt(RandX * RandX + RandY * RandY + RandZ * RandZ)));
}

//-------------------------------------------------------------------------------------------------