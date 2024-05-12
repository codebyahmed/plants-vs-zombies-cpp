#include "SnowPea.h"

SnowPea::SnowPea(int x, int y, float elapsedGameTime) {
    model = "plt_snowpea.png";
    posX = x;
    posY = y;
    health = 100;

    prjModel = "prj_ice.png";
    prjX = x + 50;
    prjY = y;

    peaDamage = 15;
    peaSpeed = 10;
    lastPeaTime = elapsedGameTime;
    peaInterval = 2;
    isPeaAttacking = false;
}

void SnowPea::attack(RenderWindow &window, float elapsedGameTime, Zombie **zombies, int zombieCount) {
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
                zombie->setFrozen(true);
                zombie->setFrozenTime(elapsedGameTime);
                
                prjX = posX + 50;
                prjY = posY;
                isPeaAttacking = false;
            }
            else {
                prjX += peaSpeed;
                // If the pea is out of the window, stop attacking
                if (prjX > 900) {
                    isPeaAttacking = false;
                }
            }
        }
    }
    else {
        isPeaAttacking = false;
    }
}

