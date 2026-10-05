#include "spotLight.h"

SpotLight::SpotLight()
    : position(0.0f, 0.0f, 0.0f),
      direction(0.0f, 0.0f, -1.0f),
      color(1.0f, 1.0f, 1.0f),
      intensity(1.0f),
      constant(1.0f),
      linear(0.09f),
      quadratic(0.032f),
      innerCutoff(0.91f),
      outerCutoff(0.82f)
{
}

void SpotLight::SetPosition(const Vec3 &position)
{
    this->position = position;
}

void SpotLight::SetDirection(const Vec3 &direction)
{
    this->direction = direction;
}

void SpotLight::SetColor(const Vec3 &color)
{
    this->color = color;
}

void SpotLight::SetIntensity(float intensity)
{
    this->intensity = intensity;
}

void SpotLight::SetConstant(float constant)
{
    this->constant = constant;
}

void SpotLight::SetLinear(float linear)
{
    this->linear = linear;
}

void SpotLight::SetQuadratic(float quadratic)
{
    this->quadratic = quadratic;
}

void SpotLight::SetInnerCutoff(float cutoff)
{
    this->innerCutoff = cutoff;
}

void SpotLight::SetOuterCutoff(float cutoff)
{
    this->outerCutoff = cutoff;
}

Vec3 SpotLight::GetPosition() const
{
    return position;
}

Vec3 SpotLight::GetDirection() const
{
    return direction;
}

Vec3 SpotLight::GetColor() const
{
    return color;
}

float SpotLight::GetIntensity() const
{
    return intensity;
}

float SpotLight::GetConstant() const
{
    return constant;
}

float SpotLight::GetLinear() const
{
    return linear;
}

float SpotLight::GetQuadratic() const
{
    return quadratic;
}

float SpotLight::GetInnerCutoff() const
{
    return innerCutoff;
}

float SpotLight::GetOuterCutoff() const
{
    return outerCutoff;
}