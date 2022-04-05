#include <catch2/catch_test_macros.hpp>
#include "Math/Vector2D.h"

TEST_CASE("Set", "[Vector2D]")
{
    Vector2D vec2 = Vector2D::Zero;
    vec2.Set(5.0f, 3.0f);
    REQUIRE(vec2.X == 5.0f);
    REQUIRE(vec2.Y == 3.0f);
}

TEST_CASE("Size", "[Vector2D]")
{
    srand(time(NULL));
    float randX = rand() % 100;
    float randY = rand() % 100;
    Vector2D vec2(randX, randY);
    REQUIRE(vec2.Magnitude() == Math::Sqrt(randX * randX + randY * randY));
}

TEST_CASE("SizeSqure", "[Vector2]")
{
    srand(time(NULL));
    float randX = rand() % 100;
    float randY = rand() % 100;
    Vector2D vec2(randX, randY);
    REQUIRE(vec2.MagnitudeSquared() == randX * randX + randY * randY);
}

TEST_CASE("IsZero", "[Vector2D]")
{
    Vector2D vec2 = Vector2D::Zero;
    REQUIRE(vec2.IsZero());
}

TEST_CASE("IsNotZero", "[Vector2D]")
{
    Vector2D vec2 = Vector2D::One;
    REQUIRE_FALSE(vec2.IsZero());
}

TEST_CASE("IsNearlyZero", "[Vector2D]")
{
    Vector2D vec2 = Vector2D::Zero;
    REQUIRE(vec2.IsNearlyZero());
}

TEST_CASE("IsNearZeroNumberNearlyZero", "[Vector2D]")
{
    Vector2D vec2(NEAR_ZERO_NUMBER, NEAR_ZERO_NUMBER);
    REQUIRE(vec2.IsNearlyZero());
}

TEST_CASE("IsNotNearlyZero", "[Vector2D]")
{
    Vector2D vec2 = Vector2D::One;
    REQUIRE_FALSE(vec2.IsNearlyZero());
}