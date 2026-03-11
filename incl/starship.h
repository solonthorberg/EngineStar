#ifndef STARSHIP_H
#define STARSHIP_H

#include <string>

enum class Action {
	Attack,
	Flee,
	Shield,
	Evade,
};

class Starship {
   protected:
	std::string name;
	int health;
	int max_health;
	int attack;
	int defence;

   public:
	int compute_damage();
	void print_actions();
	int get_num_actions();
	Action get_action(int attack);

	void take_damage();
	bool is_alive;
	void print_status();
	std::string get_name();
};

#endif
