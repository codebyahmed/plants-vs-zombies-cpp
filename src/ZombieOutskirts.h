#ifndef ZOMBIEOUTSKIRTS_H
#define ZOMBIEOUTSKIRTS_H

#include "Level.h"

class ZombieOutskirts : public Level {
    
public:
    ZombieOutskirts();
    ZombieOutskirts(int lives, int sunPoints, float elapsedTime, int plantCount, int zombieCount, string plantsData, string zombiesData);
};

#endif // ZOMBIEOUTSKIRTS_H