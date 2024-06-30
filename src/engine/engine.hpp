#pragma once

#include "devices/window.hpp"
#include "graphics/graphics.hpp"


class Engine
{
public:
    Engine(Window &window);
    ~Engine();

    void update();

private:
    Window &window;
    std::unique_ptr<VulkanGraphics> graphics;

    rocket::scoped_connection_container connections;
};
