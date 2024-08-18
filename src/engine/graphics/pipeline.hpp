#pragma once

#include "logical_device.hpp"
#include "render_pass.hpp"
#include "swap_chain.hpp"


class GraphicsPipeline
{
public: GraphicsPipeline(LogicalDevice &logicalDevice, SwapChain &swapChain, VkDescriptorSetLayout &descriptorSet);
    ~GraphicsPipeline();

    VkPipeline getGraphicsPipeline() const { return graphicsPipeline; }
    VkPipelineLayout pipelineLayout;

private:
    VkPipeline graphicsPipeline;

    LogicalDevice &logicalDevice;
    SwapChain &swapChain;

    void createGraphicsPipeline(VkDescriptorSetLayout &descriptorSet);
    VkShaderModule createShaderModule(const std::vector<char>& code);
};
