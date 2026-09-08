#pragma once

class Vec2
{
public:
    float x;
    float y;

    Vec2();
    Vec2(float x, float y);

    Vec2 operator+(const Vec2 &other) const;
    Vec2 operator-(const Vec2 &other) const;

    Vec2 operator*(float scalar) const;
    Vec2 operator/(float scalar) const;

    float Length() const;
    Vec2 Normalize() const;

    float Dot(const Vec2 &other) const;
};