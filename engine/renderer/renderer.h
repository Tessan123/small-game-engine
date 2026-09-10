#pragma once

struct GLFWwindow;

class VertexArray;
class IndexBuffer;
class Shader;
class Mat4;
class Renderer
{
public:
    static void Initialize(GLFWwindow *window);
    static void Clear();
    static void Present();

    static void DrawIndexed(
        const VertexArray &vertexArray, const IndexBuffer &indexBuffer, const Shader &shader, const Mat4 &model);
};