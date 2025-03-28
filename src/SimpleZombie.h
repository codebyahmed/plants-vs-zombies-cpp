#ifndef SIMPLEZOMBIE_H
#define SIMPLEZOMBIE_H

#include "Zombie.h"

class SimpleZombie : public Zombie {
public:
    SimpleZombie(int x = -1, int y = -1);
    SimpleZombie(float posX, float posY, int health, bool isAttacking, bool reached, bool frozen, float frozenTime);

    void saveState(ofstream &file) override;
    void move(float elapsedGameTime) override;
    bool isFlying() override;
    //void attack(RenderWindow &window, float elapsedGameTime, Plant **plants, int plantCount) override;
};

#endif // SIMPLEZOMBIE_H