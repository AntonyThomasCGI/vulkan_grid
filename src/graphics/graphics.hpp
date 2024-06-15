#pragma once

#include <memory>

#include "physical_device.hpp"
#include "instance.hpp"


class VulkanGraphics {

public:
    VulkanGraphics();
    ~VulkanGraphics();

    void setPhysicalDevice(PhysicalDevice physicalDevice);

private:
    std::unique_ptr<Instance> instance;
    PhysicalDevice physicalDevice;
};
