#pragma once

struct GLFWwindow;

class VertexArray;
class IndexBuffer;
class Shader;
class Mat4;
class Texture;
class Sprite;
class Camera;
class Material;
class SceneLights;
class RenderData;
class Mesh;
class Renderer
{
public:
    static void Initialize(GLFWwindow *window);
    static void Clear();
    static void Present();

    static void DrawIndexed(
        const Mesh &mesh, const Material &material, const RenderData &renderData);

    static void DrawSprite(
        const Sprite &sprite, const Shader &shader, const VertexArray &vertexArray, const IndexBuffer &indexBuffer, const Mat4 &view, const Mat4 &projection);
};