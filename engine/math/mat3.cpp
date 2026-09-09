#include "mat3.h"
#include "vec3.h"

Mat3::Mat3()
    : m{
          {1.0f, 0.0f, 0.0f},
          {0.0f, 1.0f, 0.0f},
          {0.0f, 0.0f, 1.0f}}
{
}

Mat3::Mat3(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22)
    : m{
          {m00, m01, m02},
          {m10, m11, m12},
          {m20, m21, m22}}
{
}

Mat3 Mat3::operator+(const Mat3 &other) const
{
    return Mat3(
        m[0][0] + other.m[0][0],
        m[0][1] + other.m[0][1],
        m[0][2] + other.m[0][2],

        m[1][0] + other.m[1][0],
        m[1][1] + other.m[1][1],
        m[1][2] + other.m[1][2],

        m[2][0] + other.m[2][0],
        m[2][1] + other.m[2][1],
        m[2][2] + other.m[2][2]);
}

Mat3 Mat3::operator-(const Mat3 &other) const
{
    return Mat3(
        m[0][0] - other.m[0][0],
        m[0][1] - other.m[0][1],
        m[0][2] - other.m[0][2],

        m[1][0] - other.m[1][0],
        m[1][1] - other.m[1][1],
        m[1][2] - other.m[1][2],

        m[2][0] - other.m[2][0],
        m[2][1] - other.m[2][1],
        m[2][2] - other.m[2][2]);
}

Mat3 Mat3::operator*(const Mat3 &other) const
{
    return Mat3(
        m[0][0] * other.m[0][0] +
            m[0][1] * other.m[1][0] +
            m[0][2] * other.m[2][0],

        m[0][0] * other.m[0][1] +
            m[0][1] * other.m[1][1] +
            m[0][2] * other.m[2][1],

        m[0][0] * other.m[0][2] +
            m[0][1] * other.m[1][2] +
            m[0][2] * other.m[2][2],

        m[1][0] * other.m[0][0] +
            m[1][1] * other.m[1][0] +
            m[1][2] * other.m[2][0],

        m[1][0] * other.m[0][1] +
            m[1][1] * other.m[1][1] +
            m[1][2] * other.m[2][1],

        m[1][0] * other.m[0][2] +
            m[1][1] * other.m[1][2] +
            m[1][2] * other.m[2][2],

        m[2][0] * other.m[0][0] +
            m[2][1] * other.m[1][0] +
            m[2][2] * other.m[2][0],

        m[2][0] * other.m[0][1] +
            m[2][1] * other.m[1][1] +
            m[2][2] * other.m[2][1],

        m[2][0] * other.m[0][2] +
            m[2][1] * other.m[1][2] +
            m[2][2] * other.m[2][2]);
}

Vec3 Mat3::operator*(const Vec3 &vector) const
{
    return Vec3(
        m[0][0] * vector.x +
            m[0][1] * vector.y +
            m[0][2] * vector.z,

        m[1][0] * vector.x +
            m[1][1] * vector.y +
            m[1][2] * vector.z,

        m[2][0] * vector.x +
            m[2][1] * vector.y +
            m[2][2] * vector.z);
}

Mat3 Mat3::operator*(float scalar) const
{
    return Mat3(
        m[0][0] * scalar,
        m[0][1] * scalar,
        m[0][2] * scalar,

        m[1][0] * scalar,
        m[1][1] * scalar,
        m[1][2] * scalar,

        m[2][0] * scalar,
        m[2][1] * scalar,
        m[2][2] * scalar);
}