#include "renderer.h"
#include "vertexArray.h"
#include "indexBuffer.h"
#include <GLFW/glfw3.h>

namespace
{
    GLFWwindow *window = nullptr;
}

void Renderer::Initialize(GLFWwindow* glfwWindow)
{
    window = glfwWindow;
}

void Renderer::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::Present()
{
    glfwSwapBuffers(window);
}

void Renderer::DrawIndexed(const VertexArray &vertexArray, const IndexBuffer &indexBuffer)
{
    vertexArray.Bind();

    glDrawElements(
        GL_TRIANGLES,
        indexBuffer.GetCount(),
        GL_UNSIGNED_INT,
        nullptr);

    vertexArray.Unbind();
}