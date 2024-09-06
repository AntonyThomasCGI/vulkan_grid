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

    void move(glm::vec2 trans, float rot);

    glm::vec2 translate = glm::vec2(0.0f, 0.0f);
    float rotate = 0.0f;
    glm::vec2 scale = glm::vec3(100.0f);

    void draw(CommandBuffer &commandBuffer, SwapChain &swapChain, uint32_t currentFrame);

private:
    std::unique_ptr<Shader> shader;
    std::unique_ptr<Square> mesh;
};
