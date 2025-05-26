cmake_minimum_required(VERSION 3.10)

project(DreamEngine VERSION 0.1.0)

Set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Engine/Binaries/${CMAKE_SYSTEM_NAME}")

add_subdirectory(Engine/Source/Runtime)
add_subdirectory(Engine/Source/Launch)

