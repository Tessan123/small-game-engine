#include "vec2.h"
#include <cmath>

Vec2::Vec2()
    : x(0.0f), y(0.0f)
{
}

Vec2::Vec2(float x, float y)
    : x(x), y(y)
{
}

Vec2 Vec2::operator+(const Vec2 &other) const
{
    return Vec2(x + other.x, y + other.y);
}

Vec2 Vec2::operator-(const Vec2 &other) const
{
    return Vec2(x - other.x, y - other.y);
}

Vec2 Vec2::operator*(float scalar) const
{
    return Vec2(x * scalar, y * scalar);
}

Vec2 Vec2::operator/(float scalar) const
{
    return Vec2(x / scalar, y / scalar);
}

float Vec2::Length() const
{
    return std::sqrt(x * x + y * y);
}

Vec2 Vec2::Normalize() const
{
    float length = Length();

    if (length == 0.0f)
    {
        return Vec2(0.0f, 0.0f);
    }

    return Vec2(x / length, y / length);
}

float Vec2::Dot(const Vec2 &other) const
{
    return x * other.x + y * other.y;
}