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
	static std::vector<Starship*> registry;

  public:
    Starship(std::string name, int health, int attack, int defence);
    virtual ~Starship();

    virtual int compute_damage();
    virtual void take_damage(int amount);
    virtual bool is_alive() const;
    virtual std::string get_name() const;
    virtual void print_status() const;

    virtual void print_actions();
    virtual int get_num_actions();
    virtual Action get_action(int choice);
    virtual std::string get_type() const = 0;

    static void print_ships_by_type(std::string targetType) ;
};

#endif
