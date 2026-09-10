#pragma once

#include <memory>
#include "transform.h"

class GLFWwindow;
class VertexArray;
class VertexBuffer;
class IndexBuffer;
class Shader;
class Texture;

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

    std::unique_ptr<VertexArray> vertexArray;
    std::unique_ptr<VertexBuffer> vertexBuffer;
    std::unique_ptr<IndexBuffer> indexBuffer;
    std::unique_ptr<Shader> shader;
    std::unique_ptr<Texture> texture;
};