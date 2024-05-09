#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include "Plant.h"

class Sunflower : public Plant {
private:
    int sunProductionInterval; // Time interval for producing sun in seconds

public:
    // Constructor signature
    Sunflower(int health, int cost, int sunProductionInterval);

    // Getter for sun production interval
    int getSunProductionInterval() const;

    // Setter for sun production interval
    void setSunProductionInterval(int interval);
};

#endif // SUNFLOWER_H
