
#include "window.hpp"


Window::Window(unsigned int width, unsigned int height)
{
    createWindow(width, height);
}


Window::~Window()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}


std::pair<uint32_t, const char**> Window::getInstanceExtensions()
{
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;

    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    return std::make_pair(glfwExtensionCount, glfwExtensions);
}


VkResult Window::createSurface(VkInstance &instance, VkSurfaceKHR *surface)
{
    return glfwCreateWindowSurface(instance, window, nullptr, surface);
}


void Window::createWindow(unsigned int width, unsigned int height)
{
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    window = glfwCreateWindow(width, height, "Vulkan Grid", nullptr, nullptr);

    //glfwSetWindowUserPointer(window, this);
    //glfwSetFramebufferSizeCallback(window, framebufferReszieCallback);
    //glfwSetKeyCallback(window, keyCallback);
}
