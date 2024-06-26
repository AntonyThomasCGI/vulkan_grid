#pragma once

#include "logical_device.hpp"
#include "swap_chain.hpp"


class RenderPass
{
public:
    RenderPass(LogicalDevice &logicalDevice, SwapChain &swapChain);
    ~RenderPass();

    VkRenderPass const getRenderPass() const { return renderPass; }

private:
    VkRenderPass renderPass;

    LogicalDevice &logicalDevice;
    SwapChain &swapChain;

    void createRenderPass();
};
