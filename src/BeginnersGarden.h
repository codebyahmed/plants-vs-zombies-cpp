#ifndef BEGINNERSGARDEN_H
#define BEGINNERSGARDEN_H

#include "Level.h"

class BeginnersGarden : public Level {
    
public:
    BeginnersGarden();
    BeginnersGarden(int lives, int sunPoints, float elapsedTime, int plantCount, int zombieCount, string plants, string zombies);
};

#endif // BEGINNERSGARDEN_H