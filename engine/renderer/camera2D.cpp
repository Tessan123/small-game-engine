#include "camera2D.h"
#include "vec3.h"

Camera2D::Camera2D(float width, float height)
    : position(width / 2.0f, height / 2.0f), zoom(1.0f), width(width), height(height)
{
}

void Camera2D::SetPosition(const Vec2 &newPosition)
{
    position = newPosition;
}

void Camera2D::SetZoom(float newZoom)
{
    zoom = newZoom;
}

void Camera2D::Move(const Vec2 &offset)
{
    position = position + offset;
}

void Camera2D::Zoom(float amount)
{
    zoom += amount;

    if (zoom < 0.1f)
    {
        zoom = 0.1f;
    }
}

const Vec2 &Camera2D::GetPosition() const
{
    return position;
}

float Camera2D::GetZoom() const
{
    return zoom;
}

Mat4 Camera2D::GetViewMatrix() const
{
    return Mat4::Translation(
        Vec3(
            -position.x,
            -position.y,
            0.0f));
}

Mat4 Camera2D::GetProjectionMatrix() const
{
    float halfWidth = width / (2.0f * zoom);
    float halfHeight = height / (2.0 * zoom);

    return Mat4::Orthographic(
        -halfWidth,
        halfWidth,
        -halfHeight,
        halfHeight,
        -1.0f,
        1.0f);
}
