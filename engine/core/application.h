#pragma once

class GLFWwindow;

#include "vertexArray.h"
#include "vertexBuffer.h"
#include "indexBuffer.h"
#include "shader.h"
#include "transform.h"

class Application
{
public:
    Application();
    ~Application();

    void run();

private:
    void ProcessInput();
    void Update();
    void Render();

    GLFWwindow *window;
    bool running;
    float deltaTime;

    float fps;
    float fpsTimer;
    int frameCount;

    float positionX;
    float positionY;

    Transform transform;

    VertexArray *vertexArray;
    VertexBuffer *vertexBuffer;
    IndexBuffer *indexBuffer;
    Shader *shader;
};