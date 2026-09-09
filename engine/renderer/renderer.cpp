#include "renderer.h"
#include <GLFW/glfw3.h>

void Renderer::Initialize()
{
    // opengl init go here
}

void Renderer::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Present()
{
    // swap buffers will be handled by the window
}