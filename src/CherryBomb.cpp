#include "CherryBomb.h"

CherryBomb::CherryBomb(int x, int y, float elapsedGameTime) {
    model = "plt_cherrybomb.png";
    posX = x;
    posY = y;
    health = 100;

    prjModel = "prj_boom.png";
    prjX = x - 100;
    prjY = y - 100;

    blastRadius = 100;
    blastDamage = 500;
    blastTime = 2;
    creationTime = elapsedGameTime;
}

CherryBomb::CherryBomb(int posX, int posY, int health, int prjX, int prjY, int blastRadius, int blastDamage, int blastTime, float creationTime) {
    model = "plt_cherrybomb.png";
    this->posX = posX;
    this->posY = posY;
    this->health = health;

    prjModel = "prj_boom.png";
    this->prjX = prjX;
    this->prjY = prjY;

    this->blastRadius = blastRadius;
    this->blastDamage = blastDamage;
    this->blastTime = blastTime;
    this->creationTime = creationTime;
}

void CherryBomb::saveState(ofstream &file) {
    file << "CherryBomb" << endl;
    file << posX << endl;
    file << posY << endl;
    file << health << endl;
    file << prjX << endl;
    file << prjY << endl;
    file << blastRadius << endl;
    file << blastDamage << endl;
    file << blastTime << endl;
    file << creationTime << endl;
}

void CherryBomb::attack(RenderWindow &window, float elapsedGameTime, Zombie **zombies, int zombieCount) {
    if (elapsedGameTime - creationTime >= blastTime) {
        // Draw the explosion
        Texture t;
        t.loadFromFile("./images/" + prjModel);
        Sprite s(t);
        s.setPosition(prjX, prjY);
        s.setScale(2, 2);
        window.draw(s);

        // Check if the explosion hits the zombies
        for (int i = 0; i < zombieCount; i++) {
            if (zombies[i] != nullptr && zombies[i]->isAlive()) {
                FloatRect zombieBounds = zombies[i]->getBounds();
                FloatRect blastBounds = s.getGlobalBounds();
                if (zombieBounds.intersects(blastBounds)) {
                    zombies[i]->takeDamage(blastDamage);
                }
            }
        }

        health = 0;
    }
}
