#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include "Plant.h"

class Sunflower : public Plant {
private:
    // Information of the sun produced by the sunflower
    int sunValue; // Sun value produced by the sunflower
    float lastSunTime; // Last time the sun was produced
    float sunInterval; // Time interval for producing sun in seconds
    bool isSunAvailable; // True if sun is available to be collected

public:
    Sunflower(int x = -1, int y = -1, float elapsedGameTime = 0);
    Sunflower(int posX, int posY, int health, int prjX, int prjY, float lastSunTime, bool isSunAvailable);

    void saveState(ofstream &file) override;
    int produce(RenderWindow &window, float elapsedGameTime, Event &event);

    // Not used in Sunflower
    void attack(RenderWindow &window, float elapsedGameTime, Zombie **zombies, int zombieCount) {};
};

#endif // SUNFLOWER_H
