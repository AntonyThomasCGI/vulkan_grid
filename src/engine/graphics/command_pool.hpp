
#pragma once

#include <vulkan/vulkan.h>

#include "logical_device.hpp"
#include "surface.hpp"


class CommandPool
{
public:
    CommandPool(PhysicalDevice &physicalDevice, LogicalDevice &logicalDevice, Surface &surface);
    ~CommandPool();

private:
    VkCommandPool commandPool;

    LogicalDevice &logicalDevice;
};
