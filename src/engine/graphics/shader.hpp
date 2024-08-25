#pragma once

#include <memory>
#include <string>
#include <vector>

#include <vulkan/vulkan.h>

#include "command_pool.hpp"
#include "logical_device.hpp"
#include "pipeline.hpp"
#include "swap_chain.hpp"


class Shader
{
public:
    Shader(LogicalDevice &logicalDevice, CommandPool &commandPool, SwapChain &swapChain, std::string vertShader, std::string fragShader);
    ~Shader();

    void bind(VkCommandBuffer &commandBuffer, uint32_t currentFrame);
    void updateUniformBuffer(uint32_t currentFrame, SwapChain &swapChain);

    std::unique_ptr<GraphicsPipeline> graphicsPipeline;

private:
    LogicalDevice logicalDevice;
    CommandPool commandPool;

    VkDescriptorSetLayout descriptorSetLayout;

    VkShaderModule createShaderModule(const std::vector<char>& code);

    std::vector<VkBuffer> uniformBuffers;
    std::vector<VkDeviceMemory> uniformBuffersMemory;
    std::vector<void*> uniformBuffersMapped;

    VkDescriptorPool descriptorPool;
    std::vector<VkDescriptorSet> descriptorSets;

    void createDescriptorSets();
    void createDescriptorPool();
    void createUniformBuffers();
    void createDescriptorSetLayout();
};
