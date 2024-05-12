#include "Plant.h"

Plant::Plant(int x, int y) : posX(x), posY(y), health(-1) {}

int Plant::getPosX() const {
    return posX;
}

int Plant::getPosY() const {
    return posY;
}

int Plant::getHealth() const {
    return health;
}

void Plant::setPosition(int x, int y) {
    posX = x;
    posY = y;
}

void Plant::draw(RenderWindow &window) {
    Texture texture;
    texture.loadFromFile("./images/" + model);
    Sprite sprite(texture);
    sprite.setPosition(posX, posY);
    sprite.setScale(0.7, 0.7);
    window.draw(sprite);
}

void Plant::takeDamage(int damage) {
    health -= damage;
}

bool Plant::isAlive() {
    if (health <= 0)
        return false;
    return true;
}

FloatRect Plant::getBounds() {
    return FloatRect(posX, posY, 70, 70);
}

void Plant::getAttacked(RenderWindow &window, float elapsedGameTime, Zombie **zombies, int zombieCount) {
    // Find the nearest zombie
    Zombie *zombie = nullptr;
    for (int i = 0; i < zombieCount; i++) {
        if (zombies[i] != nullptr && zombies[i]->isAlive()) {
            if (zombies[i]->getPosY() == posY && zombies[i]->getPosX() - posX > 0 && zombies[i]->getPosX() < 900) {
                if (zombie == nullptr) {
                    zombie = zombies[i];
                }
                else if (zombies[i]->getPosX() < zombie->getPosX()) {
                    zombie = zombies[i];
                }
            }
        }
    }

    // Check if zombie is in attack range of plant
    if (zombie != nullptr) {
        // Get attacked by zombie if its in bounds
        FloatRect plantBounds = getBounds();
        FloatRect zombieBounds = zombie->getBounds();
        if (plantBounds.intersects(zombieBounds)) {
            if (!zombie->getIsAttacking() && elapsedGameTime - zombie->getLastAttackTime() >= zombie->getAttackInterval()) {
                zombie->setIsAttacking(true);
                takeDamage(zombie->getAttackDamage());
                zombie->setLastAttackTime(elapsedGameTime);
            }
        }
    }
}
