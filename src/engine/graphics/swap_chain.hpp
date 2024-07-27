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

    void cleanupSwapChain();
    void setRenderPass(VkRenderPass rp);
    void createFramebuffers();

    const VkSwapchainKHR &getSwapChain() const { return swapChain; }

    const VkFramebuffer &getFramebuffer(int index) const { return swapChainFramebuffers[index]; }

    VkFormat swapChainImageFormat;
    VkExtent2D swapChainExtent;

private:
    VkSwapchainKHR swapChain;
    std::vector<VkImage> swapChainImages;

    Surface &surface;
    PhysicalDevice &physicalDevice;
    LogicalDevice &logicalDevice;
    Window &window;

    std::vector<VkImageView> swapChainImageViews;
    std::vector<VkFramebuffer> swapChainFramebuffers;

    VkRenderPass renderPass = VK_NULL_HANDLE;

    void createSwapChain();
    void createImageViews();

    VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
    VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
};
