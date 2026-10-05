#pragma once

#include "mat4.h"
#include "camera.h"
#include "sceneLights.h"

struct RenderData
{
    Mat4 model;
    const Camera &camera;
    const SceneLights &lights;
};