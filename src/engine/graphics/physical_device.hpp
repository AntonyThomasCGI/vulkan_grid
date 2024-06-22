#pragma once

#include <optional>
#include <vector>

#include "instance.hpp"
#include "surface.hpp"


struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;

    bool isComplete() {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};


struct SwapChainSupportDetails {
    VkSurfaceCapabilitiesKHR capabilities;
    std::vector<VkSurfaceFormatKHR> formats;
    std::vector<VkPresentModeKHR> presentModes;
};


class PhysicalDevice {

public:
    PhysicalDevice(Instance &instance, Surface &surface);
    ~PhysicalDevice();

    static const std::vector<const char*> deviceExtensions;

    QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);
    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
    void pickPhysicalDevice();

private:
    Instance &instance;
    Surface &surface;
    VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

    bool isDeviceSuitable(VkPhysicalDevice device);
    bool checkDeviceExtensionSupport(VkPhysicalDevice device);
};
