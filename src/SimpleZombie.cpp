#include "SimpleZombie.h"

SimpleZombie::SimpleZombie(int x, int y) {
    model = "zmb_simple.png";
    posX = x;
    posY = y;
    health = 75;
    speed = 0.75;
    attackDamage = 25;
    lastAttackTime = 0;
    frozen = false;
    frozenTime = 0;
}

SimpleZombie::SimpleZombie(float posX, float posY, int health, bool isAttacking, bool reached, bool frozen, float frozenTime) {
    model = "zmb_simple.png";
    this->posX = posX;
    this->posY = posY;
    this->health = health;
    this->isAttacking = isAttacking;
    this->reached = reached;
    this->frozen = frozen;
    this->frozenTime = frozenTime;
}

void SimpleZombie::saveState(ofstream &file) {
    file << "SimpleZombie" << endl;
    file << posX << endl;
    file << posY << endl;
    file << health << endl;
    file << isAttacking << endl;
    file << reached << endl;
    file << frozen << endl;
    file << frozenTime << endl;
}

void SimpleZombie::move(float elapsedGameTime) {
    if (!isAttacking && !reached && !frozen) {
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

bool SimpleZombie::isFlying() {
    return false;
}

// void SimpleZombie::attack(RenderWindow &window, float elapsedGameTime, Plant **plants, int plantCount) {
//     // Check if plant is in range
//     Plant* target;
//     for (int i = 0; i < plantCount; i++) {
//         if (plants[i]->getBounds().intersects(getBounds())) {
//             target = plants[i];
//             break;
//         }
//     }

//     // Attack the plant
//     if (target != nullptr) {
//         if (!isAttacking && elapsedGameTime - lastAttackTime >= attackInterval) {
//             isAttacking = true;
//             lastAttackTime = elapsedGameTime;
//         }
//         else if (isAttacking) {
//             // Draw the attack
//             RectangleShape attack(Vector2f(10, 10));
//             attack.setFillColor(Color::Red);
//             attack.setPosition(posX, posY);
//             window.draw(attack);

//             // Check if the attack hits the plant
//             if (attack.getGlobalBounds().intersects(target->getBounds())) {
//                 target->takeDamage(attackDamage);
//             }
//         }
//     }
//     else {
//         isAttacking = false;
//     }
// }
