#include "Repeater.h"

Repeater::Repeater(int x, int y, float elapsedGameTime) {
    model = "plt_repeater.png";
    posX = x;
    posY = y;
    health = 100;

    prjModel = "prj_pea.png";
    prjX = x + 50;
    prjY = y;
    prj1X = x + 50;
    prj1Y = y;

    peaDamage = 25;
    peaSpeed = 12;
    lastPeaTime[0] = elapsedGameTime;
    lastPeaTime[1] = elapsedGameTime;
    peaInterval = 1.5;
    isPeaAttacking[0] = false;
    isPeaAttacking[1] = false;
}

Repeater::Repeater(int posX, int posY, int health, int prjX, int prjY, int prj1X, int prj1Y, float lastPeaTime0, float lastPeaTime1, bool isPeaAttacking0, bool isPeaAttacking1) {
    model = "plt_repeater.png";
    this->posX = posX;
    this->posY = posY;
    this->health = health;

    prjModel = "prj_pea.png";
    this->prjX = prjX;
    this->prjY = prjY;
    this->prj1X = prj1X;
    this->prj1Y = prj1Y;

    peaDamage = 25;
    peaSpeed = 12;
    lastPeaTime[0] = lastPeaTime0;
    lastPeaTime[1] = lastPeaTime1;
    peaInterval = 1.5;
    isPeaAttacking[0] = isPeaAttacking0;
    isPeaAttacking[1] = isPeaAttacking1;
}

void Repeater::saveState(ofstream &file) {
    file << "Repeater" << endl;
    file << posX << endl;
    file << posY << endl;
    file << health << endl;
    file << prjX << endl;
    file << prjY << endl;
    file << prj1X << endl;
    file << prj1Y << endl;
    file << lastPeaTime[0] << endl;
    file << lastPeaTime[1] << endl;
    file << isPeaAttacking[0] << endl;
    file << isPeaAttacking[1] << endl;
}

// The Repeater shoots two peas at a time
// Use logic from PeaShooter.cpp to shoot two peas instead of one
// The 2nd pea is shot 0.5 seconds after the 1st pea
// Both peas have different prj too
void Repeater::attack(RenderWindow &window, float elapsedGameTime, Zombie **zombies, int zombieCount) {
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
        if (!isPeaAttacking[0] && elapsedGameTime - lastPeaTime[0] >= peaInterval) {
            isPeaAttacking[0] = true;
            lastPeaTime[0] = elapsedGameTime;
        }
        else if (isPeaAttacking[0]) {
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
                isPeaAttacking[0] = false;
            }
            else {
                prjX += peaSpeed;
                if (prjX > 900) {
                    prjX = posX + 50;
                    prjY = posY;
                    isPeaAttacking[0] = false;
                }
            }
        }

        if (!isPeaAttacking[1] && elapsedGameTime - lastPeaTime[1] >= peaInterval + 0.2) {
            isPeaAttacking[1] = true;
            lastPeaTime[1] = elapsedGameTime;
        }
        else if (isPeaAttacking[1]) {
            // Draw the pea moving to the right
            Texture t;
            t.loadFromFile("./images/" + prjModel);
            Sprite s(t);
            s.setPosition(prj1X, prj1Y);
            s.setScale(0.3, 0.3);
            window.draw(s);

            // Check if the pea hits the zombie
            FloatRect peaBounds = s.getGlobalBounds();
            FloatRect zombieBounds = zombie->getBounds();
            if (peaBounds.intersects(zombieBounds)) {
                zombie->takeDamage(peaDamage);

                prj1X = posX + 50;
                prj1Y = posY;
                isPeaAttacking[1] = false;
            }
            else {
                prj1X += peaSpeed;
                if (prj1X > 900) {
                    prj1X = posX + 50;
                    prj1Y = posY;
                    isPeaAttacking[1] = false;
                }
            }
        }
    }
    else {
        isPeaAttacking[0] = false;
        isPeaAttacking[1] = false;
    }

}