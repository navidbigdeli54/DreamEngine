Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0
)

FetchContent_MakeAvailable(Catch2)

add_executable(Test
	Test.cpp
	
	#Platform
	"Runtime/Core/Platform/PlatformTypesTest.cpp"
	
	#Math
	"Runtime/Core/Math/Vector3DTest.cpp"
	"Runtime/Core/Math/Vector4DTest.cpp"
	"Runtime/Core/Math/Matrix3DTest.cpp"
	"Runtime/Core/Math/Matrix4DTest.cpp"
	"Runtime/Core/Math/Transform4DTest.cpp" 
	"Runtime/Core/Math/QuaternionTest.cpp")

target_link_libraries(Test PRIVATE Catch2::Catch2WithMain)
target_link_libraries(Test PRIVATE Runtime)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

include(CTest)
include(Catch)
catch_discover_tests(Test)