#include "BeginnersGarden.h"

BeginnersGarden::BeginnersGarden() {
    levelName = "Beginner's Garden";
    background = "bg_1.png";
    startImage = "scr_start.png";

    plantFactory[0] = new PeaShooterFactory(330, 0);
    plantFactory[1] = new SunflowerFactory(410, 0);
    plantFactory[2] = new RepeaterFactory(490, 0);
    plantFactory[3] = new WallnutFactory(570, 0, false);
    plantFactory[4] = new SnowPeaFactory(650, 0, false);
    plantFactory[5] = new CherryBombFactory(730, 0, false);
    plantFactory[6] = new FumeShroomFactory(810, 0, false);
    plants = new Plant*[50];
    plantCount = 0;

    totalZombieCount = 10;
    zombieCount[0] = 7;
    zombieCount[1] = 3;
    zombieFactory[0] = new SimpleZombieFactory();
    zombieFactory[1] = new FootballZombieFactory();
    zombieFactory[2] = new FlyingZombieFactory();
    zombieFactory[3] = new DancingZombieFactory();
    zombies = new Zombie*[totalZombieCount];
    zombieGoTime = new int[totalZombieCount];

    lives = 3;
    this->sunPoints = 500;
    this->isPaused = false;

    initZombies();
}

BeginnersGarden::BeginnersGarden(int lives, int sunPoints, float elapsedTime, int plantCount, int zombieCount, string plantsData, string zombiesData) {
    levelName = "Beginner's Garden";
    background = "bg_1.png";
    startImage = "scr_start.png";

    plantFactory[0] = new PeaShooterFactory(330, 0);
    plantFactory[1] = new SunflowerFactory(410, 0);
    plantFactory[2] = new RepeaterFactory(490, 0);
    plantFactory[3] = new WallnutFactory(570, 0, false);
    plantFactory[4] = new SnowPeaFactory(650, 0, false);
    plantFactory[5] = new CherryBombFactory(730, 0, false);
    plantFactory[6] = new FumeShroomFactory(810, 0, false);
    plants = new Plant*[50];

    zombieFactory[0] = new SimpleZombieFactory();
    zombieFactory[1] = new FootballZombieFactory();
    zombieFactory[2] = new FlyingZombieFactory();
    zombieFactory[3] = new DancingZombieFactory();
    this->totalZombieCount = zombieCount;
    zombies = new Zombie*[totalZombieCount];
    zombieGoTime = new int[totalZombieCount];

    this->lives = lives;
    this->sunPoints = sunPoints;
    this->isPaused = false;
    gameTime.setStartTime(elapsedTime);
    this->plantCount = plantCount;

    loadPlants(plantsData);
    loadZombies(zombiesData);
}
