#include "vec3.h"
#include <cmath>

Vec3::Vec3()
    : x(0.0f), y(0.0f), z(0.0f)
{
}

Vec3::Vec3(float x, float y, float z)
    : x(x), y(y), z(z)
{
}

Vec3 Vec3::operator+(const Vec3 &other) const
{
    return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3 Vec3::operator-(const Vec3 &other) const
{
    return Vec3(x - other.x, y - other.y, z - other.z);
}

Vec3 Vec3::operator*(float scalar) const
{
    return Vec3(x * scalar, y * scalar, z * scalar);
}

Vec3 Vec3::operator/(float scalar) const
{
    return Vec3(x / scalar, y / scalar, z / scalar);
}

float Vec3::Length() const
{
    return std::sqrt(x * x + y * y + z * z);
}

Vec3 Vec3::Normalize() const
{
    float length = Length();

    if (length == 0.0f)
    {
        return Vec3(0.0f, 0.0f, 0.0f);
    }

    return Vec3(x / length, y / length, z / length);
}

float Vec3::Dot(const Vec3 &other) const
{
    return x * other.x + y * other.y + z * other.z;
}

Vec3 Vec3::Cross(const Vec3 &other) const
{
    return Vec3(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}