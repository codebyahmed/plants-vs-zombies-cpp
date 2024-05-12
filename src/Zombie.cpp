#include "Zombie.h"

Zombie::Zombie(int x, int y) : posX(x), posY(y), health(-1),  speed(-1), attackDamage(-1), reached(false), alive(true), frozen(false), freezeDuration(2) {}

int Zombie::getPosX() const {
    return posX;
}

int Zombie::getPosY() const {
    return posY;
}

int Zombie::getAttackDamage() const {
    return attackDamage;
}

float Zombie::getAttackInterval() const {
    return attackInterval;
}

float Zombie::getLastAttackTime() const {
    return lastAttackTime;
}

bool Zombie::getIsAttacking() const {
    return isAttacking;
}

bool Zombie::getReached() const {
    return reached;
}

void Zombie::setAlive(bool status) {
    alive = status;
}

void Zombie::setLastAttackTime(float time) {
    lastAttackTime = time;
}

void Zombie::setIsAttacking(bool status) {
    isAttacking = status;
}

void Zombie::setFrozen(bool status) {
    frozen = status;
}

void Zombie::setFrozenTime(float time) {
    frozenTime = time;
}

FloatRect Zombie::getBounds() {
    return FloatRect(posX, posY, 70, 70);
}

void Zombie::draw(RenderWindow &window) {
    Texture texture;
    texture.loadFromFile("./images/" + model);
    Sprite sprite(texture);
    sprite.setPosition(posX, posY);
    sprite.setScale(0.7, 0.7);
    window.draw(sprite);
}

void Zombie::takeDamage(int damage) {
    health -= damage;
}

bool Zombie::isAlive() {
    if (health <= 0)
        alive = false;
    return alive;
}
