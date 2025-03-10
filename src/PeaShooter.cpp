#include "PeaShooter.h"

PeaShooter::PeaShooter(int x, int y, float elapsedGameTime) {
    model = "plt_peashooter.png";
    posX = x;
    posY = y;
    health = 100;

    prjModel = "prj_pea.png";
    prjX = x + 50;
    prjY = y;

    peaDamage = 25;
    peaSpeed = 12;
    lastPeaTime = elapsedGameTime;
    peaInterval = 1.5;
    isPeaAttacking = false;
}

PeaShooter::PeaShooter(int posX, int posY, int health, int prjX, int prjY, float lastPeaTime, bool isPeaAttacking) {
    model = "plt_peashooter.png";
    this->posX = posX;
    this->posY = posY;
    this->health = health;

    prjModel = "prj_pea.png";
    this->prjX = prjX;
    this->prjY = prjY;

    peaDamage = 25;
    peaSpeed = 12;
    this->lastPeaTime = lastPeaTime;
    peaInterval = 1.5;
    this->isPeaAttacking = isPeaAttacking;
}

void PeaShooter::saveState(ofstream &file) {
    file << "PeaShooter" << endl;
    file << posX << endl;
    file << posY << endl;
    file << health << endl;
    file << prjX << endl;
    file << prjY << endl;
    file << lastPeaTime << endl;
    file << isPeaAttacking << endl;
}

void PeaShooter::attack(RenderWindow &window, float elapsedGameTime, Zombie **zombies, int zombieCount) {
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

    // Attack the zombie
    if (zombie != nullptr) {
        if (!isPeaAttacking && elapsedGameTime - lastPeaTime >= peaInterval) {
            isPeaAttacking = true;
            lastPeaTime = elapsedGameTime;
        }
        else if (isPeaAttacking) {
            // Draw the pea moving to the right
            Texture t;
            t.loadFromFile("./images/" + prjModel);
            Sprite s(t);
            s.setPosition(prjX, prjY);
            s.setScale(0.3, 0.3);
            window.draw(s);

            // Check if the pea hits the zombie
            FloatRect peaBounds = s.getGlobalBounds();
            FloatRect zombieBounds = zombie->getBounds();
            if (peaBounds.intersects(zombieBounds)) {
                zombie->takeDamage(peaDamage);
                
                prjX = posX + 50;
                prjY = posY;
                isPeaAttacking = false;
            }
            else {
                prjX += peaSpeed;
                // If the pea is out of the window, stop attacking
                if (prjX > 900) {
                    prjX = posX + 50;
                    prjY = posY;
                    isPeaAttacking = false;
                }
            }
        }
    }
    else {
        isPeaAttacking = false;
    }
}