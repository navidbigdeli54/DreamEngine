//#include <catch2/catch_test_macros.hpp>
//#include "Math/Vector3D.h"
//
//TEST_CASE("Vector3D::Zero", "[Vector3D]")
//{
//    Vector3D vec3 = Vector3D::Zero;
//    REQUIRE(vec3.X == 0);
//    REQUIRE(vec3.Y == 0);
//    REQUIRE(vec3.Z == 0);
//}
//
//TEST_CASE("Vector3D::One", "[Vector3D]")
//{
//    Vector3D vec3 = Vector3D::One;
//    REQUIRE(vec3.X == 1);
//    REQUIRE(vec3.Y == 1);
//    REQUIRE(vec3.Z == 1);
//}
//
//TEST_CASE("Vector3D::Up", "[Vector3D]")
//{
//    Vector3D vec3 = Vector3D::Up;
//    REQUIRE(vec3.X == 0);
//    REQUIRE(vec3.Y == 1);
//    REQUIRE(vec3.Z == 0);
//}
//
//TEST_CASE("Vector3D::Forward", "[Vector3D]")
//{
//    Vector3D vec3 = Vector3D::Forward;
//    REQUIRE(vec3.X == 0);
//    REQUIRE(vec3.Y == 0);
//    REQUIRE(vec3.Z == 1);
//}
//
//TEST_CASE("Vector3D::Right", "[Vector3D]")
//{
//    Vector3D vec3 = Vector3D::Right;
//    REQUIRE(vec3.X == 1);
//    REQUIRE(vec3.Y == 0);
//    REQUIRE(vec3.Z == 0);
//}
//
//TEST_CASE("Vector3D::Vector3D(float)", "[Vector3D]")
//{
//    srand(time(NULL));
//    float random = rand() % 100;
//    Vector3D vec3(random);
//    REQUIRE(vec3.X == random);
//    REQUIRE(vec3.Y == random);
//    REQUIRE(vec3.Z == random);
//}
//
//TEST_CASE("Vector3D::Vector3D(float, float, float)", "[Vector3D]")
//{
//    srand(time(NULL));
//    float randX = rand() % 100;
//    float randY = rand() % 100;
//    float randZ = rand() % 100;
//
//    Vector3D vec3(randX, randY, randZ);
//    REQUIRE(vec3.X == randX);
//    REQUIRE(vec3.Y == randY);
//    REQUIRE(vec3.Z == randZ);
//}
//
//TEST_CASE("Vector3D::Vector3D(&Vector3D)", "[Vector3D]")
//{
//    srand(time(NULL));
//    float randX = rand() % 100;
//    float randY = rand() % 100;
//    float randZ = rand() % 100;
//
//    Vector3D vec3(randX, randY, randZ);
//
//    Vector3D otherVec3(vec3);
//
//    REQUIRE(otherVec3.X == randX);
//    REQUIRE(otherVec3.Y == randY);
//    REQUIRE(otherVec3.Z == randZ);
//}
//
//TEST_CASE("Vector3D::CrossProduct(&Vector3D)", "[Vector3D]")
//{
//    srand(time(NULL));
//    float vec1RandX = rand() % 100;
//    float vec1RandY = rand() % 100;
//    float vec1RandZ = rand() % 100;
//    Vector3D vec1(vec1RandX, vec1RandY, vec1RandZ);
//
//    float vec2RandX = rand() % 100;
//    float vec2RandY = rand() % 100;
//    float vec2RandZ = rand() % 100;
//
//    Vector3D vec2(vec2RandX, vec2RandY, vec2RandZ);
//
//    Vector3D crossProduct = vec1 ^ vec2;
//
//    REQUIRE(Math::AlmostEqual(crossProduct.X, vec1.Y * vec2.Z - vec1.Z * vec2.Y));
//    REQUIRE(Math::AlmostEqual(crossProduct.Y, vec1.Z * vec2.X - vec1.X * vec2.Z));
//    REQUIRE(Math::AlmostEqual(crossProduct.Z, vec1.X * vec2.Y - vec1.Y * vec2.X));
//}
//
////TEST_CASE("Vector3D::DotProduct(&Vector3D)", "[Vector3D]")
////{
////    srand(time(NULL));
////    float vec1RandX = rand() % 100;
////    float vec1RandY = rand() % 100;
////    float vec1RandZ = rand() % 100;
////    Vector3D vec1(vec1RandX, vec1RandY, vec1RandZ);
////
////    float vec2RandX = rand() % 100;
////    float vec2RandY = rand() % 100;
////    float vec2RandZ = rand() % 100;
////
////    Vector3D vec2(vec2RandX, vec2RandY, vec2RandZ);
////
////    float dotProduct = vec1 * vec2;
////
////    REQUIRE(Math::AlmostEqual(dotProduct, vec1.X * vec2.X + vec1.Y * vec2.Y + vec1.Z * vec2.Z));
////}
//
//TEST_CASE("Vector3D::Scale(float)", "[Vector3D]")
//{
//    srand(time(NULL));
//    float vec1RandX = rand() % 100;
//    float vec1RandY = rand() % 100;
//    float vec1RandZ = rand() % 100;
//    Vector3D vec3(vec1RandX, vec1RandY, vec1RandZ);
//
//    float randScale = rand() % 100;
//
//    Vector3D scaledVec3 = vec3 * randScale;
//
//    REQUIRE(Math::AlmostEqual(scaledVec3.X, vec3.X * randScale));
//    REQUIRE(Math::AlmostEqual(scaledVec3.Y, vec3.Y * randScale));
//    REQUIRE(Math::AlmostEqual(scaledVec3.Z, vec3.Z * randScale));
//}
//
//TEST_CASE("Vector3D::ScaleAndAssign(float)", "[Vector3D]")
//{
//    srand(time(NULL));
//    float vec1RandX = rand() % 100;
//    float vec1RandY = rand() % 100;
//    float vec1RandZ = rand() % 100;
//    Vector3D vec3(vec1RandX, vec1RandY, vec1RandZ);
//
//    float randScale = rand() % 100;
//
//    Vector3D temp(vec3);
//    temp *= randScale;
//
//    REQUIRE(Math::AlmostEqual(temp.X, vec3.X * randScale));
//    REQUIRE(Math::AlmostEqual(temp.Y, vec3.Y * randScale));
//    REQUIRE(Math::AlmostEqual(temp.Z, vec3.Z * randScale));
//}
//
//TEST_CASE("Vector3D::Divide(float)", "[Vector3D]")
//{
//    srand(time(NULL));
//    float vec1RandX = rand() % 100;
//    float vec1RandY = rand() % 100;
//    float vec1RandZ = rand() % 100;
//    Vector3D vec3(vec1RandX, vec1RandY, vec1RandZ);
//
//    float randScale = rand() % 100;
//
//    Vector3D scaledVec3 = vec3 / randScale;
//
//    REQUIRE(Math::AlmostEqual(scaledVec3.X, vec3.X / randScale));
//    REQUIRE(Math::AlmostEqual(scaledVec3.Y, vec3.Y / randScale));
//    REQUIRE(Math::AlmostEqual(scaledVec3.Z, vec3.Z / randScale));
//}
//
//TEST_CASE("Vector3D::DivideAndAssign(float)", "[Vector3D]")
//{
//    srand(time(NULL));
//    float vec1RandX = rand() % 100;
//    float vec1RandY = rand() % 100;
//    float vec1RandZ = rand() % 100;
//    Vector3D vec3(vec1RandX, vec1RandY, vec1RandZ);
//
//    float randScale = rand() % 100;
//
//    Vector3D temp(vec3);
//    temp /= randScale;
//
//    REQUIRE(Math::AlmostEqual(temp.X, vec3.X / randScale));
//    REQUIRE(Math::AlmostEqual(temp.Y, vec3.Y / randScale));
//    REQUIRE(Math::AlmostEqual(temp.Z, vec3.Z / randScale));
//}
//
////TEST_CASE("Vector3D::Equal(&Vector3D)", "[Vector3D]")
////{
////    srand(time(NULL));
////    float vec1RandX = rand() % 100;
////    float vec1RandY = rand() % 100;
////    float vec1RandZ = rand() % 100;
////    Vector3D vec1(vec1RandX, vec1RandY, vec1RandZ);
////
////    Vector3D vec2(vec1RandX, vec1RandY, vec1RandZ);
////
////    REQUIRE(vec1 == vec2);
////}
//
////TEST_CASE("Vector3D::NotEqual(&Vector3D)", "[Vector3D]")
////{
////    srand(time(NULL));
////    float vec1RandX = rand() % 100;
////    float vec1RandY = rand() % 100;
////    float vec1RandZ = rand() % 100;
////    Vector3D vec1(vec1RandX, vec1RandY, vec1RandZ);
////
////    Vector3D vec2(vec1RandX + rand() % 100, vec1RandY + rand() % 100, vec1RandZ + rand() % 100);
////
////    REQUIRE(vec1 != vec2);
////}
//
////TEST_CASE("Vector3D::Set", "[Vector3D]")
////{
////    Vector3D vec3 = Vector3D::Zero;
////
////    srand(time(NULL));
////    float randX = rand() % 100;
////    float randY = rand() % 100;
////    float randZ = rand() % 100;
////
////    vec3.Set(randX, randY, randZ);
////    REQUIRE(Math::AlmostEqual(vec3.X, randX));
////    REQUIRE(Math::AlmostEqual(vec3.Y, randY));
////    REQUIRE(Math::AlmostEqual(vec3.Z, randZ));
////}
//
//TEST_CASE("Vector3D::Magnitude", "[Vector3D]")
//{
//    srand(time(NULL));
//    float randX = rand() % 100;
//    float randY = rand() % 100;
//    float randZ = rand() % 100;
//    Vector3D vec3(randX, randY, randZ);
//    REQUIRE(Math::AlmostEqual(vec3.Magnitude(), Math::Sqrt(randX * randX + randY * randY + randZ * randZ)));
//}
//
////TEST_CASE("Vector3D::MagnitudeSquared", "[Vector3D]")
////{
////    srand(time(NULL));
////    float randX = rand() % 100;
////    float randY = rand() % 100;
////    float randZ = rand() % 100;
////    Vector3D vec3(randX, randY, randZ);
////    REQUIRE(Math::AlmostEqual(vec3.MagnitudeSquared(), randX * randX + randY * randY + randZ * randZ));
////}
//
////TEST_CASE("Vector3D::IsZero", "[Vector3D]")
////{
////    Vector3D vec3 = Vector3D::Zero;
////    REQUIRE(vec3.IsZero());
////}
////
////TEST_CASE("Vector3D::IsNotZero", "[Vector3D]")
////{
////    Vector3D vec3 = Vector3D::One;
////    REQUIRE_FALSE(vec3.IsZero());
////}
////
////TEST_CASE("Vector3D::IsNearlyZero", "[Vector3D]")
////{
////    Vector3D vec3 = Vector3D::Zero;
////    REQUIRE(vec3.IsNearlyZero());
////}
////
////TEST_CASE("Vector3D::IsNearZeroNumberNearlyZero", "[Vector3D]")
////{
////    Vector3D vec3(NEAR_ZERO_NUMBER, NEAR_ZERO_NUMBER, NEAR_ZERO_NUMBER);
////    REQUIRE(vec3.IsNearlyZero());
////}
////
////TEST_CASE("Vector3D::IsNotNearlyZero", "[Vector3D]")
////{
////    Vector3D vec3 = Vector3D::One;
////    REQUIRE_FALSE(vec3.IsNearlyZero());
////}