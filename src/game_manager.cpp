#include <iostream>

#include "../incl/battle_manager.h"
#include "../incl/console_manager.h"
#include "../incl/game_manager.h"
#include "../incl/starship_manager.h"

void GameManager::run_game() { management_mode(); }

void GameManager::management_mode() {
    int input, loop = 1;

    enum Actions { START = 1, CHOOSE_SHIP = 2, QUIT = 3 };
    do {
        ConsoleManager::clear_screen();
        ConsoleManager::print_title();
        ConsoleManager::print_start_menu();
        do {
            while (!(std::cin >> input)) {
                std::cout << "Invalid input. Try again: ";
                std::cin.clear();
                std::cin.ignore(1000, '\n');
            }
        } while (input < 1 || input > 3);

        switch (input) {
        case START:
            if (player_ship == nullptr) {
                std::cout << "You must choose a ship before deploying!"
                          << std::endl;
                ConsoleManager::pause_continue();
            } else {
                std::cout << "Launching... " << player_ship->get_name() << "..."
                          << std::endl;
                BattleManager battle;
                battle.start_battle(player_ship);
            }
            break;

        case CHOOSE_SHIP: {
            std::vector<std::unique_ptr<Starship>> available_ships =
                ship_manager.initializeStarships();

            ConsoleManager::print_starship_manager_menu(available_ships);

            Starship *chosen = ship_manager.starship_selecter(available_ships);

            if (player_ship != nullptr) {
                delete player_ship;
            }

            player_ship = std::move(chosen);

            ConsoleManager::clear_screen();
            break;
        }
        case QUIT:
            loop = 0;
            break;
        };
    } while (loop != 0);
};
