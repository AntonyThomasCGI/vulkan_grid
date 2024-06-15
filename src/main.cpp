
#define GLFW_INCLUDE_VULKAN

#include <iostream>

#include "graphics/graphics.hpp"


int main() {
    std::cout << "start" << std::endl;

    VulkanGraphics graphics = VulkanGraphics();

    std::cout << "end" << std::endl;

    return 0;
}
