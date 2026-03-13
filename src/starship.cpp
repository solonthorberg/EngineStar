#include "../incl/starship.h"
#include <iostream>

Starship::Starship(std::string name, int health, int attack, int defence)
    : name(name), health(health), max_health(health), attack(attack),
      defence(defence) {}

int Starship::compute_damage() { return this->attack; }

void Starship::get_repair(int amount) {
    this->health += amount;
    if (this->health > this->max_health) {
        this->health = this->max_health;
    }
}

void Starship::add_shield(int amount) { this->defence += amount; }

void Starship::evade() { this->is_evading = true; }

void Starship::take_damage(int amount) {
    if (this->is_evading) {
        std::cout << this->name << " dodged the attack!" << std::endl;
        this->is_evading = false;
        return;
    }

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

int Starship::get_health() const { return this->health; }

int Starship::get_attack() const { return this->attack; }

int Starship::get_defence() const { return this->defence; }

std::string Starship::get_name() const { return this->name; }
