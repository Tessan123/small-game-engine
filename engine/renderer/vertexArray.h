#pragma once

class VertexArray
{
public:
    VertexArray();
    ~VertexArray();

    void Bind() const;
    void Unbind() const;

    void AddVertexBuffer() const;

private:
    unsigned int rendererID = 1;
};