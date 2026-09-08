#include "vec4.h"
#include <cmath>

Vec4::Vec4()
    : x(0.0f), y(0.0f), z(0.0f), w(0.0f)
{
}

Vec4::Vec4(float x, float y, float z, float w)
    : x(x), y(y), z(z), w(w)
{
}

Vec4 Vec4::operator+(const Vec4 &other) const
{
    return Vec4(x + other.x, y + other.y, z + other.z, w + other.w);
}

Vec4 Vec4::operator-(const Vec4 &other) const
{
    return Vec4(x - other.x, y - other.y, z - other.z, w - other.w);
}

Vec4 Vec4::operator*(float scalar) const
{
    return Vec4(x * scalar, y * scalar, z * scalar, w * scalar);
}

Vec4 Vec4::operator/(float scalar) const
{
    return Vec4(x / scalar, y / scalar, z / scalar, w / scalar);
}

float Vec4::Length() const
{
    return std::sqrt(x * x + y * y + z * z + w * w);
}

Vec4 Vec4::Normalize() const
{
    float length = Length();

    if (length == 0.0f)
    {
        return Vec4(0.0f, 0.0f, 0.0f, 0.0f);
    }

    return Vec4(x / length, y / length, z / length, w / length);
}

float Vec4::Dot(const Vec4 &other) const
{
    return x * other.x + y * other.y + z * other.z + w * other.w;
}