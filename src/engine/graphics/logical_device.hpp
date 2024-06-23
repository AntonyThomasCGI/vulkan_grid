#pragma once


#include "physical_device.hpp"
#include "surface.hpp"


class LogicalDevice
{
public:
    LogicalDevice(Instance &instance, Surface &surface, PhysicalDevice &physicalDevice);
    ~LogicalDevice();

    const VkDevice &getDevice() const { return device; }

private:
    VkDevice device;
    Instance &instance;
    Surface &surface;
    PhysicalDevice &physicalDevice;

    void LogicalDevice::createLogicalDevice();
};
