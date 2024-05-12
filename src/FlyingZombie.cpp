#include "FlyingZombie.h"

FlyingZombie::FlyingZombie(int x, int y) {
    model = "zmb_flying.png";
    posX = x;
    posY = y;
    health = 100;
    speed = 1.25;
    attackDamage = 0;
    lastAttackTime = 0;
}

void FlyingZombie::move(float elapsedGameTime) {
    if (!reached && !frozen) {
        posX -= speed;
        if (posX <= 50) {
            reached = true;
        }
    }

    //Unfreeze if frozen
    if (frozen && elapsedGameTime - frozenTime >= freezeDuration) {
        frozen = false;
    }
}

bool FlyingZombie::isFlying() {
    return true;
}