
#pragma once

#include "command_buffer.hpp"
#include "logical_device.hpp"
#include "shader.hpp"
#include "texture.hpp"


class Material
{
public:
    Material(LogicalDevice &logicalDevice);
    //Material(std::string vertShader, std::string fragShader, std::string texturePath);
    ~Material();

    void setShader(CommandPool &commandPool, SwapChain &swapChain, std::string vertShader, std::string fragShader);
    void setTexturePath(PhysicalDevice &physicalDevice, CommandPool &commandPool, std::string texturePath);

    void bind(CommandBuffer &commandBuffer, uint32_t currentFrame);

    void updateUniformBuffer(glm::mat4 transform, glm::vec3 color, uint32_t currentFrame, SwapChain &swapChain);

private:
    LogicalDevice &logicalDevice;

    std::unique_ptr<GraphicsPipeline> graphicsPipeline;
    std::unique_ptr<Shader> shader;
    std::unique_ptr<TextureImage> textureImage;

    VkDescriptorSetLayout descriptorSetLayout;
    std::vector<VkBuffer> uniformBuffers;
    std::vector<VkDeviceMemory> uniformBuffersMemory;
    std::vector<void*> uniformBuffersMapped;

    VkDescriptorPool descriptorPool;
    std::vector<VkDescriptorSet> descriptorSets;

    void createDescriptorSets(TextureImage &textureImage);
    void createDescriptorPool();
    void createUniformBuffers(CommandPool &commandPool);
    void createDescriptorSetLayout();
};
