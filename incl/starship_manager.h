#ifndef STARSHIP_MANAGER_H
#define STARSHIP_MANAGER_H

#include <vector>

#include "./starship.h"
#include <memory>

class StarshipManager {
  public:
    std::vector<std::unique_ptr<Starship>> initializeStarships();
    Starship *
    starship_selecter(std::vector<std::unique_ptr<Starship>> &available_ships);
};

#endif
