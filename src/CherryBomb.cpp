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
