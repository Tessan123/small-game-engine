#pragma once

#include "vec3.h"
#include "mat4.h"

class Transform
{
public:
    Transform();

    Vec3 position;
    Vec3 rotation;
    Vec3 scale;

    Mat4 GetModelMatrix() const;
};