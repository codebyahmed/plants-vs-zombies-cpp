#ifndef ZOMBIEFACTORY_H
#define ZOMBIEFACTORY_H

#include "Zombie.h"
#include "SimpleZombie.h"
#include "FootballZombie.h"
#include "FlyingZombie.h"
#include "DancingZombie.h"

class ZombieFactory {
public:
    virtual Zombie* createZombie(int x, int y) = 0;
};

class SimpleZombieFactory : public ZombieFactory {
public:
    Zombie* createZombie(int x, int y) override;
};

class FootballZombieFactory : public ZombieFactory {
public:
    Zombie* createZombie(int x, int y) override;
};

class FlyingZombieFactory : public ZombieFactory {
public:
    Zombie* createZombie(int x, int y) override;
};

class DancingZombieFactory : public ZombieFactory {
public:
    Zombie* createZombie(int x, int y) override;
};

#endif // ZOMBIEFACTORY_H