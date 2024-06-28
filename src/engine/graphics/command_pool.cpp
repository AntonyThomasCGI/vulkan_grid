
#include <stdexcept>

#include "command_pool.hpp"


CommandPool::CommandPool(PhysicalDevice &physicalDevice, LogicalDevice &logicalDevice, Surface &surface) : logicalDevice(logicalDevice)
{
    QueueFamilyIndices queueFamilyIndices = surface.findQueueFamilies(physicalDevice.getPhysicalDevice());

    VkCommandPoolCreateInfo poolInfo{};
    poolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    poolInfo.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    poolInfo.queueFamilyIndex = queueFamilyIndices.graphicsFamily.value();

    if (vkCreateCommandPool(logicalDevice.getDevice(), &poolInfo, nullptr, &commandPool) != VK_SUCCESS) {
        throw std::runtime_error("failed to create command pool!");
    }
}


CommandPool::~CommandPool()
{
    vkDestroyCommandPool(logicalDevice.getDevice(), commandPool, nullptr);
}
