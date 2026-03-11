#include "../incl/starship.h"
#include <iostream>

Starship::Starship(std::string name, int health, int attack, int defence)
    : name(name), health(health), attack(attack), defence(defence) {}

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
