#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "starship_manager.h"
class GameManager {
  private:
    StarshipManager ship_manager;
    Starship *player_ship = nullptr;

  public:
    void run_game();
    void management_mode();
};

#endif
