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
    virtual ~Starship() = default;

    virtual int compute_damage();
    virtual void print_actions();
    virtual int get_num_actions();
    virtual Action get_action(int attack);

    virtual void take_damage();
    virtual bool is_alive();
    virtual void print_status();
    virtual std::string get_name();
    virtual std::string get_type() const = 0;
    virtual void print_ships();
};

#endif
