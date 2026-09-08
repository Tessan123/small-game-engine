#include <iostream>
#include "vec2.h"
#include "vec3.h"
#include "application.h"

int main()
{
    // std::cout << "My engine starting..." << std::endl;
    // Application app;
    // app.run();

    Vec3 a(1.0f, 0.0f, 0.0f);
    Vec3 b(0.0f, 1.0f, 0.0f);

    Vec3 result = a.Cross(b);

    std::cout << "Cross: "
              << result.x << ", "
              << result.y << ", "
              << result.z
              << std::endl;

    return 0;
}