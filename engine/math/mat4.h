#pragma once

class Vec3;
class Vec4;

class Mat4
{
public:
    float m[4][4];

    Mat4();

    Mat4(float m00, float m01, float m02, float m03,
         float m10, float m11, float m12, float m13,
         float m20, float m21, float m22, float m23,
         float m30, float m31, float m32, float m33);

    static Mat4 Translation(const Vec3 &translation);

    static Mat4 RotationX(float radians);
    static Mat4 RotationY(float radians);
    static Mat4 RotationZ(float radians);

    static Mat4 Scale(const Vec3 &scale);

    static Mat4 Perspective(
        float fovRadians,
        float aspect,
        float nearPlane,
        float farPlane);

    static Mat4 LookAt(const Vec3 &position, const Vec3 &target, const Vec3 &up);

    Mat4 operator+(const Mat4 &other) const;
    Mat4 operator-(const Mat4 &other) const;

    Mat4 operator*(const Mat4 &other) const;
    Vec4 operator*(const Vec4 &other) const;

    Mat4 operator*(float scalar) const;
};