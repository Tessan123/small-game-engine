#pragma once

#include <memory>
#include "transform.h"
#include "camera.h"
#include "camera2D.h"
#include "directionalLight.h"

class GLFWwindow;
class VertexArray;
class VertexBuffer;
class IndexBuffer;
class Shader;
class Texture;
class Sprite;

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

    Camera camera;
    Camera2D camera2D;

    GLFWwindow *window;
    bool running;
    float deltaTime;

    float fps;
    float fpsTimer;
    int frameCount;

    float positionX;
    float positionY;

    float cubeRotX = 0.0f; // tillfällig
    float cubeRotY = 0.0f; // tillfällig

    Transform transform;
    DirectionalLight directionalLight;

    std::unique_ptr<VertexArray> vertexArray;
    std::unique_ptr<VertexBuffer> vertexBuffer;
    std::unique_ptr<IndexBuffer> indexBuffer;
    std::unique_ptr<Shader> shader;
    std::unique_ptr<Texture> texture;
    std::unique_ptr<Shader> spriteShader;
    std::unique_ptr<Sprite> sprite;
};