
#include <memory>

#include "graphics.hpp"

VulkanGraphics::VulkanGraphics(Window &window) : window(window)
{
    instance = std::make_unique<Instance>(window);
    surface = std::make_unique<Surface>(*instance.get(), window);
}


VulkanGraphics::~VulkanGraphics()
{
}


void VulkanGraphics::setPhysicalDevice(PhysicalDevice physicalDevice)
{
    this->physicalDevice = physicalDevice;
}
