#pragma once

class VertexBuffer
{
public:
    VertexBuffer(const float *data, unsigned int size);
    ~VertexBuffer();

    void Bind() const;
    void Unbind() const;

private:
    unsigned int renderID = 0;
};