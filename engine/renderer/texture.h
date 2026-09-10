#pragma once

class Texture
{
public:
    Texture(const char* path);
    ~Texture();

    void Bind(unsigned int slot = 0) const;
    void Unbind() const;

private:
    unsigned int rendererID = 0;
};