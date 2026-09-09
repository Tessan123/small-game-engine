#include <iostream>
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

    Vec3 translation(5.0f, 2.0f, 3.0f);

    Mat4 matrix = Mat4::Translation(translation);

    Vec4 point(1.0f, 1.0f, 1.0f, 1.0f);

    Vec4 result = matrix * point;

    std::cout << "Result: "
              << result.x << ", "
              << result.y << ", "
              << result.z << ", "
              << result.w << std::endl;

    return 0;
}