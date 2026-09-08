#pragma once

class GLFWwindow;

class Application
{
public:
    Application();

    void run();

private:
    void ProcessInput();
    void Update();
    void Render();

    GLFWwindow* window;
    bool running;
    float deltaTime;

    float fps;
    float fpsTimer;
    int frameCount;
};