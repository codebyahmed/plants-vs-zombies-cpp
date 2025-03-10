#ifndef PEASHOOTER_H
#define PEASHOOTER_H

#include "Plant.h"

class PeaShooter : public Plant {
private:
    // Information of the pea shot by the pea shooter
    int peaDamage;
    float peaSpeed;
    float lastPeaTime;
    float peaInterval;
    bool isPeaAttacking;

public:
    PeaShooter(int x = -1, int y = -1, float elapsedGameTime = 0);
    PeaShooter(int posX, int posY, int health, int prjX, int prjY, float lastPeaTime, bool isPeaAttacking);

    void saveState(ofstream &file) override;
    void attack(RenderWindow &window, float elapsedGameTime, Zombie **zombies, int zombieCount);
    // Not used in PeaShooter
    int produce(RenderWindow &window, float elapsedGameTime, Event &event) { return 0; };
};

#endif // PEASHOOTER_H
