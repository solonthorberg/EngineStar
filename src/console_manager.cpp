#include <cstdlib>
#include <iostream>

#include "../incl/console_manager.h"
#include "../incl/fightership.h"

void ConsoleManager::print_title() { std::cout << "EngineStar"; };

void ConsoleManager::print_start_menu() {
	std::cout << "Please choose a option:" << std::endl;
	std::cout << "1. Start a game." << std::endl;
	std::cout << "2. Choose a starship." << std::endl;
	std::cout << "3. Quit Game." << std::endl;
}

void ConsoleManager::print_starship_manager_menu(std::vector<Starship*> ships) {
	std::cout << "Please choose a starship:" << std::endl;

	for (const auto& ship : ships) {
		if (dynamic_cast<Fighter*>(ship[i]
	}
}

void ConsoleManager::clear_screen() { std::system("clear"); }
