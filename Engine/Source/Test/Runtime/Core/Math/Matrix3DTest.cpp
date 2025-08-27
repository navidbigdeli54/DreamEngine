#include "Math/Matrix3D.h"
#include "Platform/PlatformMath.h"
#include <catch2/catch_test_macros.hpp>

//-------------------------------------------------------------------------------------------------

TEST_CASE("Matrix3D::FMatrix3D(FVector3D, FVector3D, FVector3D)", "[Matrix3D]")
{
	srand(static_cast<unsigned int>(time(nullptr)));

	const FVector3D First((float)rand(), (float)rand(), (float)rand());
	const FVector3D Second((float)rand(), (float)rand(), (float)rand());
	const FVector3D Third((float)rand(), (float)rand(), (float)rand());

	const FMatrix3D Matrix(First, Second, Third);

	REQUIRE(Matrix[0] == First);
	REQUIRE(Matrix[1] == Second);
	REQUIRE(Matrix[2] == Third);
}

//-------------------------------------------------------------------------------------------------

TEST_CASE("Matrix3D::FMatrix3D(float, float, float, float, float, float, float, float, float)", "[Matrix3D]")
{
	srand(static_cast<unsigned int>(time(nullptr)));

	float M00 = (float)rand(); float M01 = (float)rand(); float M02 = (float)rand();
	float M10 = (float)rand(); float M11 = (float)rand(); float M12 = (float)rand();
	float M20 = (float)rand(); float M21 = (float)rand(); float M22 = (float)rand();

	const FMatrix3D Matrix(M00, M01, M02, M10, M11, M12, M20, M21, M22);

	REQUIRE(Matrix(0, 0) == M00); REQUIRE(Matrix(0, 1) == M01); REQUIRE(Matrix(0, 2) == M02);
	REQUIRE(Matrix(1, 0) == M10); REQUIRE(Matrix(1, 1) == M11); REQUIRE(Matrix(1, 2) == M12);
	REQUIRE(Matrix(2, 0) == M20); REQUIRE(Matrix(2, 1) == M21); REQUIRE(Matrix(2, 2) == M22);
}

//-------------------------------------------------------------------------------------------------

TEST_CASE("Matrix3D::Multiplication(Matrix3D)", "[Matrix3D]")
{
	/*
	* TODO:
	*/
}

//-------------------------------------------------------------------------------------------------

TEST_CASE("Matrix3D::Multiplication(Vector3D)", "[Matrix3D]")
{
	/*
	* TODO:
	*/
}

//-------------------------------------------------------------------------------------------------

TEST_CASE("Matrix3D::Determinant", "[Matrix3D]")
{
	FVector3D VectorA(1, 2, 3);
	FVector3D VectorB(4, 5, 6);
	FVector3D VectorC(7, 8, 9);

	float ScalarTrippleProduct = VectorA * (VectorB ^ VectorC);

	FMatrix3D Matrix(VectorA, VectorB, VectorC);

	float Determinant = Matrix.Determinant();

	REQUIRE(ScalarTrippleProduct == Determinant);
}

//-------------------------------------------------------------------------------------------------

TEST_CASE("Matrix3D::InverseMatrix(Vector3D)", "[Matrix3D]")
{
	srand(static_cast<unsigned int>(time(nullptr)));
	FVector3D VectorA((float)rand(), (float)rand(), (float)rand());
	FVector3D VectorB((float)rand(), (float)rand(), (float)rand());
	FVector3D VectorC((float)rand(), (float)rand(), (float)rand());

	FMatrix3D Matrix(VectorA, VectorB, VectorC);

	FMatrix3D InverseMatrix = Matrix.InverseMatrix();


}

//-------------------------------------------------------------------------------------------------