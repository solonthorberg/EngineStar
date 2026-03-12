#ifndef STARSHIP_MANAGER_H
#define STARSHIP_MANAGER_H

#include <vector>

#include "./starship.h"

class StarshipManager {
    std::vector<Starship *> initializeStarships();
    Starship *starship_selecter();
};

#endif
