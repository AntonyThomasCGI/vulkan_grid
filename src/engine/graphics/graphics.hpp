#pragma once

#include <memory>

#include "devices/window.hpp"
#include "instance.hpp"
#include "logical_device.hpp"
#include "physical_device.hpp"
#include "surface.hpp"
#include "swap_chain.hpp"


struct VulkanGraphicsInfo {
    Window *window;
};


class VulkanGraphics {

public:
    VulkanGraphics(Window &window);
    ~VulkanGraphics();

private:
    Window &window;
    std::unique_ptr<Instance> instance;
    std::unique_ptr<Surface> surface;
    std::unique_ptr<PhysicalDevice> physicalDevice;
    std::unique_ptr<LogicalDevice> device;
    std::unique_ptr<SwapChain> swapChain;
};
