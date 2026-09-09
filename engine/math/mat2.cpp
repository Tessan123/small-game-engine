#include "mat2.h"
#include "vec2.h"

Mat2::Mat2()
    : m{
          {1.0f, 0.0f},
          {0.0f, 1.0f}}
{
}

Mat2::Mat2(float m00, float m01, float m10, float m11)
    : m{
          {m00, m01},
          {m10, m11}}
{
}

Mat2 Mat2::operator+(const Mat2 &other) const
{
    return Mat2(
        m[0][0] + other.m[0][0],
        m[0][1] + other.m[0][1],
        m[1][0] + other.m[1][0],
        m[1][1] + other.m[1][1]);
}

Mat2 Mat2::operator-(const Mat2 &other) const
{
    return Mat2(
        m[0][0] - other.m[0][0],
        m[0][1] - other.m[0][1],
        m[1][0] - other.m[1][0],
        m[1][1] - other.m[1][1]);
}

Mat2 Mat2::operator*(const Mat2 &other) const
{
    return Mat2(
        m[0][0] * other.m[0][0] +
            m[0][1] * other.m[1][0],

        m[0][0] * other.m[0][1] +
            m[0][1] * other.m[1][1],

        m[1][0] * other.m[0][0] +
            m[1][1] * other.m[1][0],

        m[1][0] * other.m[0][1] +
            m[1][1] * other.m[1][1]);
}

Vec2 Mat2::operator*(const Vec2 &vector) const
{
    return Vec2(
        m[0][0] * vector.x + m[0][1] * vector.y,
        m[1][0] * vector.x + m[1][1] * vector.y);
}

Mat2 Mat2::operator*(float scalar) const
{
    return Mat2(
        m[0][0] * scalar,
        m[0][1] * scalar,
        m[1][0] * scalar,
        m[1][1] * scalar);
}