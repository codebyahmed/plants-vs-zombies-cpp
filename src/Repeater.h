#ifndef REPEATER_H
#define REPEATER_H

#include "Plant.h"

class Repeater : public Plant {
private:
    // Information of the pea shot by the pea shooter
    int peaDamage;
    float peaSpeed;
    float lastPeaTime[2];
    float peaInterval;
    bool isPeaAttacking[2];

    int prj1X;
    int prj1Y;

public:
    Repeater(int x = -1, int y = -1, float elapsedGameTime = 0);

    void attack(RenderWindow &window, float elapsedGameTime, Zombie **zombies, int zombieCount);
    // Not used in PeaShooter
    int produce(RenderWindow &window, float elapsedGameTime, Event &event) { return 0; };
};

#endif // REPEATER_H
