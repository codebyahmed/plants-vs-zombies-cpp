#ifndef FUMESHROOM_H
#define FUMESHROOM_H

#include "Plant.h"

class FumeShroom : public Plant {
private:
    // Information of the FumeShroom bullet
    int shroomDamage;
    float shroomSpeed;
    float lastShroomTIme;
    float shroomInterval;
    int shroomRange;
    bool isShrooming;


public:
    FumeShroom(int x = -1, int y = -1, float elapsedGameTime = 0);
    FumeShroom(int posX, int posY, int health, int prjX, int prjY, float lastShroomTime, bool isShrooming);

    void saveState(ofstream &file) override;
    void attack(RenderWindow &window, float elapsedGameTime, Zombie **zombies, int zombieCount);
    // Not used in PeaShooter
    int produce(RenderWindow &window, float elapsedGameTime, Event &event) { return 0; };
};

#endif // FUMESHROOM_H
