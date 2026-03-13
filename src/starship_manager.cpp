#include <iostream>
#include <vector>

#include "../incl/battleship.h"
#include "../incl/fightership.h"
#include "../incl/starship.h"
#include "../incl/starship_manager.h"
#include "../incl/stealthship.h"

std::vector<std::unique_ptr<Starship>> StarshipManager::initializeStarships() {
    std::vector<std::unique_ptr<Starship>> ships;

    ships.push_back(std::make_unique<Fightership>("Wraith", 60, 70, 35));

    ships.push_back(std::make_unique<Battleship>("Iron Orbit", 95, 40, 70));

    ships.push_back(std::make_unique<Stealthship>("Eclipse", 50, 35, 65));

    return ships;
};

Starship *StarshipManager::starship_selecter(
    std::vector<std::unique_ptr<Starship>> &available_ships) {
    int choice;
    std::cout << "Enter the number of your chosen vessel: ";

    while (!(std::cin >> choice) || choice < 1 ||
           choice > (int)available_ships.size()) {
        std::cout << "Invalid choice. Select 1-" << available_ships.size()
                  << ": ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    return available_ships[choice - 1].get();
}
