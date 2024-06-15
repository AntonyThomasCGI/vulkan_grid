#pragma once

#include <vulkan/vulkan.h>


class Instance
{
public:
    Instance();
    ~Instance();

    VkInstance getInstance();

private:
    VkInstance instance;

    void createInstance();
};
