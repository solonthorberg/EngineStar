#ifndef STARSHIP_H
#define STARSHIP_H

#include <string>

enum class Action { Attack, Repair, Shield, Evade, None };

class Starship {
  protected:
    std::string name;
    int health;
    int max_health;
    int attack;
    int defence;

  public:
    Starship(std::string name, int health, int attack, int defence);
    virtual ~Starship() = default;

    virtual int compute_damage();
    virtual void take_damage(int amount);
    virtual bool is_alive() const;
    virtual void print_status() const;
    virtual void print_actions();
    virtual int get_num_actions();
    virtual Action get_action(int choice);
    virtual std::string get_name() const;
    virtual std::string get_type() const = 0;
    virtual void print_ships();
};

#endif
