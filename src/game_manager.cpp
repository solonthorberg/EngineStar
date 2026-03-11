#include <iostream>

#include "../incl/console_manager.h"
#include "../incl/game_manager.h"

void GameManager::run_game() {
	void print_title();
	void management_mode();
}

void GameManager::management_mode() {
	int input, loop = 1;

	enum Actions { START = 1, CHOOSE_SHIP = 2, QUIT = 10 };
	do {
		ConsoleManager::print_start_menu();
		do {
			while (!(std::cin >> input)) {
				std::cout << "Invalid input. Try again: ";
				std::cin.clear();
				std::cin.ignore(1000, '\n');
			}
		} while (input < 1 || input > 7);

		switch (input) {
			case START:
				// start game
			case CHOOSE_SHIP:
				// choose game
				StarshipManager();
			case QUIT:
				loop = 0;
				break;
		};
	} while (loop != 0);
};
