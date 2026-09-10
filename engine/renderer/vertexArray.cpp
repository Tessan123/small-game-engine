#include "vertexArray.h"
#include "openGLLoader.h"

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &rendererID);
}

VertexArray::~VertexArray()
{
    if (rendererID != 0)
    {
        glDeleteVertexArrays(1, &rendererID);
    }
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
        4 * sizeof(float),
        nullptr);

    glEnableVertexAttribArray(0);

    glVertexAttribPointer(
        1,
        2,
        GL_FLOAT,
        GL_FALSE,
        4 * sizeof(float),
        (void *)(2 * sizeof(float)));

    glEnableVertexAttribArray(1);
}