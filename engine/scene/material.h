#pragma once

#include "vec3.h"

class Shader;
class Texture;

class Material
{
public:
    Material(Shader *shader, Texture *texture);

    Shader *GetShader() const;
    Texture *GetTexture() const;

    void SetColor(const Vec3 &color);
    void SetSpecularIntensity(float intensity);
    void SetShininess(float shininess);

    const Vec3 &GetColor() const;
    float GetSpecularIntensity() const;
    float GetShininess() const;

private:
    Shader *shader;
    Texture *texture;
    Vec3 color;
    float specularIntensity;
    float shininess;
};