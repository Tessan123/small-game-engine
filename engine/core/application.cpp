#include "application.h"
#include "input.h"
#include "renderer.h"
#include "openGLLoader.h"
#include "shader.h"
#include "texture.h"
#include "camera.h"
#include "sprite.h"
#include "material.h"
#include "renderData.h"
#include "mesh.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <memory>

Application::Application()
    : running(true), deltaTime(0.0f), fps(0.0f), fpsTimer(0.0f), frameCount(0), positionX(0.0f), positionY(0.0f), window(nullptr),
      camera(45.0f * 3.14159265359f / 180.0f,
             800.0f / 600.0f,
             0.1f,
             100.0f),
      camera2D(800.0f, 600.0f)
{

    if (!glfwInit())
    {
        std::cerr << "failed to initialize GLFW" << std::endl;
        return;
    }

    // camera.SetPosition(Vec3(0.0f, 0.0f, 5.0f));

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
    glfwSetScrollCallback(window, ScrollCallback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if (!InitializeOpenGLFunctions())
    {
        glfwDestroyWindow(window);
        glfwTerminate();
        running = false;
        return;
    }

    Renderer::Initialize(window);

    texture = std::make_unique<Texture>("engine/assets/test.jpg");

    sprite = std::make_unique<Sprite>(texture.get());
    sprite->SetPosition(Vec2(400.0f, 300.0f));
    sprite->SetSize(Vec2(200.0f, 200.0f));

    mesh = Mesh::CreateCube();

    shader = std::make_unique<Shader>(
        "Engine/assets/shaders/basic.vert",
        "Engine/assets/shaders/basic.frag");

    spriteShader = std::make_unique<Shader>(
        "Engine/assets/shaders/sprite.vert",
        "Engine/assets/shaders/sprite.frag");

    material = std::make_unique<Material>(shader.get(), texture.get());

    const GLubyte *version = glGetString(GL_VERSION);

    if (version)
    {
        std::cout << "OpenGL version" << version << std::endl;
    }
}

Application::~Application()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Application::run()
{
    std::cout << "Starting game loop..." << std::endl;
    float lastTime = glfwGetTime();

    material->SetSpecularIntensity(1.0f);
    material->SetShininess(32.0f);
    material->SetColor(
        Vec3(1.0f, 1.0f, 1.0f));

    lights.point.SetPosition(Vec3(2.0f, 0.0f, 0.0f));
    lights.point.SetColor(Vec3(0.0f, 0.0f, 0.0f));
    lights.point.SetIntensity(2.0f);

    lights.spot.SetPosition(Vec3(0.0f, 0.0f, 0.0f));

    lights.spot.SetDirection(
        Vec3(1.0f, 0.0f, -1.0f));

    lights.spot.SetColor(
        Vec3(0.0f, 1.0f, 0.0f));

    lights.spot.SetIntensity(5.0f);

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

            // std::cout << "FPS: " << fps << std::endl;

            frameCount = 0;
            fpsTimer = 0.0f;
        }
        ProcessInput();
        Update();
        Render();
    }
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
    const float spriteSpeed = 200.0f;
    const float cameraSpeed = 300.0f;
    Vec2 spriteMovement(0.0f, 0.0f);
    Vec2 cameraMovement(0.0f, 0.0f);
    double scroll = Input::GetScrollDelta();

    cubeRotX += 0.5f * deltaTime;
    cubeRotY += 1.0f * deltaTime;

    transform.SetRotation(
        Vec3(
            cubeRotX,
            cubeRotY,
            0.0f));

    if (scroll != 0.0)
    {
        camera2D.Zoom(scroll * 0.1f);
        Input::ResetScroll();
    }

    if (Input::IsActionDown(Action::MoveForvard))
    {
        camera.Move(camera.GetForward(), deltaTime);
        // spriteMovement.y += spriteSpeed * deltaTime;
        // cameraMovement.y += cameraSpeed * deltaTime;
    }

    if (Input::IsActionDown(Action::MoveBackward))
    {
        camera.Move(-camera.GetForward(), deltaTime);
        // spriteMovement.y -= spriteSpeed * deltaTime;
        // cameraMovement.y -= cameraSpeed * deltaTime;
    }
    if (Input::IsActionDown(Action::MoveLeft))
    {
        camera.Move(-camera.GetRight(), deltaTime);
        // spriteMovement.x -= spriteSpeed * deltaTime;
        // cameraMovement.x -= cameraSpeed * deltaTime;
    }
    if (Input::IsActionDown(Action::MoveRight))
    {
        camera.Move(camera.GetRight(), deltaTime);
        // spriteMovement.x += spriteSpeed * deltaTime;
        // cameraMovement.x += cameraSpeed * deltaTime;
    }

    // sprite->SetPosition(sprite->GetPosition() + spriteMovement);
    // camera2D.Move(cameraMovement);

    double mouseDeltaX = Input::GetMouseDeltaX();
    double mouseDeltaY = Input::GetMouseDeltaY();

    const float sensitivity = 0.1f;

    if (Input::IsActionDown(Action::Shoot))
    {
        camera.Rotate(
            static_cast<float>(mouseDeltaX) * sensitivity,
            static_cast<float>(mouseDeltaY) * sensitivity);
    }
}

void Application::Render()
{
    Renderer::Clear();

    RenderData renderData{
        transform.GetModelMatrix(),
        camera,
        lights};

    // Mat4 spriteView = camera2D.GetViewMatrix();
    // Mat4 spriteProjection = camera2D.GetProjectionMatrix();

    Renderer::DrawIndexed(*mesh, *material, renderData);

    // Renderer::DrawSprite(*sprite, *spriteShader, *vertexArray, *indexBuffer, spriteView, spriteProjection);

    Renderer::Present();
}