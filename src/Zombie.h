#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
using namespace std;

class Zombie {
protected:
    string model;
    float posX;
    float posY;
    int health;
    float speed;
    int attackDamage;
    float attackInterval;
    float lastAttackTime;
    bool isAttacking;
    bool reached;
    bool alive;
    bool frozen;
    float frozenTime;
    float freezeDuration;

public:
    // Constructor
    Zombie(int x = -1, int y = -1);

    int getPosX() const;
    int getPosY() const;
    int getAttackDamage() const;
    float getAttackInterval() const;
    float getLastAttackTime() const;
    bool getIsAttacking() const;
    bool getReached() const;

    void setAlive(bool status);
    void setLastAttackTime(float time);
    void setIsAttacking(bool status);
    void setFrozen(bool status);
    void setFrozenTime(float time);

    virtual bool isFlying() = 0;

    // Move the zombie
    virtual void move(float elapsedGameTime) = 0;

    // Attack the plant
    // virtual void attack(RenderWindow &window, float elapsedGameTime, Plant **plants, int plantCount) = 0;

    virtual FloatRect getBounds();

    void draw(RenderWindow &window);

    // Take damage
    void takeDamage(int damage);

    // Check if the zombie is alive
    bool isAlive();
};

#endif // ZOMBIE_H