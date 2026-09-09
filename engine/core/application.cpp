#include "application.h"
#include "input.h"
#include "renderer.h"
#include "openGLLoader.h"
#include <GLFW/glfw3.h>
#include <iostream>

Application::Application()
    : running(true), deltaTime(0.0f), fps(0.0f), fpsTimer(0.0f), frameCount(0), positionX(0.0f), positionY(0.0f),
      vertexArray(nullptr), vertexBuffer(nullptr), indexBuffer(nullptr), shader(nullptr)
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

    if (!InitializeOpenGLFunctions())
    {
        glfwDestroyWindow(window);
        glfwTerminate();
        running = false;
        return;
    }

    Renderer::Initialize();

    float vertices[] = {
        -0.5f, 0.5f,
        0.5f, 0.5f,
        -0.5f, -0.5f,
        0.5f, -0.5f};

    unsigned int indices[]{
        0, 1, 2,
        2, 1, 3};

    vertexArray = new VertexArray();

    vertexArray->Bind();

    vertexBuffer = new VertexBuffer(vertices, sizeof(vertices));

    vertexArray->AddVertexBuffer();

    indexBuffer = new IndexBuffer(indices, 6);

    vertexArray->Unbind();

    shader = new Shader(
        "Engine/assets/shaders/basic.vert",
        "Engine/assets/shaders/basic.frag");

    const GLubyte *version = glGetString(GL_VERSION);

    if (version)
    {
        std::cout << "OpenGL version" << version << std::endl;
    }
}

Application::~Application()
{
    delete shader;
    delete indexBuffer;
    delete vertexBuffer;
    delete vertexArray;

    glfwDestroyWindow(window);
    glfwTerminate();
}

void Application::run()
{
    std::cout << "Starting game loop..." << std::endl;
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
    std::cout << "Game loop ended." << std::endl;
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

    shader->Bind();
    vertexArray->Bind();

    glDrawElements(GL_TRIANGLES, indexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);

    vertexArray->Unbind();

    shader->Unbind();

    glfwSwapBuffers(window);
}