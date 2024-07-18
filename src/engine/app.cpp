
#include "app.hpp"

AppBase::AppBase(Window &window, Engine &engine) : window(window), engine(engine)
{
    connections += {
        window.shouldClose.connect<&AppBase::closeRequested>(this),
        window.keyPressed.connect<&AppBase::processInput>(this)
    };
}


void AppBase::closeRequested()
{
    running = false;
}


void AppBase::mainLoop()
{
    while (running) {
        update();
        window.update();
        engine.update();
    }
}
