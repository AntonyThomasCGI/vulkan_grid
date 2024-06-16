
#include <stdexcept>

#include "surface.hpp"


Surface::Surface(Instance *instance, Window *window)
{
    VkInstance inst = instance->getInstance();
    if (window->createSurface(inst, &surface) != VK_TRUE) {
    }
}


Surface::~Surface()
{
}
