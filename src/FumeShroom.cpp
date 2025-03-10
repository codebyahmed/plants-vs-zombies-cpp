#include "FumeShroom.h"

FumeShroom::FumeShroom(int x, int y, float elapsedGameTime) {
    model = "plt_fumeshroom.png";
    posX = x;
    posY = y;
    health = 100;

    prjModel = "prj_fume.png";
    prjX = x + 50;
    prjY = y;

    shroomDamage = 10;
    shroomSpeed = 6;
    lastShroomTIme = elapsedGameTime;
    shroomInterval = 2;
    shroomRange = 320; // 4 boxes
    isShrooming = false;
}

FumeShroom::FumeShroom(int posX, int posY, int health, int prjX, int prjY, float lastShroomTime, bool isShrooming) {
    model = "plt_fumeshroom.png";
    this->posX = posX;
    this->posY = posY;
    this->health = health;

    prjModel = "prj_fume.png";
    this->prjX = prjX;
    this->prjY = prjY;

    shroomDamage = 10;
    shroomSpeed = 6;
    this->lastShroomTIme = lastShroomTime;
    shroomInterval = 2;
    shroomRange = 320; // 4 boxes
    this->isShrooming = isShrooming;
}

void FumeShroom::saveState(ofstream &file) {
    file << "FumeShroom" << endl;
    file << posX << endl;
    file << posY << endl;
    file << health << endl;
    file << prjX << endl;
    file << prjY << endl;
    file << lastShroomTIme << endl;
    file << isShrooming << endl;
}

// Attacks all zombies within shroomRange, goes through zombies
// Use logic from PeaShooter::attack but modify it to pass through zombies
void FumeShroom::attack(RenderWindow &window, float elapsedGameTime, Zombie **zombies, int zombieCount) {
    // Find the nearest zombie
    Zombie *zombie = nullptr;
    for (int i = 0; i < zombieCount; i++) {
        if (zombies[i] != nullptr && zombies[i]->isAlive()) {
            if (zombies[i]->getPosY() == posY && zombies[i]->getPosX() - posX > 0 && zombies[i]->getPosX() < 900 && zombies[i]->getPosX() - posX <= shroomRange) {
                if (zombie == nullptr) {
                    zombie = zombies[i];
                }
                else if (zombies[i]->getPosX() < zombie->getPosX()) {
                    zombie = zombies[i];
                }
            }
        }
    }

    // Attack the zombie
    if (zombie != nullptr) {
        if (!isShrooming && elapsedGameTime - lastShroomTIme >= shroomInterval) {
            isShrooming = true;
            lastShroomTIme = elapsedGameTime;
        }
        else if (isShrooming) {
            // Draw the shroom moving to the right
            Texture t;
            t.loadFromFile("./images/" + prjModel);
            Sprite s(t);
            s.setPosition(prjX, prjY);
            s.setScale(1, 1);
            window.draw(s);

            // Check if the shroom hits the zombie
            FloatRect shroomBounds = s.getGlobalBounds();
            FloatRect zombieBounds = zombie->getBounds();
            if (shroomBounds.intersects(zombieBounds)) {
                zombie->takeDamage(shroomDamage);
                
                prjX = posX + 50;
                prjY = posY;
                isShrooming = false;
            }
            else {
                prjX += shroomSpeed;
                if (prjX > 900) {
                    prjX = posX + 50;
                    prjY = posY;
                    isShrooming = false;
                }
            }
        }
    }
    else {
        isShrooming = false;
    }

}