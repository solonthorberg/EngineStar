#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include "starship.h"

class Battleship : public Starship {
   public:
	Battleship(std::string name, int health, int attack, int defence);

	int compute_damage();
	void print_actions();
	int get_num_actions();
	Action get_action();
};

#endif
