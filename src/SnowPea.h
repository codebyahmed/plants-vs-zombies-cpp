#ifndef SNOWPEA_H
#define SNOWPEA_H

#include "PeeShooter.h"

class SnowPea : public PeeShooter {
private:
    int freezeDuration; // Duration for which the zombie is frozen in seconds

public:
    // Constructor signature
    SnowPea(int health, int cost, int shootingInterval, int numPees,int freezeDuration);

    // Getter for freeze duration
    int getFreezeDuration() const;

    // Setter for freeze duration
    void setFreezeDuration(int duration);
};

#endif // SNOWPEA_H
