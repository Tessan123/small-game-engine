#include "renderer.h"
#include "vertexArray.h"
#include "indexBuffer.h"
#include "shader.h"
#include "mat4.h"
#include "texture.h"
#include "sprite.h"
#include "vec3.h"
#include "camera.h"
#include "material.h"
#include "sceneLights.h"
#include "renderData.h"
#include "mesh.h"
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

void Renderer::DrawIndexed(const Mesh &mesh, const Material &material, const RenderData &renderData)
{
    const VertexArray &vertexArray = mesh.GetVertexArray();
    const IndexBuffer &indexBuffer = mesh.GetIndexBuffer();
    const Mat4 &model = renderData.model;
    const Camera &camera = renderData.camera;
    const SceneLights &lights = renderData.lights;
    Mat4 view = camera.GetViewMatrix();
    Mat4 projection = camera.GetProjectionMatrix();
    Shader *shader = material.GetShader();
    Texture *texture = material.GetTexture();
    shader->Bind();
    shader->SetMat4("u_Model", model);
    shader->SetMat4("u_View", view);
    shader->SetMat4("u_Projection", projection);

    shader->SetVec3(
        "u_LightDirection",
        lights.directional.GetDirection());

    shader->SetVec3(
        "u_LightColor",
        lights.directional.GetColor());

    shader->SetFloat(
        "u_LightIntensity",
        lights.directional.GetIntensity());

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
        lights.directional.GetAmbientIntensity());

    shader->SetVec3(
        "u_PointLightPosition",
        lights.point.GetPosition());

    shader->SetVec3(
        "u_PointLightColor",
        lights.point.GetColor());

    shader->SetFloat(
        "u_PointLightIntensity",
        lights.point.GetIntensity());

    shader->SetFloat(
        "u_PointLightConstant",
        lights.point.GetConstant());

    shader->SetFloat(
        "u_PointLightLinear",
        lights.point.GetLinear());

    shader->SetFloat(
        "u_PointLightQuadratic",
        lights.point.GetQuadratic());

    shader->SetVec3(
        "u_SpotLightPosition",
        lights.spot.GetPosition());

    shader->SetVec3(
        "u_SpotLightDirection",
        lights.spot.GetDirection());

    shader->SetVec3(
        "u_SpotLightColor",
        lights.spot.GetColor());

    shader->SetFloat(
        "u_SpotLightIntensity",
        lights.spot.GetIntensity());

    shader->SetFloat(
        "u_SpotLightConstant",
        lights.spot.GetConstant());

    shader->SetFloat(
        "u_SpotLightLinear",
        lights.spot.GetLinear());

    shader->SetFloat(
        "u_SpotLightQuadratic",
        lights.spot.GetQuadratic());

    shader->SetFloat(
        "u_SpotLightInnerCutoff",
        lights.spot.GetInnerCutoff());

    shader->SetFloat(
        "u_SpotLightOuterCutoff",
        lights.spot.GetOuterCutoff());

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