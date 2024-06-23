#pragma once

#include <vector>

#include "instance.hpp"
#include "surface.hpp"


class PhysicalDevice {

public:
    PhysicalDevice(Instance &instance, Surface &surface);
    ~PhysicalDevice();

    static const std::vector<const char*> deviceExtensions;

    const VkPhysicalDevice &getPhysicalDevice() const { return physicalDevice; }

    void pickPhysicalDevice();

private:
    Instance &instance;
    Surface &surface;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

    bool isDeviceSuitable(VkPhysicalDevice device);
    bool checkDeviceExtensionSupport(VkPhysicalDevice device);
};
