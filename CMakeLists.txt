cmake_minimum_required(VERSION 3.20)

project(MyEngine
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Default build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

add_executable(MyEngine
    Sandbox/main.cpp
    Engine/Core/application.cpp
    Engine/Input/input.cpp
)

target_include_directories(MyEngine PRIVATE
    Engine/Core
    Engine/Input
)

find_package(glfw3 REQUIRED)

target_link_libraries(MyEngine PRIVATE
    glfw
    opengl32
)