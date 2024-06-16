
#include "engine/engine.hpp"

#include <iostream>


const unsigned int WIDTH = 800;
const unsigned int HEIGHT = 600;


int main() {
    std::cout << "start" << std::endl;

    auto window = Window(WIDTH, HEIGHT);

    VulkanGraphics graphics = VulkanGraphics(&window);

    std::cout << "end" << std::endl;

    return 0;
}
