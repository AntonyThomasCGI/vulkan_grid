#pragma once

#include "devices/window.hpp"
#include "engine.hpp"


class AppBase
{
public:
    AppBase(Window &window, Engine &engine);

    virtual void processInput(int key, int scancode, int action, int mode) = 0;
    virtual void update() = 0;

    void mainLoop();
    bool running = true;

private:
    Window &window;
    Engine &engine;

    void closeRequested();

    rocket::scoped_connection_container connections;
};
