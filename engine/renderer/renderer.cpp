#include "renderer.h"
#include "vertexArray.h"
#include "indexBuffer.h"
#include "shader.h"
#include "mat4.h"
#include "texture.h"
#include <GLFW/glfw3.h>

namespace
{
    GLFWwindow *window = nullptr;
}

void Renderer::Initialize(GLFWwindow *glfwWindow)
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

void Renderer::DrawIndexed(const VertexArray &vertexArray, const IndexBuffer &indexBuffer, const Shader &shader, const Mat4 &model, const Texture &texture)
{
    shader.Bind();
    //shader.SetFloat("red", 1.0f);
    shader.SetMat4("u_Model", model);

    texture.Bind(0);
    shader.SetInt("u_Texture", 0);

    vertexArray.Bind();

    glDrawElements(
        GL_TRIANGLES,
        indexBuffer.GetCount(),
        GL_UNSIGNED_INT,
        nullptr);

    vertexArray.Unbind();

    texture.Unbind();
    shader.Unbind();
}