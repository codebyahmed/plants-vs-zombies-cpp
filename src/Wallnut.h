#ifndef WALLNUT_H
#define WALLNUT_H

#include "Plant.h"

class Wallnut : public Plant {
private:
    bool isRolling;
    float creationTime;

public:
    Wallnut(int x = -1, int y = -1, float elapsedGameTime = 0);
    Wallnut(int posX, int posY, int health);

    void saveState(ofstream &file) override;
    // Not used in Wallnut
    void attack(RenderWindow &window, float elapsedGameTime, Zombie **zombies, int zombieCount) {

        //roll the walnut
        if (isRolling == false) {
            if(elapsedGameTime-creationTime>2){
                    isRolling=true;
            }

        }

        if(isRolling==true){
            posX+=5;
        }

        if (posX>900){
            isRolling=false;
            health=0;
        }

    };
    
    int produce(RenderWindow &window, float elapsedGameTime, Event &event) { return 0; };
};

#endif // WALLNUT_H
