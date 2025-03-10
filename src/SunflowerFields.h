#ifndef SUNFLOWERFIELDS_H
#define SUNFLOWERFIELDS_H

#include "Level.h"

class SunflowerFields : public Level {
    
public:
    SunflowerFields();
    SunflowerFields(int lives, int sunPoints, float elapsedTime, int plantCount, int zombieCount, string plantsData, string zombiesData);
};

#endif // SUNFLOWERFIELDS_H