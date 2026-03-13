#include "../incl/battleship.h"
#include <iostream>

Battleship::Battleship(std::string name, int health, int attack, int defence)
    : Starship(name, health, attack, defence) {}

void Battleship::print_actions() {
    std::cout << this->name << " actions:" << std::endl;
    std::cout << "1. Attack" << std::endl;
    std::cout << "2. Repair" << std::endl;
    std::cout << "3. Shield" << std::endl;
    std::cout << "4. Evade" << std::endl;
}

int Battleship::get_num_actions() { return 4; }

Action Battleship::get_action(int choice) {
    switch (choice) {
    case 1:
        return Action::Attack;
    case 2:
        return Action::Repair;
    case 3:
        return Action::Shield;
    case 4:
        return Action::Evade;
    default:
        return Action::None;
    }
}

std::string Battleship::get_type() const { return "Battleship"; }
