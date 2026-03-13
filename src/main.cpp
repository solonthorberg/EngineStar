#include "../incl/game_manager.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    srand(static_cast<unsigned int>(time(0)));

    try {
        GameManager game;
        game.run_game();
    } catch (const std::exception &e) {
        std::cerr << "CRITICAL ERROR: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "\nThank you for playing. Commander, signing off."
              << std::endl;

    return 0;
}
