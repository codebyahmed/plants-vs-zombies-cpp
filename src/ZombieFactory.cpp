#include "ZombieFactory.h"

Zombie *SimpleZombieFactory::createZombie(int x, int y) {
    return new SimpleZombie(x, y);
}

Zombie *FootballZombieFactory::createZombie(int x, int y) {
    return new FootballZombie(x, y);
}

Zombie *FlyingZombieFactory::createZombie(int x, int y) {
    return new FlyingZombie(x, y);
}

Zombie *DancingZombieFactory::createZombie(int x, int y) {
    return new DancingZombie(x, y);
}
