
#include <stdexcept>
#include <iostream>

#include <vulkan/vk_enum_string_helper.h>

#include "surface.hpp"


Surface::Surface(Instance &instance, Window &window) : instance(instance)
{
    VkInstance inst = instance.getInstance();
    if (VkResult result = window.createSurface(inst, &surface); result != VK_SUCCESS) {
        std::cerr << string_VkResult(result) << std::endl;
        throw std::runtime_error("failed to create window surface!");
    }
}


Surface::~Surface()
{
    VkInstance inst = instance.getInstance();
    vkDestroySurfaceKHR(inst, surface, nullptr);
}
