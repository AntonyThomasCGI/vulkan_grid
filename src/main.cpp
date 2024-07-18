
#include "engine/engine.hpp"
#include "engine/app.hpp"

#include <iostream>



const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;


class App : public AppBase
{
public:
    using AppBase::AppBase;

    void update() { std::cout << "in main::App update" << std::endl; }

    void processInput(int key, int scancode, int action, int mode) {
        if (key == GLFW_KEY_ESCAPE) {
            running = false;
        }
    }
};


int main() {
    std::cout << "start" << std::endl;

    try {
        Window window = Window(WIDTH, HEIGHT);
        Engine engine = Engine(window);
        App app = App(window, engine);
        app.mainLoop();
    } catch (std::exception& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }

    std::cout << "end" << std::endl;

    return EXIT_SUCCESS;
};
