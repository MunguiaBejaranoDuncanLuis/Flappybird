#include "Game.hpp"
#include <iostream>

int main() {
    try {
        Game game;
        game.run();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    return 0;
}