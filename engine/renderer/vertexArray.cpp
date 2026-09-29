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

void VertexArray::AddVertexBuffer(const VertexBufferLayout &layout) const
{
    const auto &elements = layout.GetElements();

    unsigned int offset = 0;

    for (std::size_t i = 0; i < elements.Size(); i++)
    {
        const VertexBufferElement &element = elements[i];
        unsigned int glType = GL_FLOAT;

        glVertexAttribPointer(
            static_cast<unsigned int>(i),
            element.count,
            glType,
            element.normalized ? GL_TRUE : GL_FALSE,
            layout.GetStride(),
            reinterpret_cast<const void *>(offset));

        glEnableVertexAttribArray(static_cast<unsigned int>(i));
        offset += element.count * sizeof(float);
    }
}