#include "mesh.h"

#include "vertexArray.h"
#include "vertexBuffer.h"
#include "indexBuffer.h"
#include "vertexBufferLayout.h"

namespace
{
    const float cubeVertices[] =
        {
            // Front (+Z)
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
            0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
            0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f,
            -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,

            // Back (-Z)
            -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 0.0f,
            -0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 1.0f, 1.0f,
            0.5f, 0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f,
            0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f,

            // Left (-X)
            -0.5f, -0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            -0.5f, -0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
            -0.5f, 0.5f, 0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
            -0.5f, 0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 0.0f, 1.0f,

            // Right (+X)
            0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
            0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
            0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f,
            0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,

            // Top (+Y)
            -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f,
            -0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
            0.5f, 0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
            0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,

            // Bottom (-Y)
            -0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 1.0f,
            0.5f, -0.5f, -0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 1.0f,
            0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f,
            -0.5f, -0.5f, 0.5f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f};

    const unsigned int cubeIndices[] =
        {
            0, 1, 2, 2, 3, 0,
            4, 5, 6, 6, 7, 4,
            8, 9, 10, 10, 11, 8,
            12, 13, 14, 14, 15, 12,
            16, 17, 18, 18, 19, 16,
            20, 21, 22, 22, 23, 20};
}

Mesh::~Mesh() = default;

Mesh::Mesh(
    const float *vertices,
    unsigned int vertexSize,
    const unsigned int *indices,
    unsigned int indexCount)
{
    vertexArray = std::make_unique<VertexArray>();

    vertexArray->Bind();

    vertexBuffer =
        std::make_unique<VertexBuffer>(
            vertices,
            vertexSize);

    VertexBufferLayout layout;

    layout.Push(ShaderDataType::Float3);
    layout.Push(ShaderDataType::Float3);
    layout.Push(ShaderDataType::Float2);

    vertexArray->AddVertexBuffer(layout);

    indexBuffer =
        std::make_unique<IndexBuffer>(
            indices,
            indexCount);

    vertexArray->Unbind();
}

const VertexArray &Mesh::GetVertexArray() const
{
    return *vertexArray;
}

const IndexBuffer &Mesh::GetIndexBuffer() const
{
    return *indexBuffer;
}

std::unique_ptr<Mesh> Mesh::CreateCube()
{
    return std::make_unique<Mesh>(
        cubeVertices,
        sizeof(cubeVertices),
        cubeIndices,
        36);
}