
#include <iostream>
#include <memory>

#include <vulkan/vk_enum_string_helper.h>

#include "graphics.hpp"


const int MAX_FRAMES_IN_FLIGHT = 2;


VulkanGraphics::VulkanGraphics(Window &window) : window(window)
{
    instance = std::make_unique<Instance>(window);
    surface = std::make_unique<Surface>(*instance.get(), window);
    physicalDevice = std::make_unique<PhysicalDevice>(*instance.get(), *surface.get());
    physicalDevice->pickPhysicalDevice();
    logicalDevice = std::make_unique<LogicalDevice>(*instance.get(), *surface.get(), *physicalDevice.get());
    swapChain = std::make_unique<SwapChain>(*surface.get(), *physicalDevice.get(), *logicalDevice.get(), window);
    commandPool = std::make_unique<CommandPool>(*physicalDevice.get(), *logicalDevice.get(), *surface.get());
}

VulkanGraphics::~VulkanGraphics()
{
    cleanupSyncObjects();
}


void VulkanGraphics::createAsset()
{
    graphicsPipeline = std::make_unique<GraphicsPipeline>(*logicalDevice.get(), *swapChain.get());

    square = std::make_unique<Square>(logicalDevice.get());
    square->createBuffers(*commandPool.get());

    commandBuffers.resize(MAX_FRAMES_IN_FLIGHT);
    for (int i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {
        commandBuffers[i] = std::make_unique<CommandBuffer>(*logicalDevice.get(), *commandPool.get());
    }

    createSyncObjects();
}


void VulkanGraphics::createSyncObjects() {
    imageAvailableSemaphores.resize(MAX_FRAMES_IN_FLIGHT);
    renderFinishedSemaphores.resize(MAX_FRAMES_IN_FLIGHT);
    inFlightFences.resize(MAX_FRAMES_IN_FLIGHT);

    VkSemaphoreCreateInfo semaphoreInfo{};
    semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

    VkFenceCreateInfo fenceInfo{};
    fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    fenceInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;

    for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {
        if (vkCreateSemaphore(logicalDevice->getDevice(), &semaphoreInfo, nullptr, &imageAvailableSemaphores[i]) != VK_SUCCESS ||
            vkCreateSemaphore(logicalDevice->getDevice(), &semaphoreInfo, nullptr, &renderFinishedSemaphores[i]) != VK_SUCCESS ||
            vkCreateFence(logicalDevice->getDevice(), &fenceInfo, nullptr, &inFlightFences[i]) != VK_SUCCESS) {
            throw std::runtime_error("failed to create semaphores!");
        }
    }
}


void VulkanGraphics::cleanupSyncObjects() {
    vkDeviceWaitIdle(logicalDevice->getDevice());
    for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {
        vkDestroySemaphore(logicalDevice->getDevice(), imageAvailableSemaphores[i], nullptr);
        vkDestroySemaphore(logicalDevice->getDevice(), renderFinishedSemaphores[i], nullptr);
        vkDestroyFence(logicalDevice->getDevice(), inFlightFences[i], nullptr);
    }
}


void VulkanGraphics::update()
{
    std::cout << "graphics::update()" << std::endl;
    vkWaitForFences(logicalDevice->getDevice(), 1, &inFlightFences[currentFrame], VK_TRUE, UINT64_MAX);

    uint32_t imageIndex;
    VkResult result = vkAcquireNextImageKHR(logicalDevice->getDevice(), swapChain->getSwapChain(), 5e+9, imageAvailableSemaphores[currentFrame], VK_NULL_HANDLE, &imageIndex);
    //if (result == VK_ERROR_OUT_OF_DATE_KHR || result == VK_SUBOPTIMAL_KHR) {
    //    throw std::runtime_error();
    //} else if (result != VK_SUCCESS) {
    //    throw std::runtime_error("failed to acquire swap chain image!");
    //}
    if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR) {
        std::cerr << string_VkResult(result) << std::endl;
        throw std::runtime_error("failed to acquire swap chain image!");
    }

    swapChain->setCurrentImageIndex(imageIndex);

    // Only reset the fence if we are submitting work.
    vkResetFences(logicalDevice->getDevice(), 1, &inFlightFences[currentFrame]);

    commandBuffers[currentFrame]->start();

    square->draw(*commandBuffers[currentFrame].get(), *swapChain.get(), *graphicsPipeline.get());

    commandBuffers[currentFrame]->end();
    commandBuffers[currentFrame]->submit(imageAvailableSemaphores[currentFrame], renderFinishedSemaphores[currentFrame], inFlightFences[currentFrame]);

    VkSemaphore signalSemaphores[] = {renderFinishedSemaphores[currentFrame]};
    // ****

    VkPresentInfoKHR presentInfo{};
    presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
    presentInfo.waitSemaphoreCount = 1;
    presentInfo.pWaitSemaphores = signalSemaphores;

    VkSwapchainKHR swapChains[] = {swapChain->getSwapChain()};
    presentInfo.swapchainCount = 1;
    presentInfo.pSwapchains = swapChains;
    presentInfo.pImageIndices = &imageIndex;
    presentInfo.pResults = nullptr;

    vkQueuePresentKHR(logicalDevice->getPresentQueue(), &presentInfo);
    //**

    currentFrame = (currentFrame + 1) % MAX_FRAMES_IN_FLIGHT;

    std::cout << "end graphics::update()" << std::endl;
}
