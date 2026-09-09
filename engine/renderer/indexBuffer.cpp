#include "indexBuffer.h"
#include "openGLLoader.h"

IndexBuffer::IndexBuffer(const unsigned int *data, unsigned int count)
    : count(count)
{
    glGenBuffers(1, &renderID);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderID);

    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER,
        count * sizeof(unsigned int),
        data,
        GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &renderID);
}

void IndexBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, renderID);
}

void IndexBuffer::Unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

unsigned int IndexBuffer::GetCount() const
{
    return count;
}