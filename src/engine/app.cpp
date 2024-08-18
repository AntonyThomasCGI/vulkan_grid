
#include "app.hpp"

AppBase::AppBase(Window &window, Engine &engine) : window(window), engine(engine)
{
    connections += {
        window.shouldClose.connect<&AppBase::exitApp>(this),
        window.keyPressed.connect<&AppBase::processInput>(this)
    };
}


void AppBase::exitApp()
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
