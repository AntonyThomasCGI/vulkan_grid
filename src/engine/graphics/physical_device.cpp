
#include <stdexcept>
#include <set>
#include <string>

#include "physical_device.hpp"


# ifdef __APPLE__
    const std::vector<const char*> PhysicalDevice::deviceExtensions = {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME,
        "VK_KHR_portability_subset"
    };
#else
    const std::vector<const char*> PhysicalDevice::deviceExtensions = {
        VK_KHR_SWAPCHAIN_EXTENSION_NAME
    };
#endif



PhysicalDevice::PhysicalDevice(Instance &instance, Surface &surface) : instance(instance), surface(surface)
{
}


PhysicalDevice::~PhysicalDevice()
{
}


QueueFamilyIndices PhysicalDevice::findQueueFamilies(VkPhysicalDevice device) {
    QueueFamilyIndices indicies;

    uint32_t queueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

    std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

    int i = 0;
    for (const auto& queueFamily : queueFamilies) {
        // Does device support graphics rendering.
        if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
            indicies.graphicsFamily = i;
        }
        // Does the device support our window surface.
        VkBool32 presentSupport = false;
        vkGetPhysicalDeviceSurfaceSupportKHR(device, i, surface.getSurface(), &presentSupport);
        if (presentSupport) {
            indicies.presentFamily = i;
        }

        if (indicies.isComplete()) {
            break;
        }
        i++;
    }

    return indicies;
}


SwapChainSupportDetails PhysicalDevice::querySwapChainSupport(VkPhysicalDevice device) {
    SwapChainSupportDetails details;

    auto vkSurface = surface.getSurface();

    vkGetPhysicalDeviceSurfaceCapabilitiesKHR(device, vkSurface, &details.capabilities);

    uint32_t formatCount;
    vkGetPhysicalDeviceSurfaceFormatsKHR(device, surface.getSurface(), &formatCount, nullptr);
    if (formatCount != 0) {
        details.formats.resize(formatCount);
        vkGetPhysicalDeviceSurfaceFormatsKHR(device, vkSurface, &formatCount, details.formats.data());
    }

    uint32_t presentModeCount;
    vkGetPhysicalDeviceSurfacePresentModesKHR(device, vkSurface, &presentModeCount, nullptr);
    if (presentModeCount != 0) {
        details.presentModes.resize(presentModeCount);
        vkGetPhysicalDeviceSurfacePresentModesKHR(device, vkSurface, &presentModeCount, details.presentModes.data());
    }

    return details;
}


void PhysicalDevice::pickPhysicalDevice() {
    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(instance.getInstance(), &deviceCount, nullptr);

    if (deviceCount == 0) {
        throw std::runtime_error("failed to find any GPUs with Vulkan support!");
    }

    std::vector<VkPhysicalDevice> devices(deviceCount);
    vkEnumeratePhysicalDevices(instance.getInstance(), &deviceCount, devices.data());

    for (const auto& device : devices) {
        if (isDeviceSuitable(device)) {
            physicalDevice = device;
            break;
        }
    }
    if (physicalDevice == VK_NULL_HANDLE) {
        throw std::runtime_error("failed to find a suitable GPU!");
    }
}


bool PhysicalDevice::isDeviceSuitable(VkPhysicalDevice device) {
    QueueFamilyIndices indicies = findQueueFamilies(device);

    bool extensionsSupported = checkDeviceExtensionSupport(device);

    bool swapChainAdequate = false;
    if (extensionsSupported) {
        SwapChainSupportDetails swapChainSupport = querySwapChainSupport(device);
        swapChainAdequate = !swapChainSupport.formats.empty() && !swapChainSupport.presentModes.empty();
    }

    return indicies.isComplete() && extensionsSupported && swapChainAdequate;
}


bool PhysicalDevice::checkDeviceExtensionSupport(VkPhysicalDevice device) {
    uint32_t extensionCount = 0;
    vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionCount, nullptr);

    std::vector<VkExtensionProperties> availableExtensions(extensionCount);
    vkEnumerateDeviceExtensionProperties(device, nullptr, &extensionCount, availableExtensions.data());

    std::set<std::string> requiredExtensions(deviceExtensions.begin(), deviceExtensions.end());

    for (const auto& extension : availableExtensions) {
        requiredExtensions.erase(extension.extensionName);
    }

    return requiredExtensions.empty();
}
