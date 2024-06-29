
#include "engine/engine.hpp"

#include <iostream>


int main() {
    std::cout << "start" << std::endl;

    try {
        Engine engine = Engine();
        engine.mainLoop();
    } catch (std::exception& e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }

    std::cout << "end" << std::endl;

    return EXIT_SUCCESS;
};
