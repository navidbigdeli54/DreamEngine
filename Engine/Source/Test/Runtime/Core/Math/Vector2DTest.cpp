#include <catch2/catch_test_macros.hpp>
#include "Math/Vector2D.h"

TEST_CASE("Vector2D::Set", "[Vector2D]")
{
    Vector2D vec2 = Vector2D::Zero;

    srand(time(NULL));
    float randX = rand() % 100;
    float randY = rand() % 100;

    vec2.Set(randX, randY);
    REQUIRE(Math::AlmostEqual(vec2.X, randX));
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