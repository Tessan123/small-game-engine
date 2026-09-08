#include <iostream>
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"
#include "application.h"

int main()
{
    // std::cout << "My engine starting..." << std::endl;
    // Application app;
    // app.run();

    Vec4 a(1.0f, 2.0f, 3.0f, 4.0f);
    Vec4 b(2.0f, 3.0f, 4.0f, 5.0f);

    Vec4 sum = a + b;

    std::cout << "Sum: "
              << sum.x << ", "
              << sum.y << ", "
              << sum.z << ", "
              << sum.w
              << std::endl;

    std::cout << "Length: "
              << a.Length()
              << std::endl;

    std::cout << "Dot: "
              << a.Dot(b)
              << std::endl;

    return 0;
}