#include "camera.h"

Camera::Camera(float fovRadians, float aspectRatio, float nearPlane, float farPlane)
    : position(0.0f, 0.0f, 3.0f), target(0.0f, 0.0f, 0.0f), up(0.0f, 1.0f, 0.0f),
      fovRadians(fovRadians), aspectRatio(aspectRatio), nearPlane(nearPlane), farPlane(farPlane)
{
}

Mat4 Camera::GetViewMatrix() const
{
    return Mat4::LookAt(position, target, up);
}

Mat4 Camera::GetProjectionMatrix() const
{
    return Mat4::Perspective(fovRadians, aspectRatio, nearPlane, farPlane);
}

void Camera::SetPosition(const Vec3 &newPosition)
{
    position = newPosition;
}

void Camera::SetTarget(const Vec3 &newTarget)
{
    target = newTarget;
}

void Camera::Move(const Vec3 &direction, float deltaTime)
{
    const float speed = 3.0f;

    position = position + direction * speed * deltaTime;
    target = target + direction * speed * deltaTime;
}