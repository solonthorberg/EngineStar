#ifndef STEALTHSHIP_H
#define STEALTHSHIP_H

#include "starship.h"

class Stealthship : public Starship {
   public:
	Stealthship(std::string name, int health, int attack, int defence);

	int compute_damage();
	void print_actions();
	int get_num_actions();
	Action get_action();
};

#endif
