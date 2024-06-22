
#include <memory>

#include "graphics.hpp"

VulkanGraphics::VulkanGraphics(Window &window) : window(window)
{
    instance = std::make_unique<Instance>(window);
    surface = std::make_unique<Surface>(*instance.get(), window);
    physicalDevice = std::make_unique<PhysicalDevice>(*instance.get(), *surface.get());
    physicalDevice.get()->pickPhysicalDevice();
}


VulkanGraphics::~VulkanGraphics()
{
}
