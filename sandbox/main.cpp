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

    Mat4 matrix;

    Vec4 vector(1.0f, 2.0f, 3.0f, 1.0f);

    Vec4 result = matrix * vector;

    std::cout << result.x << std::endl;
    std::cout << result.y << std::endl;
    std::cout << result.z << std::endl;
    std::cout << result.w << std::endl;

    return 0;
}