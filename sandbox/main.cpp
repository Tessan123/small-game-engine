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

int main()
{
    // std::cout << "My engine starting..." << std::endl;
    // Application app;
    // app.run();

    Application app;

    float vertices[] = {
        -0.5f, 0.5f,
        0.5f, 0.5f,
        -0.5f, -0.5f,
        0.5f, -0.5f};

    unsigned int indices[] = {
        0, 1, 2,
        2, 1, 3};

    VertexArray vertexArray;
    vertexArray.Bind();

    VertexBuffer vertexBuffer(
        vertices,
        sizeof(vertices));

    vertexArray.AddVertexBuffer();

    IndexBuffer indexBuffer(
        indices,
        6);

    vertexArray.Unbind();

    app.run();

    return 0;
}