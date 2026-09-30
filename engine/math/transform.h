#pragma once

#include "vec3.h"
#include "mat4.h"

class Transform
{
public:
    Transform();

    Mat4 GetModelMatrix() const;

    void SetRotation(const Vec3 &newRotation);
    const Vec3 &GetRotation() const;

private:
    Vec3 position;
    Vec3 rotation;
    Vec3 scale;
};