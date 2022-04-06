add_library(Runtime
    Engine/Public/Object.h
    Engine/Public/Engine.h
    Engine/Public/Actor.h
    Engine/Public/Component/Component.h
    Engine/Public/Component/Transform.h
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
    Core/Public/Collection/List.h
    
    Engine/Private/Actor.cpp
    Engine/Private/Component/Transform.cpp
    Core/Private/Math/Vector.cpp
)

target_include_directories(Runtime 
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Engine/Public"
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Core/Public"
)

SET_TARGET_PROPERTIES(Runtime PROPERTIES LINKER_LANGUAGE C)