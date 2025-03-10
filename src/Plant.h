#ifndef PLANT_H
#define PLANT_H

#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

#include "Zombie.h"

class Plant {
protected:
    // Plant's information
    string model;
    int posX;
    int posY;
    int health;

    // Projectile information
    string prjModel;
    int prjX;
    int prjY;

public:
    Plant(int x = -1, int y = -1);

    int getPosX() const;
    int getPosY() const;
    int getHealth() const;
    void setPosition(int x, int y);

    virtual void draw(RenderWindow &window);
    void takeDamage(int damage);
    bool isAlive();

    FloatRect getBounds();

    virtual void saveState(ofstream &file) = 0;

    //All
    virtual void getAttacked(RenderWindow &window, float elapsedGameTime, Zombie **zombies, int zombieCount);

    //Shooter
    virtual void attack(RenderWindow &window, float elapsedGameTime, Zombie **zombies, int zombieCount) = 0;
    
    //Sunflower
    virtual int produce(RenderWindow &window, float elapsedGameTime, Event &event) = 0;

    
};

#endif // PLANT_H
