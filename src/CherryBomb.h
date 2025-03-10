#ifndef CHERRYBOMB_H
#define CHERRYBOMB_H

#include "Plant.h"

class CherryBomb : public Plant {
private:
    // Information of the cherryBomb blast
    float blastRadius;
    int blastDamage;
    float blastTime; //Seconds to detonate
    float creationTime; //Time when plant was created


public:
    CherryBomb(int x = -1, int y = -1, float elapsedGameTime = 0);
    CherryBomb(int posX, int posY, int health, int prjX, int prjY, int blastRadius, int blastDamage, int blastTime, float creationTime);

    void saveState(ofstream &file) override;
    void attack(RenderWindow &window, float elapsedGameTime, Zombie **zombies, int zombieCount);
    // Not used in PeaShooter
    int produce(RenderWindow &window, float elapsedGameTime, Event &event) { return 0; };
};

#endif // CHERRYBOMB_H
