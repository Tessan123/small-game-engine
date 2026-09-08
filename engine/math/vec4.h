#pragma once

class Vec4
{
public:
    float x;
    float y;
    float z;
    float w;

    Vec4();
    Vec4(float x, float y, float z, float w);

    Vec4 operator+(const Vec4 &other) const;
    Vec4 operator-(const Vec4 &other) const;

    Vec4 operator*(float scalar) const;
    Vec4 operator/(float scalar) const;

    float Length() const;
    Vec4 Normalize() const;

    float Dot(const Vec4 &other) const;
};