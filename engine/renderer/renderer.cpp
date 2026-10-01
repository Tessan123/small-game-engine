#include "renderer.h"
#include "vertexArray.h"
#include "indexBuffer.h"
#include "shader.h"
#include "mat4.h"
#include "texture.h"
#include "sprite.h"
#include "vec3.h"
#include "directionalLight.h"
#include "camera.h"
#include "material.h"
#include "pointLight.h"
#include <GLFW/glfw3.h>

namespace
{
    GLFWwindow *window = nullptr;
}

void Renderer::Initialize(GLFWwindow *glfwWindow)
{
    window = glfwWindow;
    glEnable(GL_DEPTH_TEST);
}

void Renderer::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::Present()
{
    glfwSwapBuffers(window);
}

void Renderer::DrawIndexed(const VertexArray &vertexArray, const IndexBuffer &indexBuffer, const Material &material, const Mat4 &model, const Mat4 &view, const Mat4 &projection, const DirectionalLight &light, const PointLight &pointLight, const Camera &camera)
{
    Shader *shader = material.GetShader();
    Texture *texture = material.GetTexture();
    shader->Bind();
    shader->SetMat4("u_Model", model);
    shader->SetMat4("u_View", view);
    shader->SetMat4("u_Projection", projection);

    shader->SetVec3(
        "u_LightDirection",
        light.GetDirection());

    shader->SetVec3(
        "u_LightColor",
        light.GetColor());

    shader->SetFloat(
        "u_LightIntensity",
        light.GetIntensity());

    shader->SetFloat(
        "u_SpecularIntensity",
        material.GetSpecularIntensity());

    shader->SetFloat(
        "u_Shininess",
        material.GetShininess());

    shader->SetVec3(
        "u_CameraPosition",
        camera.GetPosition());
    shader->SetVec3(
        "u_Color",
        material.GetColor());

    shader->SetFloat(
        "u_AmbientIntensity",
        light.GetAmbientIntensity());

    shader->SetVec3(
        "u_PointLightPosition",
        pointLight.GetPosition());

    shader->SetVec3(
        "u_PointLightColor",
        pointLight.GetColor());

    shader->SetFloat(
        "u_PointLightIntensity",
        pointLight.GetIntensity());

    shader->SetFloat(
        "u_PointLightConstant",
        pointLight.GetConstant());

    shader->SetFloat(
        "u_PointLightLinear",
        pointLight.GetLinear());

    shader->SetFloat(
        "u_PointLightQuadratic",
        pointLight.GetQuadratic());

    texture->Bind(0);
    shader->SetInt("u_Texture", 0);

    vertexArray.Bind();

    glDrawElements(
        GL_TRIANGLES,
        indexBuffer.GetCount(),
        GL_UNSIGNED_INT,
        nullptr);

    vertexArray.Unbind();

    texture->Unbind();
    shader->Unbind();
}

void Renderer::DrawSprite(
    const Sprite &sprite, const Shader &shader, const VertexArray &vertexArray, const IndexBuffer &indexBuffer, const Mat4 &view, const Mat4 &projection)
{
    Mat4 model = Mat4::Translation(
                     Vec3(
                         sprite.GetPosition().x,
                         sprite.GetPosition().y,
                         0.0f)) *
                 Mat4::RotationZ(sprite.GetRotation()) *
                 Mat4::Scale(
                     Vec3(
                         sprite.GetSize().x,
                         sprite.GetSize().y,
                         0.0f));
    shader.Bind();

    shader.SetMat4("u_Model", model);
    shader.SetMat4("u_View", view);
    shader.SetMat4("u_Projection", projection);

    sprite.GetTexture()->Bind(0);
    shader.SetInt("u_Texture", 0);

    vertexArray.Bind();

    glDrawElements(
        GL_TRIANGLES,
        indexBuffer.GetCount(),
        GL_UNSIGNED_INT,
        nullptr);

    vertexArray.Unbind();

    sprite.GetTexture()->Unbind();
    shader.Unbind();
}