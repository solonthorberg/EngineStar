#ifndef STARSHIP_H
#define STARSHIP_H

#include <string>
#include <vector>

enum class Action { Attack, Repair, Shield, Evade, None };

class Starship {
  protected:
    std::string name;
    int health;
    int max_health;
    int attack;
    int defence;

    bool is_evading = false;

  public:
    Starship(std::string name, int health, int attack, int defence);
    virtual ~Starship() = default;

    // Player Options
    virtual int compute_damage();
    virtual void get_repair(int amount);
    virtual void add_shield(int amount);
    virtual void evade();

    virtual void take_damage(int amount);
    virtual bool is_alive() const;
    virtual int get_health() const;
    virtual int get_attack() const;
    virtual int get_defence() const;
    virtual std::string get_name() const;

    virtual void print_actions() = 0;
    virtual int get_num_actions() = 0;
    virtual Action get_action(int choice) = 0;
    virtual std::string get_type() const = 0;
};

#endif
