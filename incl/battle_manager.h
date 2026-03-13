#ifndef BATTLE_MANAGER_H
#define BATTLE_MANAGER_H

#include "starship.h"
#include <memory>

class BattleManager {
  public:
    BattleManager();
    ~BattleManager();

    void start_battle(Starship *player_ptr);

  private:
    Starship *player;
    std::unique_ptr<Starship> enemy;

    void battle_loop();
    void player_turn();
    void enemy_turn();

    // Starship *generate_random_enemy();
    // void display_status();
    // void resolve_damage(Starship *attacker, Starship *defender);
};

#endif
