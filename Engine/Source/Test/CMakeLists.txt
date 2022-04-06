Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.0-preview3
)

FetchContent_MakeAvailable(Catch2)

add_executable(Test
  Test.cpp
  Runtime/Core/Math/Vector2DTest.cpp
  Runtime/Core/Math/Vector3DTest.cpp
  Runtime/Core/Platform/PlatformTypesTest.cpp
  Runtime/Component/TransformTest.cpp)

target_link_libraries(Test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(Test PRIVATE Runtime)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

include(CTest)
include(Catch)
catch_discover_tests(Test)