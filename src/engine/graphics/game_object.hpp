#pragma once

#include <memory>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "command_buffer.hpp"
#include "command_pool.hpp"
#include "geometry/shapes/square.hpp"
#include "shader.hpp"
#include "swap_chain.hpp"


class GameObject
{
public:

    GameObject(LogicalDevice &logicalDevice, CommandPool &commandPool, SwapChain &swapChain);
    ~GameObject();

    glm::vec2 translate;
    float rotate;
    glm::vec2 scale;

    void draw(CommandBuffer &commandBuffer, SwapChain &swapChain, uint32_t currentFrame);

private:
    std::unique_ptr<Shader> shader;
    std::unique_ptr<Square> mesh;
};
