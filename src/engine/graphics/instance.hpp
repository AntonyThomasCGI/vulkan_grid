#pragma once

#include <vulkan/vulkan.h>

#include <vector>

#include "devices/window.hpp"


class Instance
{
public:
    Instance(Window &window);
    ~Instance();

    static const::std::vector<const char*> validationLayers;

    const VkInstance &getInstance() const { return instance; }

private:
    VkInstance instance;
    bool enableValidationLayers;

    bool checkValidationLayerSupport();
    void createInstance(Window &window);
};
