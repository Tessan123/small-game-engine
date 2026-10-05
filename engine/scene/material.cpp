#include "material.h"

Material::Material(Shader *shader, Texture *texture)
    : shader(shader), texture(texture), color(1.0f, 1.0f, 1.0f),
      specularIntensity(1.0f), shininess(32.0f)
{
}

Shader *Material::GetShader() const
{
    return shader;
}

Texture *Material::GetTexture() const
{
    return texture;
}

void Material::SetColor(const Vec3 &newColor)
{
    color = newColor;
}

void Material::SetSpecularIntensity(float intensity)
{
    specularIntensity = intensity;
}

void Material::SetShininess(float newShininess)
{
    shininess = newShininess;
}

const Vec3 &Material::GetColor() const
{
    return color;
}

float Material::GetSpecularIntensity() const
{
    return specularIntensity;
}

float Material::GetShininess() const
{
    return shininess;
}