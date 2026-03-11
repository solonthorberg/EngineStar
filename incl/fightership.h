#ifndef FIGHTERSHIP_H
#define FIGHTERSHIP_H

#include "starship.h"

class Fighter : public Starship {
   public:
	Fighter(std::string name, int health, int attack, int defence);

	int compute_damage();
	void print_actions();
	int get_num_actions();
	Action get_action();
};

#endif
