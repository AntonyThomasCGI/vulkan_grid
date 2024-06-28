#pragma once

#include <vector>

#include "graphics/command_pool.hpp"

#include "vertex.hpp"


class Mesh
{

public:
    Mesh(LogicalDevice *logicalDevice, std::vector<Vertex> vertices, std::vector<uint16_t> indicies = {});
    ~Mesh();

    void createBuffers(CommandPool &commandPool);

private:
    LogicalDevice *logicalDevice;
    std::vector<Vertex> vertices;
    std::vector<uint16_t> indicies;

    VkBuffer vertexBuffer;
    VkDeviceMemory vertexBufferMemory;
    VkBuffer indexBuffer;
    VkDeviceMemory indexBufferMemory;

    void createVertexBuffer(CommandPool &commandPool);
    void createIndexBuffer(CommandPool &commandPool);
};
