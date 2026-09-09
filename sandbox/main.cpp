#include <iostream>
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "mat2.h"
#include "mat3.h"
#include "application.h"

int main()
{
    // std::cout << "My engine starting..." << std::endl;
    // Application app;
    // app.run();

    Mat3 matrix(
        1.0f, 2.0f, 3.0f,
        4.0f, 5.0f, 6.0f,
        7.0f, 8.0f, 9.0f);

    Vec3 vector(1.0f, 2.0f, 3.0f);

    Vec3 result = matrix * vector;

    std::cout << result.x << ", "
              << result.y << ", "
              << result.z
              << std::endl;

    return 0;
}