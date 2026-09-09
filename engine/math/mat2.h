#pragma once

class Vec2;

class Mat2
{
public:
    float m[2][2];

    Mat2();

    Mat2(float m00, float m01, float m10, float m11);

    Mat2 operator+(const Mat2 &other) const;
    Mat2 operator-(const Mat2 &other) const;

    Mat2 operator*(const Mat2 &other) const;
    Vec2 operator*(const Vec2 &other) const;

    Mat2 operator*(float scalar) const;
};