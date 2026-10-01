#pragma once

struct GLFWwindow;

class VertexArray;
class IndexBuffer;
class Shader;
class Mat4;
class Texture;
class Sprite;
class DirectionalLight;
class Camera;
class Material;
class PointLight;
class Renderer
{
public:
    static void Initialize(GLFWwindow *window);
    static void Clear();
    static void Present();

    static void DrawIndexed(
        const VertexArray &vertexArray, const IndexBuffer &indexBuffer, const Material &material, const Mat4 &model, const Mat4 &view, const Mat4 &projection, const DirectionalLight &light, const PointLight &pointLight, const Camera &camera);

    static void DrawSprite(
        const Sprite &sprite, const Shader &shader, const VertexArray &vertexArray, const IndexBuffer &indexBuffer, const Mat4 &view, const Mat4 &projection);
};