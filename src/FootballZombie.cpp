#include "FootballZombie.h"

FootballZombie::FootballZombie(int x, int y) {
    model = "zmb_football.png";
    posX = x;
    posY = y;
    health = 150;
    speed = 1;
    attackDamage = 40;
    lastAttackTime = 0;
    frozen = false;
    frozenTime = 0;
}

FootballZombie::FootballZombie(float posX, float posY, int health, bool isAttacking, bool reached, bool frozen, float frozenTime) {
    model = "zmb_football.png";
    this->posX = posX;
    this->posY = posY;
    this->health = health;
    this->isAttacking = isAttacking;
    this->reached = reached;
    this->frozen = frozen;
    this->frozenTime = frozenTime;
}

void FootballZombie::saveState(ofstream &file) {\
    file << "FootballZombie" << endl;
    file << posX << endl;
    file << posY << endl;
    file << health << endl;
    file << isAttacking << endl;
    file << reached << endl;
    file << frozen << endl;
    file << frozenTime << endl;
}

void FootballZombie::move(float elapsedGameTime) {
    int posYTop = 100;
    int posYBottom = 476;

    int random = rand() % 10000;

    if (!isAttacking && !reached && !frozen) {
        if (random < 10) {
            if (posY > posYTop) {
                posY -= 94;
            }
        }
        else if (random < 20) {
            if (posY < posYBottom) {
                posY += 94;
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

bool FootballZombie::isFlying() {
    return false;
}
