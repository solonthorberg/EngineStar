#include "../incl/stealthship.h"
#include <iostream>

void Stealthship::print_actions() {
    std::cout << this->name << " actions:" << std::endl;
    std::cout << "1. Attack" << std::endl;
    std::cout << "2. Repair" << std::endl;
    std::cout << "3. Shield" << std::endl;
    std::cout << "4. Evade" << std::endl;
}

int Stealthship::get_num_actions() { return 4; }

Action Stealthship::get_action(int choice) {
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

std::string Stealthship::get_type() const { return "Stealthship"; }
