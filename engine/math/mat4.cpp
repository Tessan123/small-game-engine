#include "mat4.h"
#include "vec4.h"
#include "vec3.h"
#include <xmmintrin.h>
#include <cmath>

Mat4::Mat4()
    : m{
          {1.0f, 0.0f, 0.0f, 0.0f},
          {0.0f, 1.0f, 0.0f, 0.0f},
          {0.0f, 0.0f, 1.0f, 0.0f},
          {0.0f, 0.0f, 0.0f, 1.0f}}
{
}

Mat4::Mat4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33)
    : m{
          {m00, m01, m02, m03},
          {m10, m11, m12, m13},
          {m20, m21, m22, m23},
          {m30, m31, m32, m33}}
{
}

Mat4 Mat4::operator+(const Mat4 &other) const
{
    return Mat4(
        m[0][0] + other.m[0][0],
        m[0][1] + other.m[0][1],
        m[0][2] + other.m[0][2],
        m[0][3] + other.m[0][3],

        m[1][0] + other.m[1][0],
        m[1][1] + other.m[1][1],
        m[1][2] + other.m[1][2],
        m[1][3] + other.m[1][3],

        m[2][0] + other.m[2][0],
        m[2][1] + other.m[2][1],
        m[2][2] + other.m[2][2],
        m[2][3] + other.m[2][3],

        m[3][0] + other.m[3][0],
        m[3][1] + other.m[3][1],
        m[3][2] + other.m[3][2],
        m[3][3] + other.m[3][3]);
}

Mat4 Mat4::operator-(const Mat4 &other) const
{
    return Mat4(
        m[0][0] - other.m[0][0],
        m[0][1] - other.m[0][1],
        m[0][2] - other.m[0][2],
        m[0][3] - other.m[0][3],

        m[1][0] - other.m[1][0],
        m[1][1] - other.m[1][1],
        m[1][2] - other.m[1][2],
        m[1][3] - other.m[1][3],

        m[2][0] - other.m[2][0],
        m[2][1] - other.m[2][1],
        m[2][2] - other.m[2][2],
        m[2][3] - other.m[2][3],

        m[3][0] - other.m[3][0],
        m[3][1] - other.m[3][1],
        m[3][2] - other.m[3][2],
        m[3][3] - other.m[3][3]);
}

Mat4 Mat4::operator*(const Mat4 &other) const
{
    Mat4 result;

    __m128 b0 = _mm_loadu_ps(&other.m[0][0]);
    __m128 b1 = _mm_loadu_ps(&other.m[1][0]);
    __m128 b2 = _mm_loadu_ps(&other.m[2][0]);
    __m128 b3 = _mm_loadu_ps(&other.m[3][0]);

    for (int row = 0; row < 4; row++)
    {
        __m128 a0 = _mm_set1_ps(m[row][0]);
        __m128 a1 = _mm_set1_ps(m[row][1]);
        __m128 a2 = _mm_set1_ps(m[row][2]);
        __m128 a3 = _mm_set1_ps(m[row][3]);

        __m128 r = _mm_add_ps(
            _mm_add_ps(_mm_mul_ps(a0, b0), _mm_mul_ps(a1, b1)),
            _mm_add_ps(_mm_mul_ps(a2, b2), _mm_mul_ps(a3, b3)));

        _mm_storeu_ps(&result.m[row][0], r);
    }

    return result;
}

Vec4 Mat4::operator*(const Vec4 &vector) const
{
    return Vec4(
        m[0][0] * vector.x +
            m[0][1] * vector.y +
            m[0][2] * vector.z +
            m[0][3] * vector.w,

        m[1][0] * vector.x +
            m[1][1] * vector.y +
            m[1][2] * vector.z +
            m[1][3] * vector.w,

        m[2][0] * vector.x +
            m[2][1] * vector.y +
            m[2][2] * vector.z +
            m[2][3] * vector.w,

        m[3][0] * vector.x +
            m[3][1] * vector.y +
            m[3][2] * vector.z +
            m[3][3] * vector.w);
}

Mat4 Mat4::operator*(float scalar) const
{
    Mat4 result;

    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            result.m[row][col] = m[row][col] * scalar;
        }
    }
    return result;
}

Mat4 Mat4::Translation(const Vec3 &translation)
{
    return Mat4(
        1.0f, 0.0f, 0.0f, translation.x,
        0.0f, 1.0f, 0.0f, translation.y,
        0.0f, 0.0f, 1.0f, translation.z,
        0.0f, 0.0f, 0.0f, 1.0f);
}

Mat4 Mat4::RotationX(float radians)
{
    float c = std::cos(radians);
    float s = std::sin(radians);

    return Mat4(
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, c, -s, 0.0f,
        0.0f, s, c, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f);
}

Mat4 Mat4::RotationY(float radians)
{
    float c = std::cos(radians);
    float s = std::sin(radians);

    return Mat4(
        c, 0.0f, s, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        -s, 0.0f, c, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f);
}

Mat4 Mat4::RotationZ(float radians)
{
    float c = std::cos(radians);
    float s = std::sin(radians);

    return Mat4(
        c, -s, 0.0f, 0.0f,
        s, c, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f);
}

Mat4 Mat4::Scale(const Vec3 &scale)
{
    return Mat4(
        scale.x, 0.0f, 0.0f, 0.0f,
        0.0f, scale.y, 0.0f, 0.0f,
        0.0f, 0.0f, scale.z, 0.0f,
        0.0f, 0.0f, 0.f, 1.0f);
}