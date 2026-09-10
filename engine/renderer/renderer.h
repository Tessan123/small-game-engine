#pragma once

struct GLFWwindow;

class VertexArray;
class IndexBuffer;
class Renderer
{
public:
    static void Initialize(GLFWwindow* window);
    static void Clear();
    static void Present();

    static void DrawIndexed(
        const VertexArray &vertexArray, const IndexBuffer &indexBuffer);
};