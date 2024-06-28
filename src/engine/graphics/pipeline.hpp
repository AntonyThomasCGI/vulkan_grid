#pragma once

#include "logical_device.hpp"
#include "render_pass.hpp"
#include "swap_chain.hpp"


class GraphicsPipeline
{
public:
    GraphicsPipeline(LogicalDevice &logicalDevice, SwapChain &swapChain, RenderPass &renderPass);
    ~GraphicsPipeline();

private:
    VkPipeline graphicsPipeline;
    VkPipelineLayout pipelineLayout;

    LogicalDevice &logicalDevice;
    SwapChain &swapChain;
    RenderPass &renderPass;

    void createGraphicsPipeline();
    VkShaderModule createShaderModule(const std::vector<char>& code);
};
