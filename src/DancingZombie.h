#ifndef DANCINGZOMBIE_H
#define DANCINGZOMBIE_H

#include "Zombie.h"

class DancingZombie : public Zombie {
public:
    DancingZombie(int x = -1, int y = -1);
    void move(float elapsedGameTime) override;
    bool isFlying() override;
    //void attack(RenderWindow &window, float elapsedGameTime, Plant **plants, int plantCount) override;
};

#endif // DANCINGZOMBIE_H