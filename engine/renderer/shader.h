#pragma once

class Mat4;
class Shader
{
public:
    Shader(const char *vertexPath, const char *fragmentPath);
    ~Shader();

    void Bind() const;
    void Unbind() const;

    void SetFloat(const char *name, float value) const;
    void SetMat4(const char *name, const Mat4 &matrix) const;

private:
    unsigned int rendererID = 0;
};