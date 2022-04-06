#include <catch2/catch_test_macros.hpp>
#include "Collection/List.h"

TEST_CASE("List::List", "List")
{
    List<int32> list;

    REQUIRE(list.Size() == 0);
    REQUIRE(list.Capacity() == List<int32>::DefaultCapacity);
}

TEST_CASE("List::List(int32)", "List")
{
    srand(time(NULL));
    int random = rand() % 5;
    List<int32> list(random);

    REQUIRE(list.Size() == 0);
    REQUIRE(list.Capacity() == random);
}

TEST_CASE("List::Add(T)", "List")
{
    List<int32> list(1);
    srand(time(NULL));
    int random = rand() % 100;
    list.Add(random);

    REQUIRE(list.Size() == 1);
    REQUIRE(list[0] == random);
}

TEST_CASE("List::AddAndGrow(T)", "List")
{
    List<int32> list(1);
    srand(time(NULL));
    int random = rand() % 100;
    list.Add(random);
    list.Add(random + 1);

    REQUIRE(list.Size() == 2);
    REQUIRE(list.Capacity() == 2);
    REQUIRE(list[0] == random);
    REQUIRE(list[1] == random + 1);
}

TEST_CASE("List::Remove(T)", "List")
{
    List<int32> list;
    srand(time(NULL));
    int random = rand() % 100;
    list.Add(random);
    list.Add(random + 1);
    list.Add(random + 2);

    REQUIRE(list.Size() == 3);

    list.Remove(random + 1);

    REQUIRE(list.Size() == 2);
    REQUIRE(list[0] == random);
    REQUIRE(list[1] == random + 2);
}

TEST_CASE("List::RemoveAt(size_t)", "List")
{
    List<int32> list;
    srand(time(NULL));
    int random = rand() % 100;
    list.Add(random);
    list.Add(random + 1);
    list.Add(random + 2);

    REQUIRE(list.Size() == 3);

    list.RemoveAt(2);

    REQUIRE(list.Size() == 2);
    REQUIRE(list[0] == random);
    REQUIRE(list[1] == random + 1);
}

TEST_CASE("List::Find(T)", "List")
{
    List<int32> list;
    srand(time(NULL));
    int random = rand() % 100;
    list.Add(random);
    list.Add(random + 1);
    list.Add(random + 2);

    size_t index = list.Find(random + 1);

    REQUIRE(index == 1);
}

TEST_CASE("List::NotFind(T)", "List")
{
    List<int32> list;
    srand(time(NULL));
    int random = rand() % 100;
    list.Add(random);
    list.Add(random + 1);
    list.Add(random + 2);

    size_t index = list.Find(random + 3);

    REQUIRE(index == List<int32>::InvalidIndex);
}

TEST_CASE("List::Contains(T)", "List")
{
    List<int32> list;
    srand(time(NULL));
    int random = rand() % 100;
    list.Add(random);
    list.Add(random + 1);
    list.Add(random + 2);

    REQUIRE(list.Contains(random + 1));
}

TEST_CASE("List::NotContains(T)", "List")
{
    List<int32> list;
    srand(time(NULL));
    int random = rand() % 100;
    list.Add(random);
    list.Add(random + 1);
    list.Add(random + 2);

    REQUIRE(list.Contains(random + 3) == false);
}