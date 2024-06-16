#pragma once

#include "vulkan/vulkan.h"

#include "devices/window.hpp"
#include "instance.hpp"

class Surface {

public:
    Surface(Instance &instance, Window &window);
    ~Surface();

private:
    Instance &instance;
    VkSurfaceKHR surface;
};
