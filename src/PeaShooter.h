#ifndef PEASHOOTER_H
#define PEASHOOTER_H

#include "Plant.h"

class PeaShooter : public Plant {
private:
    float fireInterval; // in seconds
    int peaDamage;

public:
    PeaShooter(int x = -1, int y = -1, int health = 5, int fireRate = 0.5, int peaDamage = 1);
    ~PeaShooter() {}
    void attack();
    void print();
};

#endif // PEASHOOTER_H
