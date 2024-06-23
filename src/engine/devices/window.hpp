#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <utility>

class Window
{
public:
    Window(unsigned int width, unsigned int height);
    ~Window();

    std::pair<uint32_t, const char**> getInstanceExtensions();

    VkResult createSurface(VkInstance &instance, VkSurfaceKHR *surface);

    void getFramebufferSize(int &width, int &height);

private:
    GLFWwindow *window;

    void createWindow(unsigned int width, unsigned int height);
};
