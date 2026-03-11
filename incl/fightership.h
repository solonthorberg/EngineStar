#ifndef FIGHTERSHIP_H
#define FIGHTERSHIP_H

#include "starship.h"
#include <string>

class Fightership : public Starship {
  public:
    Fightership(std::string name, int health, int attack, int defence);

    void print_actions() override;
    int get_num_actions() override;
    Action get_action(int choice) override;

    std::string get_type() const override;
};

#endif
