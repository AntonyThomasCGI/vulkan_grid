#pragma once

#include "logical_device.hpp"
#include "render_pass.hpp"
#include "swap_chain.hpp"


class GraphicsPipeline
{
public:
    GraphicsPipeline(LogicalDevice &logicalDevice, SwapChain &swapChain);
    ~GraphicsPipeline();

    VkPipeline getGraphicsPipeline() const { return graphicsPipeline; }

private:
    VkPipeline graphicsPipeline;
    VkPipelineLayout pipelineLayout;

    LogicalDevice &logicalDevice;
    SwapChain &swapChain;

    void createGraphicsPipeline();
    VkShaderModule createShaderModule(const std::vector<char>& code);
};
