
#include <rocket.hpp>

#include <iostream>

#include "engine.hpp"


const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;


Engine::Engine()
{
    window = std::make_unique<Window>(WIDTH, HEIGHT);

    connections += {
        window->shouldClose.connect<&Engine::closeRequested>(this)
    };

    graphics = std::make_unique<VulkanGraphics>(*window.get());
    graphics->createAsset();
}

Engine::~Engine()
{}


void Engine::closeRequested()
{
    running = false;
}



void Engine::mainLoop()
{
    while (running) {
        window->update();
        graphics->update();
    }
}
