#include <catch2/catch_test_macros.hpp>
#include "Math/Vector2D.h"

TEST_CASE("Vector2D::Vector2D()", "[Vector2D]")
{
    Vector2D vec2;
    REQUIRE(vec2.X == 0);
    REQUIRE(vec2.Y == 0);
}

TEST_CASE("Vector2D::Vector2D(float)", "[Vector2D]")
{
    srand(time(NULL));
    float random = rand() % 100;
    Vector2D vec2(random);
    REQUIRE(vec2.X == random);
    REQUIRE(vec2.Y == random);
}

TEST_CASE("Vector2D::Vector2D(float, float)", "[Vector2D]")
{
    srand(time(NULL));
    float randX = rand() % 100;
    float randY = rand() % 100;
    Vector2D vec2(randX, randY);
    REQUIRE(vec2.X == randX);
    REQUIRE(vec2.Y == randY);
}

TEST_CASE("Vector2D::Vector2D(&Vector2D)", "[Vector2D]")
{
    srand(time(NULL));
    float randX = rand() % 100;
    float randY = rand() % 100;
    Vector2D vec2(randX, randY);

    Vector2D otherVector2(vec2);

    REQUIRE(otherVector2.X == randX);
    REQUIRE(otherVector2.Y == randY);
}

TEST_CASE("Vector2D::Scale(float)", "[Vector2D]")
{
    srand(time(NULL));
    float vec1RandX = rand() % 100;
    float vec1RandY = rand() % 100;
    Vector2D vec2(vec1RandX, vec1RandY);

    float randScale = rand() % 100;

    Vector2D scaledVec2 = vec2 * randScale;

    REQUIRE(Math::AlmostEqual(scaledVec2.X, vec2.X * randScale));
    REQUIRE(Math::AlmostEqual(scaledVec2.Y, vec2.Y * randScale));
}

TEST_CASE("Vector2D::ScaleAndAssign(float)", "[Vector2D]")
{
    srand(time(NULL));
    float vec1RandX = rand() % 100;
    float vec1RandY = rand() % 100;
    Vector2D vec2(vec1RandX, vec1RandY);

    float randScale = rand() % 100;

    Vector2D temp(vec2);
    temp *= randScale;

    REQUIRE(Math::AlmostEqual(temp.X, vec2.X * randScale));
    REQUIRE(Math::AlmostEqual(temp.Y, vec2.Y * randScale));
}

TEST_CASE("Vector2D::Divide(float)", "[Vector2D]")
{
    srand(time(NULL));
    float vec1RandX = rand() % 100;
    float vec1RandY = rand() % 100;
    Vector2D vec2(vec1RandX, vec1RandY);

    float randScale = rand() % 100;

    Vector2D scaledVec2 = vec2 / randScale;

    REQUIRE(Math::AlmostEqual(scaledVec2.X, vec2.X / randScale));
    REQUIRE(Math::AlmostEqual(scaledVec2.Y, vec2.Y / randScale));
}

TEST_CASE("Vector2D::DivideAndAssign(float)", "[Vector2D]")
{
    srand(time(NULL));
    float vec1RandX = rand() % 100;
    float vec1RandY = rand() % 100;
    Vector2D vec2(vec1RandX, vec1RandY);

    float randScale = rand() % 100;

    Vector2D temp(vec2);
    temp /= randScale;

    REQUIRE(Math::AlmostEqual(temp.X, vec2.X / randScale));
    REQUIRE(Math::AlmostEqual(temp.Y, vec2.Y / randScale));
}

TEST_CASE("Vector2D::Equal(&Vector3D)", "[Vector2D]")
{
    srand(time(NULL));
    float vec1RandX = rand() % 100;
    float vec1RandY = rand() % 100;
    Vector2D vec1(vec1RandX, vec1RandY);

    Vector2D vec2(vec1RandX, vec1RandY);

    REQUIRE(vec1 == vec2);
}

TEST_CASE("Vector2D::NotEqual(&Vector3D)", "[Vector2D]")
{
    srand(time(NULL));
    float vec1RandX = rand() % 100;
    float vec1RandY = rand() % 100;
    Vector2D vec1(vec1RandX, vec1RandY);

    Vector2D vec2(vec1RandX + rand() % 100, vec1RandY + rand() % 100);

    REQUIRE(vec1 != vec2);
}

TEST_CASE("Vector2D::Set", "[Vector2D]")
{
    Vector2D vec2 = Vector2D::Zero;

    srand(time(NULL));
    float randX = rand() % 100;
    float randY = rand() % 100;

    vec2.Set(randX, randY);
    REQUIRE(vec2.X == randX);
    REQUIRE(vec2.Y == randY);
}

TEST_CASE("Vector2D::Magnitude", "[Vector2D]")
{
    srand(time(NULL));
    float randX = rand() % 100;
    float randY = rand() % 100;
    Vector2D vec2(randX, randY);
    REQUIRE(Math::AlmostEqual(vec2.Magnitude(), Math::Sqrt(randX * randX + randY * randY)));
}

TEST_CASE("Vector2D::MagnitudeSquared", "[Vector2]")
{
    srand(time(NULL));
    float randX = rand() % 100;
    float randY = rand() % 100;
    Vector2D vec2(randX, randY);
    REQUIRE(Math::AlmostEqual(vec2.MagnitudeSquared(), randX * randX + randY * randY));
}

TEST_CASE("Vector2D::IsZero", "[Vector2D]")
{
    Vector2D vec2 = Vector2D::Zero;
    REQUIRE(vec2.IsZero());
}

TEST_CASE("Vector2D::IsNotZero", "[Vector2D]")
{
    Vector2D vec2 = Vector2D::One;
    REQUIRE_FALSE(vec2.IsZero());
}

TEST_CASE("Vector2D::IsNearlyZero", "[Vector2D]")
{
    Vector2D vec2 = Vector2D::Zero;
    REQUIRE(vec2.IsNearlyZero());
}

TEST_CASE("Vector2D::IsNearZeroNumberNearlyZero", "[Vector2D]")
{
    Vector2D vec2(NEAR_ZERO_NUMBER, NEAR_ZERO_NUMBER);
    REQUIRE(vec2.IsNearlyZero());
}

TEST_CASE("Vector2D::IsNotNearlyZero", "[Vector2D]")
{
    Vector2D vec2 = Vector2D::One;
    REQUIRE_FALSE(vec2.IsNearlyZero());
}