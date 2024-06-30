
#include <rocket.hpp>

#include <iostream>

#include "engine.hpp"


Engine::Engine(Window &window) : window(window)
{
    graphics = std::make_unique<VulkanGraphics>(window);
    graphics->createAsset();
}

Engine::~Engine()
{
}

void Engine::update()
{
    graphics->update();
}
