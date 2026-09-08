#include "application.h"
#include <GLFW/glfw3.h>
#include <iostream>

Application::Application()
    : running(true), deltaTime(0.0f), fps(0.0f), fpsTimer(0.0f), frameCount(0)
{

    if (!glfwInit())
    {
        std::cerr << "failed to initialize GLFW" << std::endl;
        return;
    }

    window = glfwCreateWindow(
        800,
        600,
        "My Engine",
        nullptr,
        nullptr);

    if (!window)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);

    const GLubyte *version = glGetString(GL_VERSION);

    if (version)
    {
        std::cout << "OpenGL version" << version << std::endl;
    }
}

void Application::run()
{
    float lastTime = glfwGetTime();

    while (running)
    {
        float currentTime = glfwGetTime();
        deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        frameCount++;
        fpsTimer += deltaTime;

        if (fpsTimer >= 1.0f)
        {
            fps = frameCount / fpsTimer;

            std::cout << "FPS: " << fps << std::endl;

            frameCount = 0;
            fpsTimer = 0.0f;
        }

        ProcessInput();
        Update();
        Render();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}

void Application::ProcessInput()
{
    glfwPollEvents();

    if (glfwWindowShouldClose(window))
    {
        running = false;
    }
}

void Application::Update()
{
    // std::cout << deltaTime << std::endl;
}

void Application::Render()
{
}