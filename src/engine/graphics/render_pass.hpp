#pragma once

#include "logical_device.hpp"


class RenderPass
{
public:
    RenderPass(LogicalDevice &logicalDevice, VkFormat &imageFormat);
    ~RenderPass();

    VkRenderPass const getRenderPass() const { return renderPass; }

private:
    VkRenderPass renderPass;
    VkFormat imageFormat;

    LogicalDevice &logicalDevice;

    void createRenderPass();
};
