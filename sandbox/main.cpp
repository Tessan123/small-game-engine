#include <iostream>
#include <cmath>
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat2.h"
#include "mat3.h"
#include "mat4.h"
#include "application.h"

int main()
{
    // std::cout << "My engine starting..." << std::endl;
    // Application app;
    // app.run();

    float angle = 3.14159265359f / 2.0f;

    Mat4 rotation = Mat4::RotationZ(angle);

    Vec4 point(1.0f, 0.0f, 0.0f, 1.0f);

    Vec4 result = rotation * point;

    std::cout << "Result: "
              << result.x << ", "
              << result.y << ", "
              << result.z << ", "
              << result.w << std::endl;

    return 0;
}