#pragma once

class Shader
{
public:
    Shader(const char *vertexPath, const char *fragmentPath);
    ~Shader();

    void Bind() const;
    void Unbind() const;

private:
    unsigned int rendererID;
};