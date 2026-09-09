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

    Vec3 cameraPosition(0.0f, 0.0f, 5.0f);
    Vec3 target(0.0f, 0.0f, 0.0f);
    Vec3 up(0.0f, 1.0f, 0.0f);

    Mat4 view = Mat4::LookAt(
        cameraPosition,
        target,
        up);

    Vec4 point(
        0.0f,
        0.0f,
        0.0f,
        1.0f);

    Vec4 result = view * point;

    std::cout << "Result: "
              << result.x << ", "
              << result.y << ", "
              << result.z << ", "
              << result.w
              << std::endl;

    return 0;
}