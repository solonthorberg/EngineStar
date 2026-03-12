#include <iostream>
#include <vector>

#include "../incl/battleship.h"
#include "../incl/fightership.h"
#include "../incl/starship.h"
#include "../incl/starship_manager.h"
#include "../incl/stealthship.h"

std::vector<Starship *> StarshipManager::initializeStarships() {
    std::vector<Starship *> ships;

    ships.push_back(new Fightership("Wraith", 80, 70, 65));

    ships.push_back(new Battleship("Iron Orbit", 95, 40, 70));

    ships.push_back(new Stealthship("Eclipse", 50, 70, 65));

    return ships;
};

Starship *StarshipManager::starship_selecter() {
	// Select a ship
	return;
}
