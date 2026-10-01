#include "pointLight.h"

PointLight::PointLight()
    : position(0.0f, 0.0f, 0.0f), color(1.0f, 1.0f, 1.0f), intensity(1.0f),
      constant(1.0f), linear(0.09f), quadratic(0.032f)
{
}

void PointLight::SetPosition(const Vec3 &position)
{
    this->position = position;
}

void PointLight::SetColor(const Vec3 &color)
{
    this->color = color;
}

void PointLight::SetIntensity(float intensity)
{
    this->intensity = intensity;
}

void PointLight::SetConstant(float constant)
{
    this->constant = constant;
}

void PointLight::SetLinear(float linear)
{
    this->linear = linear;
}

void PointLight::SetQuadratic(float quadratic)
{
    this->quadratic = quadratic;
}

Vec3 PointLight::GetPosition() const
{
    return position;
}

Vec3 PointLight::GetColor() const
{
    return color;
}

float PointLight::GetIntensity() const
{
    return intensity;
}

float PointLight::GetConstant() const
{
    return constant;
}

float PointLight::GetLinear() const
{
    return linear;
}

float PointLight::GetQuadratic() const
{
    return quadratic;
}