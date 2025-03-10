#ifndef FOOTBALLZOMBIE_H
#define FOOTBALLZOMBIE_H

#include "Zombie.h"

class FootballZombie : public Zombie {
public:
    FootballZombie(int x = -1, int y = -1);
    FootballZombie(float posX, float posY, int health, bool isAttacking, bool reached, bool frozen, float frozenTime);
    void saveState(ofstream &file) override;
    void move(float elapsedGameTime) override;
    bool isFlying() override;
    //void attack(RenderWindow &window, float elapsedGameTime, Plant **plants, int plantCount) override;
};

#endif // FOOTBALLZOMBIE_H