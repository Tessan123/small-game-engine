#include "vertexArray.h"
#include "openGLLoader.h"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &rendererID);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &rendererID);
}

void VertexArray::Bind() const
{
    glBindVertexArray(rendererID);
}

void VertexArray::Unbind() const
{
    glBindVertexArray(0);
}

void VertexArray::AddVertexBuffer() const
{
    glVertexAttribPointer(
        0,
        2,
        GL_FLOAT,
        GL_FALSE,
        2 * sizeof(float),
        nullptr);

    glEnableVertexAttribArray(0);
}