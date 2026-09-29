#pragma once

#include "vertexBufferLayout.h"

class VertexArray
{
public:
    VertexArray();
    ~VertexArray();

    void Bind() const;
    void Unbind() const;

    void AddVertexBuffer(const VertexBufferLayout &layout) const;

private:
    unsigned int rendererID = 1;
};