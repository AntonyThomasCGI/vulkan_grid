#pragma once

#include <memory>

#include "devices/window.hpp"
#include "instance.hpp"
#include "physical_device.hpp"
#include "surface.hpp"

struct VulkanGraphicsInfo {
    Window *window;
};


class VulkanGraphics {

public:
    VulkanGraphics(Window &window);
    ~VulkanGraphics();

    void setPhysicalDevice(PhysicalDevice physicalDevice);

private:
    std::unique_ptr<Instance> instance;
    std::unique_ptr<Surface> surface;
    Window &window;
    PhysicalDevice physicalDevice;
};
