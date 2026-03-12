#include "../incl/starship.h"
#include <iostream>
#include <algorithm>

std::vector<Starship*> Starship::registry;

Starship::Starship(std::string name, int health, int attack, int defence)
    : name(name), health(health), attack(attack), defence(defence) {
		registry.push_back(this);
	}

Starship::~Starship() {
	auto removed = std::find(registry.begin(), registry.end(), this);

	if (removed != registry.end()) {
		registry.erase(removed);
	}
}


int Starship::compute_damage() { return this->attack; }

void Starship::take_damage(int amount) {
    int reduced_damage = amount - this->defence;
    if (reduced_damage < 0)
        reduced_damage = 0;

    this->health -= reduced_damage;

    if (this->health < 0) {
        this->health = 0;
    }

    std::cout << this->name << " took " << reduced_damage << " damage!"
              << std::endl;
}

bool Starship::is_alive() const { return this->health > 0; }

std::string Starship::get_name() const { return this->name; }

void Starship::print_ships_by_type(std::string targetType) {
	std::cout << "Available " << targetType << " Ships:" << std::endl;

	bool found = false;

	for (const auto &ship : registry) {
		if (ship->get_type() == targetType) {
			std::cout << " > " << ship->name << std::endl;
			found = true;
		}
	}

	if (!found) {
		std::cout << "No ships found for: " << targetType << std::endl;
	}
}
