#pragma once

#include "vec3.h"

class SpotLight
{
public:
    SpotLight();

    void SetPosition(const Vec3 &position);
    void SetDirection(const Vec3 &direction);
    void SetColor(const Vec3 &color);
    void SetIntensity(float intensity);

    void SetConstant(float constant);
    void SetLinear(float linear);
    void SetQuadratic(float quadratic);

    void SetInnerCutoff(float cutoff);
    void SetOuterCutoff(float cutoff);

    Vec3 GetPosition() const;
    Vec3 GetDirection() const;
    Vec3 GetColor() const;

    float GetIntensity() const;

    float GetConstant() const;
    float GetLinear() const;
    float GetQuadratic() const;

    float GetInnerCutoff() const;
    float GetOuterCutoff() const;

private:
    Vec3 position;
    Vec3 direction;
    Vec3 color;

    float intensity;

    float constant;
    float linear;
    float quadratic;

    float innerCutoff;
    float outerCutoff;
};