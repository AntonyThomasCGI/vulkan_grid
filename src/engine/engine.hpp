#pragma once

#include "devices/window.hpp"
#include "graphics/graphics.hpp"


class Engine
{
public:
    Engine();
    ~Engine();

    void mainLoop();

private:
    std::unique_ptr<Window> window;
    std::unique_ptr<VulkanGraphics> graphics;

    void closeRequested();
    bool running = true;

    rocket::scoped_connection_container connections;
};
