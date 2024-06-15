#pragma once

#include <GLFW/glfw3.h>

class Window
{
public:
    Window(unsigned int width, unsigned int height);
    ~Window();

private:
    GLFWwindow *window;

    void createWindow(unsigned int width, unsigned int height);
};
