#ifndef PLANT_H
#define PLANT_H

#include <string>
#include <iostream>
using namespace std;

//Plant class with a filled diamond relationship with PlantFactory, indicating composition
class Plant {
protected:
    string name;
    int health;
    int cost;

public:
    Plant(const string& name='\0', int health=0, int cost=0);
    virtual ~Plant() {}

    // Getters
    string getName() const;
    int getHealth() const;
    int getCost() const;

    // Setters
    void setHealth(int health);
};

#endif // PLANT_H
