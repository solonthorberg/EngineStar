#ifndef STEALTHSHIP_H
#define STEALTHSHIP_H

#include "starship.h"
#include <string>

class Stealthship : public Starship {
  public:
    Stealthship(std::string name, int health, int attack, int defence);

    void print_actions() override;
    int get_num_actions() override;
    Action get_action(int choice) override;
    std::string get_type() const override;
};

#endif
