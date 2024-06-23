#pragma once

#include <vector>

#include "devices/window.hpp"
#include "logical_device.hpp"
#include "physical_device.hpp"
#include "surface.hpp"


class SwapChain
{
public:
    SwapChain(Surface &surface, PhysicalDevice &physicalDevice, LogicalDevice &logicalDevice, Window &window);
    ~SwapChain();

    void SwapChain::cleanupSwapChain();

    const VkSwapchainKHR &getSwapChain() const { return swapChain; }

private:
    VkSwapchainKHR swapChain;
    std::vector<VkImage> swapChainImages;
    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;

    Surface &surface;
    PhysicalDevice &physicalDevice;
    LogicalDevice &logicalDevice;
    Window &window;

    std::vector<VkImageView> swapChainImageViews;
    std::vector<VkFramebuffer> swapChainFramebuffers;

    VkRenderPass renderPass = VK_NULL_HANDLE;
    void setRenderPass(VkRenderPass rp);

    void createSwapChain();
    void createImageViews();
    void createFramebuffers();

    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
};
