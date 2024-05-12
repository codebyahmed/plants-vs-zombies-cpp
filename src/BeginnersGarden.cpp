#include "BeginnersGarden.h"

BeginnersGarden::BeginnersGarden() {
    levelName = "Beginner's Garden";
    background = "bg_beginnersgarden.png";

    plantFactory[0] = new PeaShooterFactory(330, 0);
    plantFactory[1] = new SunflowerFactory(410, 0);
    plantFactory[2] = new RepeaterFactory(490, 0);
    plantFactory[3] = new WallnutFactory(570, 0);
    plantFactory[4] = new SnowPeaFactory(650, 0);
    plantFactory[5] = new CherryBombFactory(730, 0);
    plantFactory[6] = new FumeShroomFactory(810, 0);
    plants = new Plant*[45]; // 9 columns * 5 rows = 45
    plantCount = 0;

    zombieFactory[0] = new SimpleZombieFactory();
    zombieFactory[1] = new FootballZombieFactory();
    zombieFactory[2] = new FlyingZombieFactory();
    zombieFactory[3] = new DancingZombieFactory();
    zombies = new Zombie*[10]; // 10 zombies for first level
    zombieGoTime = new int[10];
    zombieCount = 0;

    lives = 3;
    this->sunPoints = 500;

    initZombies();
}

void BeginnersGarden::initZombies() {
    //Initialise a 1D array of int, size 5 with y values of block positions
    int verticalPos[5] = { 100, 194, 288, 382, 476};

    // Create 10 simple zombies and give them a random y position
    for (int i = 0; i < 10; i++) {
        int randomY = verticalPos[rand() % 5];
        int goTime = rand() % 60;
        
        // Check if the go time is already used by another zombie
        bool isGoTimeUsed = false;
        for (int j = 0; j < i; j++) {
            if (zombieGoTime[j] == goTime) {
                isGoTimeUsed = true;
                break;
            }
        }
        
        // If go time is already used, generate a new one
        while (isGoTimeUsed) {
            goTime = rand() % 60;
            isGoTimeUsed = false;
            for (int j = 0; j < i; j++) {
                if (zombieGoTime[j] == goTime) {
                    isGoTimeUsed = true;
                    break;
                }
            }
        }
        
        // Create a new random zombie
        int choice = rand() % 4;
        if (choice == 0) 
            zombies[i] = zombieFactory[0]->createZombie(900, randomY);
        else if (choice == 1)
            zombies[i] = zombieFactory[1]->createZombie(900, randomY);
        else if (choice == 2)
            zombies[i] = zombieFactory[2]->createZombie(900, randomY);
        else
            zombies[i] = zombieFactory[3]->createZombie(900, randomY);
        zombieGoTime[i] = goTime;
        zombieCount++;
    }
}