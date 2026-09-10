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

    Engine/Math/vec2.cpp
    Engine/Math/vec3.cpp
    Engine/Math/vec4.cpp

    Engine/Math/mat2.cpp
    Engine/Math/mat3.cpp
    Engine/Math/mat4.cpp

    Engine/Math/transform.cpp

    Engine/renderer/renderer.cpp
    Engine/renderer/openGLLoader.cpp
    Engine/renderer/vertexBuffer.cpp
    Engine/renderer/indexBuffer.cpp
    Engine/renderer/vertexArray.cpp

    Engine/renderer/shader.cpp
    Engine/renderer/texture.cpp
)

target_include_directories(MyEngine PRIVATE
    Engine/Core
    Engine/Input
    Engine/Math
    Engine/renderer
    Engine/thirdParty/stb
)

find_package(glfw3 REQUIRED)

target_link_libraries(MyEngine PRIVATE
    glfw
    opengl32
)