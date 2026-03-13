#include "../incl/battle_manager.h"
#include "../incl/battleship.h"
#include "../incl/console_manager.h"
#include "../incl/starship.h"
#include <cstdlib>
#include <iostream>

BattleManager::BattleManager() {};

BattleManager::~BattleManager() {};

void BattleManager::start_battle(Starship *player_ptr) {
    this->player = player_ptr;
    this->enemy =
        std::make_unique<Battleship>("Enemy Dreadnought", 250, 50, 100);

    battle_loop();
}

void BattleManager::battle_loop() {
    bool battle_running = true;

    while (battle_running) {
        ConsoleManager::clear_screen();
        ConsoleManager::print_battle_hud(player, enemy.get());

        player_turn();

        if (!enemy->is_alive()) {
            std::cout << enemy->get_name() << " destroyed! You win!"
                      << std::endl;
            battle_running = false;
            ConsoleManager::pause_continue();
            continue;
        }

        enemy_turn();

        if (!player->is_alive()) {
            std::cout << "You got destroyed by " << enemy->get_name()
                      << "! You lost!" << std::endl;
            battle_running = false;
            ConsoleManager::pause_continue();
        }

        ConsoleManager::pause_continue();
    }
}

void BattleManager::player_turn() {
    std::cout << "Player Turn!" << std::endl;

    player->print_actions();

    int choice;
    std::cin >> choice;

    Action selectedMove = player->get_action(choice);

    switch (selectedMove) {
    case Action::Attack:
        std::cout << "You open fire!" << std::endl;
        enemy->take_damage(player->compute_damage());
        break;

    case Action::Repair:
        std::cout << "Systems repair" << std::endl;
        player->get_repair(20);
        break;

    case Action::Shield:
        std::cout << "Adding shields!" << std::endl;
        player->add_shield(20);
        break;

    case Action::Evade:
        std::cout << "Initiating thrusters!" << std::endl;
        player->evade();
        break;

    default:
        std::cout << "Invalid move! You lost your turn.\n";
        break;
    }
}

void BattleManager::enemy_turn() {
    std::cout << "Enemy Turn!" << std::endl;

    int roll = std::rand() % 100 + 1;
    Action enemy_move;

    if (roll <= 50) {
        enemy_move = Action::Attack;
    } else if (roll <= 60) {
        enemy_move = Action::Repair;
    } else if (roll <= 70) {
        enemy_move = Action::Shield;
    } else {
        enemy_move = Action::Evade;
    }

    switch (enemy_move) {
    case Action::Attack: {
        std::cout << enemy->get_name() << " attacks!" << std::endl;
        int damage = enemy->compute_damage();
        player->take_damage(damage);
        break;
    }
    case Action::Repair: {
        std::cout << enemy->get_name() << " repairs!" << std::endl;
        int amount = 30;
        enemy->get_repair(amount);
        break;
    }
    case Action::Shield: {
        std::cout << enemy->get_name() << " adds sheild!" << std::endl;
        int amount = 20;
        enemy->add_shield(amount);
        break;
    }
    case Action::Evade: {
        std::cout << enemy->get_name() << " evades!" << std::endl;
        enemy->evade();
        break;
    }
    case Action::None: {
        break;
    }
    }
}
