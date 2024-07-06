#pragma once


#include "command_pool.hpp"
#include "logical_device.hpp"


class CommandBuffer
{
public:
    CommandBuffer();
    CommandBuffer(LogicalDevice &logicalDevice, CommandPool &commandPool);

    void start();
    void end();
    void submit();

    VkCommandBuffer &getCommandBuffer() { return commandBuffer; }

private:
    VkCommandBuffer commandBuffer;
};
