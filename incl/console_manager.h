#ifndef CONSOLE_MANAGER_H
#define CONSOLE_MANAGER_H

#include <vector>

#include "starship.h"

class ConsoleManager {
   public:
	static void print_title();
	static void print_start_menu();
	static void print_starship_manager_menu(std::vector<Starship*>);
	static void clear_screen();
};

#endif
