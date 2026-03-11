#ifndef STARSHIP_MANAGER_H
#define STARSHIP_MANAGER_H

#include <vector>

#include "./starship.h"

class StarshipManager {
    std::vector<Starship *> createShipList();
    Starship *starship_selecter();
};

#endif
