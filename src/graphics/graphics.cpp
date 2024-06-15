
#include "graphics.hpp"

VulkanGraphics::VulkanGraphics()
{
    instance = std::make_unique<Instance>();
}


VulkanGraphics::~VulkanGraphics()
{
}


void VulkanGraphics::setPhysicalDevice(PhysicalDevice physicalDevice)
{
    this->physicalDevice = physicalDevice;
}