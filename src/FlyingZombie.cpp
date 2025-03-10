#include "FlyingZombie.h"

FlyingZombie::FlyingZombie(int x, int y) {
    model = "zmb_flying.png";
    posX = x;
    posY = y;
    health = 100;
    speed = 1;
    attackDamage = 0;
    lastAttackTime = 0;
    frozen = false;
    frozenTime = 0;
}

FlyingZombie::FlyingZombie(float posX, float posY, int health, bool isAttacking, bool reached, bool frozen, float frozenTime) {
    model = "zmb_flying.png";
    this->posX = posX;
    this->posY = posY;
    this->health = health;
    this->isAttacking = isAttacking;
    this->reached = reached;
    this->frozen = frozen;
    this->frozenTime = frozenTime;
}

void FlyingZombie::saveState(ofstream &file) {
    file << "FlyingZombie" << endl;
    file << posX << endl;
    file << posY << endl;
    file << health << endl;
    file << isAttacking << endl;
    file << reached << endl;
    file << frozen << endl;
    file << frozenTime << endl;
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