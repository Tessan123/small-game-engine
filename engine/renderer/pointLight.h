#pragma once

#include "vec3.h"

class PointLight
{
public:
    PointLight();

    void SetPosition(const Vec3 &position);
    void SetColor(const Vec3 &color);
    void SetIntensity(float intensity);
    void SetConstant(float constant);
    void SetLinear(float linear);
    void SetQuadratic(float quadratic);

    Vec3 GetPosition() const;
    Vec3 GetColor() const;
    float GetIntensity() const;
    float GetConstant() const;
    float GetLinear() const;
    float GetQuadratic() const;

private:
    Vec3 position;
    Vec3 color;
    float intensity;
    float constant;
    float linear;
    float quadratic;
};