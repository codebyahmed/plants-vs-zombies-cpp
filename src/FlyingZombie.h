#ifndef FLYINGZOMBIE_H
#define FLYINGZOMBIE_H

#include "Zombie.h"

class FlyingZombie : public Zombie {
public:
    FlyingZombie(int x = -1, int y = -1);
    void move(float elapsedGameTime) override;
    bool isFlying() override;
    //void attack(RenderWindow &window, float elapsedGameTime, Plant **plants, int plantCount) override;
};

#endif // FLYINGZOMBIE_H