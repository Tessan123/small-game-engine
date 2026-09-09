#include "vertexBuffer.h"
#include "openGLLoader.h"
#include <GLFW/glfw3.h>

VertexBuffer::VertexBuffer(const float *data, unsigned int size)
{
    glGenBuffers(1, &renderID);

    glBindBuffer(GL_ARRAY_BUFFER, renderID);

    glBufferData(
        GL_ARRAY_BUFFER,
        size,
        data,
        GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &renderID);
}

void VertexBuffer::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, renderID);
}

void VertexBuffer::Unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}