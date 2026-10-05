#pragma once

#include <memory>

class VertexArray;
class VertexBuffer;
class IndexBuffer;

class Mesh
{
public:
    Mesh(
        const float *vertices,
        unsigned int vertexSize,
        const unsigned int *indices,
        unsigned int indexCount);
    ~Mesh();

    const VertexArray &GetVertexArray() const;
    const IndexBuffer &GetIndexBuffer() const;

    static std::unique_ptr<Mesh> CreateCube();

private:
    std::unique_ptr<VertexArray> vertexArray;
    std::unique_ptr<VertexBuffer> vertexBuffer;
    std::unique_ptr<IndexBuffer> indexBuffer;
};