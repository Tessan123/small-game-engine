#pragma once

#include "vec3.h"

class DirectionalLight
{
public:
    DirectionalLight();

    void SetDirection(const Vec3 &direction);
    void SetColor(const Vec3 &color);
    void SetIntensity(float intensity);
    void SetAmbientIntensity(float intensity);

    const Vec3 &GetDirection() const;
    const Vec3 &GetColor() const;
    float GetIntensity() const;
    float GetAmbientIntensity() const;

private:
    Vec3 direction;
    Vec3 color;
    float intensity;
    float ambientIntensity;
};