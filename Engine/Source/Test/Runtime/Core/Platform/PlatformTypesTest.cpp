#include <catch2/catch_test_macros.hpp>
#include "Platform/PlatformTypes.h"

TEST_CASE("PlatformTypes::uint8", "[PlatformTypes]")
{
    REQUIRE(sizeof(uint8) == 1);
}

TEST_CASE("PlatformTypes::uint16", "[PlatformTypes]")
{
    REQUIRE(sizeof(uint16) == 2);
}

TEST_CASE("PlatformTypes::uint32", "[PlatformTypes]")
{
    REQUIRE(sizeof(uint32) == 4);
}

TEST_CASE("PlatformTypes::uint64", "[PlatformTypes]")
{
    REQUIRE(sizeof(uint64) == 8);
}

TEST_CASE("PlatformTypes::int8", "[PlatformTypes]")
{
    REQUIRE(sizeof(int8) == 1);
}

TEST_CASE("PlatformTypes::int16", "[PlatformTypes]")
{
    REQUIRE(sizeof(int16) == 2);
}

TEST_CASE("PlatformTypes::int32", "[PlatformTypes]")
{
    REQUIRE(sizeof(int32) == 4);
}

TEST_CASE("PlatformTypes::int64", "[PlatformTypes]")
{
    REQUIRE(sizeof(int64) == 8);
}

TEST_CASE("PlatformTypes::ansichar", "[PlatformTypes]")
{
    REQUIRE(sizeof(ansichar) == 1);
}

TEST_CASE("PlatformTypes::utf16char", "[PlatformTypes]")
{
    REQUIRE(sizeof(utf16char) == 2);
}

TEST_CASE("PlatformTypes::utf32char", "[PlatformTypes]")
{
    REQUIRE(sizeof(utf32char) == 4);
}