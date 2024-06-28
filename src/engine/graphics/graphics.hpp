#pragma once

#include <memory>

#include "command_pool.hpp"
#include "devices/window.hpp"
#include "geometry/primitives/square.hpp"
#include "instance.hpp"
#include "logical_device.hpp"
#include "physical_device.hpp"
#include "pipeline.hpp"
#include "render_pass.hpp"
#include "surface.hpp"
#include "swap_chain.hpp"


struct VulkanGraphicsInfo {
    Window *window;
};


class VulkanGraphics {

public:
    VulkanGraphics(Window &window);

    void createAsset();

private:
    Window &window;
    std::unique_ptr<Instance> instance;
    std::unique_ptr<Surface> surface;
    std::unique_ptr<PhysicalDevice> physicalDevice;
    std::unique_ptr<LogicalDevice> logicalDevice;
    std::unique_ptr<SwapChain> swapChain;
    std::unique_ptr<RenderPass> renderPass;
    std::unique_ptr<CommandPool> commandPool;

    std::unique_ptr<GraphicsPipeline> graphicsPipeline;
    std::unique_ptr<Square> square;
};
