#include "DancingZombie.h"

DancingZombie::DancingZombie(int x, int y) {
    model = "zmb_dancing.png";
    posX = x;
    posY = y;
    health = 75;
    speed = 1.75;
    attackDamage = 25;
    lastAttackTime = 0;
}

void DancingZombie::move(float elapsedGameTime) {
    int posYTop = 100;
    int posYBottom = 476;

    int random = rand() % 10000;

    if (!isAttacking && !reached && !frozen) {
        if (random < 10) {
            if (posY > posYTop) {
                posY -= 94;
                posX -= 25;
            }
        }
        else if (random < 20) {
            if (posY < posYBottom) {
                posY += 94;
                posX -= 25;
            }
        }
        else {
           posX -= speed;
        }
        if (posX <= 50) {
            reached = true;
        }
    }

    //Unfreeze if frozen
    if (frozen && elapsedGameTime - frozenTime >= freezeDuration) {
        frozen = false;
    }
}

bool DancingZombie::isFlying() {
    return false;
}