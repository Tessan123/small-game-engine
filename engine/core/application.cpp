#include "application.h"
#include "input.h"
#include "renderer.h"
#include <GLFW/glfw3.h>
#include <iostream>

Application::Application()
    : running(true), deltaTime(0.0f), fps(0.0f), fpsTimer(0.0f), frameCount(0), positionX(0.0f), positionY(0.0f)
{

    if (!glfwInit())
    {
        std::cerr << "failed to initialize GLFW" << std::endl;
        return;
    }

    Input::Bind(Action::MoveForvard, Key::W);
    Input::Bind(Action::MoveBackward, Key::S);
    Input::Bind(Action::MoveLeft, Key::A);
    Input::Bind(Action::MoveRight, Key::D);

    Input::Bind(Action::Shoot, MouseButton::Left);
    Input::Bind(Action::Aim, MouseButton::Right);
    Input::Bind(Action::Exit, Key::Escape);

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

    Renderer::Initialize();

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

    Input::Update(window);

    if (Input::WasActionPressed(Action::Exit))
    {
        running = false;
    }
}

void Application::Update()
{
    const float speed = 200.0f;

    if (Input::IsActionDown(Action::MoveForvard))
    {
        positionY += speed * deltaTime;
    }

    if (Input::IsActionDown(Action::MoveBackward))
    {
        positionY -= speed * deltaTime;
    }
    if (Input::IsActionDown(Action::MoveLeft))
    {
        positionX -= speed * deltaTime;
    }
    if (Input::IsActionDown(Action::MoveRight))
    {
        positionX += speed * deltaTime;
    }
    if (Input::WasActionPressed(Action::Shoot))
    {
        std::cout << "Shoot!" << std::endl;
    }
    // std::cout << "Postition: " << positionX << ", " << positionY << std::endl;
}

void Application::Render()
{
    Renderer::Clear();

    glfwSwapBuffers(window);
}