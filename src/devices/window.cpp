
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


void Window::createWindow(unsigned int width, unsigned int height)
{
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    window = glfwCreateWindow(width, height, "Vulkan Grid", nullptr, nullptr);

    //glfwSetWindowUserPointer(window, this);
    //glfwSetFramebufferSizeCallback(window, framebufferReszieCallback);
    //glfwSetKeyCallback(window, keyCallback);
}