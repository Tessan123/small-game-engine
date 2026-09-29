#pragma once

#include "array.h"

enum class ShaderDataType
{
    Float,
    Float2,
    Float3,
    Float4
};

struct VertexBufferElement
{
    ShaderDataType type;
    unsigned int count;
    bool normalized;
};

class VertexBufferLayout
{
public:
    VertexBufferLayout() : stride(0)
    {
    }

    void Push(ShaderDataType type)
    {
        VertexBufferElement element;
        switch (type)
        {
        case ShaderDataType::Float:
            element.count = 1;
            break;
        case ShaderDataType::Float2:
            element.count = 2;
            break;
        case ShaderDataType::Float3:
            element.count = 3;
            break;
        case ShaderDataType::Float4:
            element.count = 4;
            break;
        }
        element.type = type;
        element.normalized = false;
        elements.PushBack(element);
        stride += element.count * sizeof(float);
    }

    const Array<VertexBufferElement> &GetElements() const
    {
        return elements;
    }

    unsigned int GetStride() const
    {
        return stride;
    }

private:
    Array<VertexBufferElement> elements;
    unsigned int stride;
};