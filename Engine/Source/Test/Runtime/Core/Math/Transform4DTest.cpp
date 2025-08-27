#include "Math/Transform4D.h"
#include "Platform/PlatformMath.h"
#include <catch2/catch_test_macros.hpp>

//-------------------------------------------------------------------------------------------------

TEST_CASE("Transform4D::Transform4D(FVector3D, FVector3D, FVector3D, FPoint3D)", "[Transform4D]")
{
	srand(static_cast<unsigned int>(time(nullptr)));

	const FVector3D First((float)rand(), (float)rand(), (float)rand());
	const FVector3D Second((float)rand(), (float)rand(), (float)rand());
	const FVector3D Third((float)rand(), (float)rand(), (float)rand());
	const FPoint3D Point((float)rand(), (float)rand(), (float)rand());
	float M30 = 0.f; float M31 = 0.f; float M32 = 0.f; float M33 = 1.f;

	const FTransform4D Transform(First, Second, Third, Point);

	REQUIRE(Transform[0] == First);
	REQUIRE(Transform[1] == Second);
	REQUIRE(Transform[2] == Third);
	REQUIRE(Transform[3] == Point);
}

//-------------------------------------------------------------------------------------------------

TEST_CASE("Transform4D::Transform4D(float, float, float, float, float, float, float, float, float, float, float, float)", "[Transform4D]")
{
	srand(static_cast<unsigned int>(time(nullptr)));

	float M00 = (float)rand(); float M01 = (float)rand(); float M02 = (float)rand(); float M03 = (float)rand();
	float M10 = (float)rand(); float M11 = (float)rand(); float M12 = (float)rand(); float M13 = (float)rand();
	float M20 = (float)rand(); float M21 = (float)rand(); float M22 = (float)rand(); float M23 = (float)rand();
	float M30 = 0.f; float M31 = 0.f; float M32 = 0.f; float M33 = 1.f;

	const FTransform4D Transform(M00, M01, M02, M03, M10, M11, M12, M13, M20, M21, M22, M23);

	REQUIRE(Transform(0, 0) == M00); REQUIRE(Transform(0, 1) == M01); REQUIRE(Transform(0, 2) == M02); REQUIRE(Transform(0, 3) == M03);
	REQUIRE(Transform(1, 0) == M10); REQUIRE(Transform(1, 1) == M11); REQUIRE(Transform(1, 2) == M12); REQUIRE(Transform(1, 3) == M13);
	REQUIRE(Transform(2, 0) == M20); REQUIRE(Transform(2, 1) == M21); REQUIRE(Transform(2, 2) == M22); REQUIRE(Transform(2, 3) == M23);
	REQUIRE(Transform(3, 0) == M30); REQUIRE(Transform(3, 1) == M31); REQUIRE(Transform(3, 2) == M32); REQUIRE(Transform(3, 3) == M33);
}

//-------------------------------------------------------------------------------------------------

TEST_CASE("Transform4D::GetTranslation()", "[Transform4D]")
{
	srand(static_cast<unsigned int>(time(nullptr)));

	const FVector3D First((float)rand(), (float)rand(), (float)rand());
	const FVector3D Second((float)rand(), (float)rand(), (float)rand());
	const FVector3D Third((float)rand(), (float)rand(), (float)rand());
	const FPoint3D Point((float)rand(), (float)rand(), (float)rand());
	float M30 = 0.f; float M31 = 0.f; float M32 = 0.f; float M33 = 1.f;

	const FTransform4D Transform(First, Second, Third, Point);

	REQUIRE(Transform.GetTranslation() == Point);
}

//-------------------------------------------------------------------------------------------------

TEST_CASE("Transform4D::SetTranslation(const FPoint3D&)", "[Transform4D]")
{
	srand(static_cast<unsigned int>(time(nullptr)));

	const FVector3D First((float)rand(), (float)rand(), (float)rand());
	const FVector3D Second((float)rand(), (float)rand(), (float)rand());
	const FVector3D Third((float)rand(), (float)rand(), (float)rand());
	const FPoint3D Point((float)rand(), (float)rand(), (float)rand());
	float M30 = 0.f; float M31 = 0.f; float M32 = 0.f; float M33 = 1.f;

	FTransform4D Transform(First, Second, Third, Point);

	REQUIRE(Transform.GetTranslation() == Point);

	const FPoint3D NewPoint((float)rand(), (float)rand(), (float)rand());

	Transform.SetTranslation(NewPoint);

	REQUIRE(Transform.GetTranslation() == NewPoint);
}

//-------------------------------------------------------------------------------------------------