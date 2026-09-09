#include "transform.h"

Transform::Transform()
    : position(0.0f, 0.0f, 0.0f), rotation(0.0f, 0.0f, 0.0f), scale(1.0f, 1.0f, 1.0f)
{
}

Mat4 Transform::GetModelMatrix() const
{
    Mat4 translation = Mat4::Translation(position);

    Mat4 rotationX = Mat4::RotationX(rotation.x);
    Mat4 rotationY = Mat4::RotationY(rotation.y);
    Mat4 rotationZ = Mat4::RotationZ(rotation.z);

    Mat4 scaling = Mat4::Scale(scale);

    return translation * rotationX * rotationY * rotationZ * scaling;
}