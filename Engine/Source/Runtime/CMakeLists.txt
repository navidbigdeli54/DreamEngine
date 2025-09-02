add_library(Runtime

    #Public
    #----------------------------------------------------------------------------------------------

    #Platform
    "Core/Public/Platform/Platform.h"
    "Core/Public/Platform/PlatformMath.h"
    "Core/Public/Platform/PlatformTypes.h"

    "Core/Public/Platform/Generic/GenericPlatform.h"
    "Core/Public/Platform/Generic/GenericPlatformMath.h"
    "Core/Public/Platform/Generic/GenericPlatformTypes.h"

    "Core/Public/Platform/Linux/LinuxPlatform.h"
    "Core/Public/Platform/Linux/LinuxPlatformMath.h"
    "Core/Public/Platform/Linux/LinuxPlatformTypes.h"

    "Core/Public/Platform/Windows/WindowsPlatform.h"
    "Core/Public/Platform/Windows/WindowsPlatformMath.h"
    "Core/Public/Platform/Windows/WindowsPlatformTypes.h"

    #Math
    "Core/Public/Math/Vector3D.h"
    "Core/Public/Math/Vector4D.h"
    "Core/Public/Math/Point3D.h"
    "Core/Public/Math/Matrix3D.h"
    "Core/Public/Math/Matrix4D.h"
    "Core/Public/Math/Transform4D.h"
    "Core/Public/Math/Quaternion.h"

    #Private
    #----------------------------------------------------------------------------------------------

    #Platform
    "Core/Private/Platform/Generic/GenericPlatformMath.cpp"

    #Math
    "Core/Private/Math/Vector3D.cpp"
    "Core/Private/Math/Vector4D.cpp"
    "Core/Private/Math/Matrix3D.cpp"
    "Core/Private/Math/Matrix4D.cpp"
    "Core/Private/Math/Transform4D.cpp" 
    "Core/Private/Math/Quaternion.cpp")

target_include_directories(Runtime 
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Engine/Public"
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Core/Public"
)

SET_TARGET_PROPERTIES(Runtime PROPERTIES LINKER_LANGUAGE C)