#ifndef CONSOLE_MANAGER_H
#define CONSOLE_MANAGER_H

#include <memory>
#include <vector>

#include "starship.h"

class ConsoleManager {
  public:
    static void print_title();
    static void print_start_menu();
    static void print_starship_manager_menu(
        const std::vector<std::unique_ptr<Starship>> &ships);
    static void print_battle_hud(Starship *player, Starship *enemy);
    static void clear_screen();
    static void pause_continue();
};

#endif
