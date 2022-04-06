add_library(Runtime
    Component/Public/Component.h
    Component/Public/Transform.h
    Core/Public/Math/Vector2D.h
    Core/Public/Math/Vector3D.h
    Core/Public/Platform/Platform.h
    Core/Public/Platform/PlatformMath.h
    Core/Public/Platform/PlatformTypes.h
    Core/Public/Platform/Generic/GenericPlatform.h
    Core/Public/Platform/Generic/GenericPlatformMath.h
    Core/Public/Platform/Generic/GenericPlatformTypes.h
    Core/Public/Platform/Linux/LinuxPlatform.h
    Core/Public/Platform/Linux/LinuxPlatformMath.h
    Core/Public/Platform/Linux/LinuxPlatformTypes.h
    Core/Public/Platform/Windows/WindowsPlatform.h
    Core/Public/Platform/Windows/WindowsPlatformMath.h
    Core/Public/Platform/Windows/WindowsPlatformTypes.h
    
    Component/Private/Transform.cpp
    Core/Private/Math/Vector.cpp
)

target_include_directories(Runtime 
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Component/Public"
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Core/Public"
)

SET_TARGET_PROPERTIES(Runtime PROPERTIES LINKER_LANGUAGE C)