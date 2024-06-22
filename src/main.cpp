
#include "engine/engine.hpp"

#include <iostream>


const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;


int main() {
    std::cout << "start" << std::endl;

    Window window = Window(WIDTH, HEIGHT);

    try {
        VulkanGraphics graphics = VulkanGraphics(window);
    } catch (std::exception& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }

    std::cout << "end" << std::endl;

    return 0;
};
