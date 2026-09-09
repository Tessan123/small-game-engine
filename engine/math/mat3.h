#pragma once

class Vec3;

class Mat3
{
public:
    float m[3][3];

    Mat3();

    Mat3(float m00, float m01, float m02,
         float m10, float m11, float m12,
         float m20, float m21, float m22);

    Mat3 operator+(const Mat3 &other) const;
    Mat3 operator-(const Mat3 &other) const;

    Mat3 operator*(const Mat3 &other) const;
    Vec3 operator*(const Vec3 &other) const;

    Mat3 operator*(float scalar) const;
};