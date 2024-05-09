#ifndef FUMESHROOM_H
#define FUMESHROOM_H

#include "Plant.h"

class FumeShroom : public Plant {
private:
    int range;  // The effective range of the fumes, in game units (spaces)

public:
    // Constructor signature
    FumeShroom(int health, int cost, int range);

    // Getter for range
    int getRange() const;

    // Setter for range
    void setRange(int newRange);

   
};

#endif // FUMESHROOM_H
