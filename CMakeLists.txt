cmake_minimum_required(VERSION 3.10)

project(DreamEngine VERSION 0.1)

add_executable(DreamEngine 
    "Engine/Source/Main.cpp"
    "Engine/Source/Runtime/Core/Public/Math/Vector2D.h"
    "Engine/Source/Runtime/Core/Public/Math/Vector3D.h"
    "Engine/Source/Runtime/Core/Public/Platform/Platform.h"
    "Engine/Source/Runtime/Core/Public/Platform/PlatformMath.h"
    "Engine/Source/Runtime/Core/Public/Platform/PlatformTypes.h"
    "Engine/Source/Runtime/Core/Public/Platform/Generic/GenericPlatform.h"
    "Engine/Source/Runtime/Core/Public/Platform/Generic/GenericPlatformMath.h"
    "Engine/Source/Runtime/Core/Public/Platform/Generic/GenericPlatformTypes.h"
    "Engine/Source/Runtime/Core/Public/Platform/Linux/LinuxPlatform.h"
    "Engine/Source/Runtime/Core/Public/Platform/Linux/LinuxPlatformMath.h"
    "Engine/Source/Runtime/Core/Public/Platform/Linux/LinuxPlatformTypes.h"
    "Engine/Source/Runtime/Core/Public/Platform/Windows/WindowsPlatform.h"
    "Engine/Source/Runtime/Core/Public/Platform/Windows/WindowsPlatformMath.h"
    "Engine/Source/Runtime/Core/Public/Platform/Windows/WindowsPlatformTypes.h")

set(CMAKE_CXX_STANDARD 11)
Set(CMAKE_CXX_STANDARD_REQUIRED true)
