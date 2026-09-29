#pragma once

#include "vec2.h"
#include "mat4.h"

class Camera2D
{
public:
    Camera2D(float width, float height);

    void SetPosition(const Vec2 &position);
    void SetZoom(float zoom);

    void Move(const Vec2 &offset);
    void Zoom(float amount);

    const Vec2 &GetPosition() const;
    float GetZoom() const;

    Mat4 GetViewMatrix() const;
    Mat4 GetProjectionMatrix() const;

private:
    Vec2 position;
    float zoom;
    float width;
    float height;
};