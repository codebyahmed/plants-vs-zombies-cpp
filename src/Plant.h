#ifndef PLANT_H
#define PLANT_H

#include <iostream>
using namespace std;

class Plant {
protected:
    int gridX;
    int gridY;
    int health;

public:
    Plant(int x = -1, int y = -1, int health = -1);
    virtual ~Plant() {}
};

#endif // PLANT_H
