
#include <memory>

#include "graphics.hpp"

VulkanGraphics::VulkanGraphics(Window &window) : window(window)
{
    instance = std::make_unique<Instance>(window);
    surface = std::make_unique<Surface>(*instance.get(), window);
    physicalDevice = std::make_unique<PhysicalDevice>(*instance.get(), *surface.get());
    physicalDevice->pickPhysicalDevice();
    logicalDevice = std::make_unique<LogicalDevice>(*instance.get(), *surface.get(), *physicalDevice.get());
    swapChain = std::make_unique<SwapChain>(*surface.get(), *physicalDevice.get(), *logicalDevice.get(), window);
    renderPass = std::make_unique<RenderPass>(*logicalDevice.get(), *swapChain.get());
    swapChain->setRenderPass(renderPass->getRenderPass());
    swapChain->createFramebuffers();
    commandPool = std::make_unique<CommandPool>(*physicalDevice.get(), *logicalDevice.get(), *surface.get());
}


void VulkanGraphics::createAsset()
{
    graphicsPipeline = std::make_unique<GraphicsPipeline>(*logicalDevice.get(), *swapChain.get(), *renderPass.get());
}
