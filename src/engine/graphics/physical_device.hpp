#pragma once

#include <vector>

#include "instance.hpp"
#include "surface.hpp"

class PhysicalDevice {

public:
    PhysicalDevice(Instance &instance, Surface &surface);
    ~PhysicalDevice();

    static const std::vector<const char*> deviceExtensions;

private:
    Instance &instance;
    Surface &surface;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

    void pickPhysicalDevice();
    bool isDeviceSuitable(VkPhysicalDevice device);
    bool checkDeviceExtensionSupport(VkPhysicalDevice device);
};
