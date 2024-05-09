#ifndef PEASHOOTER_H
#define PEASHOOTER_H

#include "Plant.h"

class PeeShooter : public Plant {
private:
    int shootingInterval; // Time interval between shots in seconds
    int numPees;

public:
    // Constructor
    PeeShooter(int health, int cost, int shootingInterval, int numPees);

    // Getter for shooting interval
    int getShootingInterval() const;

    // Setter for shooting interval
    void setShootingInterval(int interval);

    // Getter for number of peas
    int getnumPees() const;

    // Setter for number of peas
    void setnumPees(int numPees);
};

#endif // PEASHOOTER_H
