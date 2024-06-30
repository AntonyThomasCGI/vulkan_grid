
#include <stdexcept>

#include "command_buffer.hpp"


CommandBuffer::CommandBuffer(LogicalDevice &logicalDevice, CommandPool &commandPool)
{
    VkCommandBufferAllocateInfo allocInfo{};
    allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocInfo.commandPool = commandPool.getCommandPool();
    allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    allocInfo.commandBufferCount = 1;

    if (vkAllocateCommandBuffers(logicalDevice.getDevice(), &allocInfo, &commandBuffer) != VK_SUCCESS) {
        throw std::runtime_error("failed to allocate command buffers!");
    }
}


void CommandBuffer::start()
{
    vkResetCommandBuffer(commandBuffer, 0);
}


void CommandBuffer::end()
{

}


void CommandBuffer::submit()
{

}
