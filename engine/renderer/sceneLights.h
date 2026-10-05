#pragma once

#include "directionalLight.h"
#include "pointLight.h"
#include "spotLight.h"

struct SceneLights
{
    DirectionalLight directional;
    PointLight point;
    SpotLight spot;
};