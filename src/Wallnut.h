#ifndef WALLNUT_H
#define WALLNUT_H

#include "Plant.h"

class Wallnut : public Plant {
private:

public:
    Wallnut(int x = -1, int y = -1, float elapsedGameTime = 0);


    // Not used in Wallnut
    void attack(RenderWindow &window, float elapsedGameTime, Zombie **zombies, int zombieCount) {};
    int produce(RenderWindow &window, float elapsedGameTime, Event &event) { return 0; };
};

#endif // WALLNUT_H
