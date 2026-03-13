#include <cstdlib>
#include <iostream>

#include "../incl/console_manager.h"

void ConsoleManager::print_title() {
    std::cout << "--- EngineStar ---" << std::endl;
};

void ConsoleManager::print_start_menu() {
    std::cout << "Please choose a option:" << std::endl;
    std::cout << "1. Start a game." << std::endl;
    std::cout << "2. Choose a starship." << std::endl;
    std::cout << "3. Quit Game." << std::endl;
}

void ConsoleManager::print_starship_manager_menu(
    const std::vector<std::unique_ptr<Starship>> &ships) {
    std::cout << "\n--- AVAILABLE FLEET BY CATEGORY ---" << std::endl;

    for (size_t i = 0; i < ships.size(); ++i) {
        std::cout << i + 1 << ". [" << ships[i]->get_type() << "] "
                  << ships[i]->get_name() << std::endl;
    }
}

void ConsoleManager::print_battle_hud(Starship *player, Starship *enemy) {
    std::cout << std::endl
              << "===================================================="
              << std::endl;

    std::cout << "  " << player->get_name() << " [" << player->get_type()
              << "]";
    std::cout << "   vs   ";
    std::cout << enemy->get_name() << " [" << enemy->get_type() << "]"
              << std::endl;

    std::cout << "  Health: " << player->get_health() << " / 100";
    std::cout << "                ";
    std::cout << "Health: " << enemy->get_health() << " / 100" << std::endl;

    std::cout << "  Attack: " << player->get_attack() << " / 100";
    std::cout << "                ";
    std::cout << "Attack: " << enemy->get_attack() << " / 100" << std::endl;

    std::cout << "  Defence: " << player->get_defence() << " / 100";
    std::cout << "                ";
    std::cout << "Defence: " << enemy->get_defence() << " / 100" << std::endl;

    std::cout << std::endl
              << "===================================================="
              << std::endl;
}

void ConsoleManager::clear_screen() { std::system("clear"); }

void ConsoleManager::pause_continue() {
    std::cout << std::endl << "Press Enter to continue...";
    std::cin.ignore(1000, '\n');
    std::cin.get();
}
