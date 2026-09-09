#include <iostream>
#include <cmath>
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat2.h"
#include "mat3.h"
#include "mat4.h"
#include "transform.h"
#include "application.h"
#include "vertexBuffer.h"
#include "indexBuffer.h"
#include "vertexArray.h"
#include "shader.h"
#include "openGLLoader.h"

int main()
{
    // std::cout << "My engine starting..." << std::endl;
    // Application app;
    // app.run();

    Application app;

    std::cout << "1" << std::endl;

    float vertices[] = {
        -0.5f, 0.5f,
        0.5f, 0.5f,
        -0.5f, -0.5f,
        0.5f, -0.5f};

    unsigned int indices[] = {
        0, 1, 2,
        2, 1, 3};

    std::cout << "2" << std::endl;

    VertexArray vertexArray;
    vertexArray.Bind();

    std::cout << "3" << std::endl;

    VertexBuffer vertexBuffer(
        vertices,
        sizeof(vertices));

    vertexArray.AddVertexBuffer();

    std::cout << "4" << std::endl;

    IndexBuffer indexBuffer(
        indices,
        6);

    vertexArray.Unbind();

    std::cout << "5" << std::endl;

    Shader shader(
        "Engine/Assets/Shaders/basic.vert",
        "Engine/Assets/Shaders/basic.frag");

    shader.Bind();

    std::cout << "6" << std::endl;

    vertexArray.Bind();

    glDrawElements(
        GL_TRIANGLES,
        indexBuffer.GetCount(),
        GL_UNSIGNED_INT,
        nullptr);

    vertexArray.Unbind();

    std::cout << "Before app.run()" << std::endl;

    app.run();

    std::cout << "After app.run()" << std::endl;

    return 0;
}