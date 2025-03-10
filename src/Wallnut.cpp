#include "Wallnut.h"

Wallnut::Wallnut(int x, int y, float elapsedGameTime) {
    model = "plt_wallnut.png";
    posX = x;
    posY = y;
    health = 300;
    creationTime=elapsedGameTime;
    isRolling = false;
    prjModel = "prj_wallnut.png";
}

Wallnut::Wallnut(int posX, int posY, int health) {
    model = "plt_wallnut.png";
    this->posX = posX;
    this->posY = posY;
    this->health = health;

    prjModel = "prj_wallnut.png";
}

void Wallnut::saveState(ofstream &file) {
    file << "Wallnut" << endl;
    file << posX << endl;
    file << posY << endl;
    file << health << endl;
}
