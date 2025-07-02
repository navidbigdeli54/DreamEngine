#include "Math/Matrix3D.h"
#include "Platform/PlatformMath.h"
#include <catch2/catch_test_macros.hpp>

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
	srand(static_cast<unsigned int>(time(nullptr)));
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
	FVector3D VectorA(rand(), rand(), rand());
	FVector3D VectorB(rand(), rand(), rand());
	FVector3D VectorC(rand(), rand(), rand());

	FMatrix3D Matrix(VectorA, VectorB, VectorC);

	FMatrix3D InverseMatrix = Matrix.InverseMatrix();


}

//-------------------------------------------------------------------------------------------------