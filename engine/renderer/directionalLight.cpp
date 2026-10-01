#include "directionalLight.h"

DirectionalLight::DirectionalLight()
    : direction(-1.0f, -1.0f, -1.0f), color(1.0f, 1.0f, 1.0f), intensity(1.0f), ambientIntensity(0.2f)
{
}

void DirectionalLight::SetDirection(const Vec3 &newDirection)
{
    direction = newDirection;
}

void DirectionalLight::SetColor(const Vec3 &newColor)
{
    color = newColor;
}

void DirectionalLight::SetIntensity(float newIntensity)
{
    intensity = newIntensity;
}

void DirectionalLight::SetAmbientIntensity(float newIntensity)
{
    ambientIntensity = newIntensity;
}

const Vec3 &DirectionalLight::GetDirection() const
{
    return direction;
}

const Vec3 &DirectionalLight::GetColor() const
{
    return color;
}

float DirectionalLight::GetIntensity() const
{
    return intensity;
}

float DirectionalLight::GetAmbientIntensity() const
{
    return ambientIntensity;
}