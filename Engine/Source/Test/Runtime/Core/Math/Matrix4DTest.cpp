#include "Math/Matrix4D.h"
#include "Platform/PlatformMath.h"
#include <catch2/catch_test_macros.hpp>

//-------------------------------------------------------------------------------------------------

TEST_CASE("Matrix4D::Matrix4D(FVector3D, FVector3D, FVector3D)", "[Matrix4D]")
{
	srand(static_cast<unsigned int>(time(nullptr)));

	const FVector4D First((float)rand(), (float)rand(), (float)rand(), (float)rand());
	const FVector4D Second((float)rand(), (float)rand(), (float)rand(), (float)rand());
	const FVector4D Third((float)rand(), (float)rand(), (float)rand(), (float)rand());
	const FVector4D Fourth((float)rand(), (float)rand(), (float)rand(), (float)rand());

	const FMatrix4D Matrix(First, Second, Third, Fourth);

	REQUIRE(Matrix[0] == First);
	REQUIRE(Matrix[1] == Second);
	REQUIRE(Matrix[2] == Third);
	REQUIRE(Matrix[3] == Fourth);
}

//-------------------------------------------------------------------------------------------------

TEST_CASE("Matrix4D::Matrix4D(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float)", "[Matrix4D]")
{
	srand(static_cast<unsigned int>(time(nullptr)));

	float M00 = (float)rand(); float M01 = (float)rand(); float M02 = (float)rand(); float M03 = (float)rand();
	float M10 = (float)rand(); float M11 = (float)rand(); float M12 = (float)rand(); float M13 = (float)rand();
	float M20 = (float)rand(); float M21 = (float)rand(); float M22 = (float)rand(); float M23 = (float)rand();
	float M30 = (float)rand(); float M31 = (float)rand(); float M32 = (float)rand(); float M33 = (float)rand();

	const FMatrix4D Matrix(M00, M01, M02, M03, M10, M11, M12, M13, M20, M21, M22, M23, M30, M31, M32, M33);

	REQUIRE(Matrix(0, 0) == M00); REQUIRE(Matrix(0, 1) == M01); REQUIRE(Matrix(0, 2) == M02); REQUIRE(Matrix(0, 3) == M03);
	REQUIRE(Matrix(1, 0) == M10); REQUIRE(Matrix(1, 1) == M11); REQUIRE(Matrix(1, 2) == M12); REQUIRE(Matrix(1, 3) == M13);
	REQUIRE(Matrix(2, 0) == M20); REQUIRE(Matrix(2, 1) == M21); REQUIRE(Matrix(2, 2) == M22); REQUIRE(Matrix(2, 3) == M23);
	REQUIRE(Matrix(3, 0) == M30); REQUIRE(Matrix(3, 1) == M31); REQUIRE(Matrix(3, 2) == M32); REQUIRE(Matrix(3, 3) == M33);
}

//-------------------------------------------------------------------------------------------------