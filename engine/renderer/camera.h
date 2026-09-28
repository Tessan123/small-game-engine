#pragma once

#include "vec3.h"
#include "mat4.h"

class Camera
{
public:
    Camera(float fovRadians, float aspectRatio, float nearPlane, float farPlane);

    Mat4 GetViewMatrix() const;
    Mat4 GetProjectionMatrix() const;

    void SetPosition(const Vec3 &position);
    void SetTarget(const Vec3 &target);

    void Move(const Vec3 &direction, float deltaTime);

private:
    Vec3 position;
    Vec3 target;
    Vec3 up;

    float fovRadians;
    float aspectRatio;
    float nearPlane;
    float farPlane;
};