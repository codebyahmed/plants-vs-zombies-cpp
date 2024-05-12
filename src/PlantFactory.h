#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include "PeaShooter.h"
#include "Sunflower.h"
#include "Repeater.h"
#include "Wallnut.h"
#include "SnowPea.h"
#include "CherryBomb.h"
#include "FumeShroom.h"

// Abstract PlantFactory class
class PlantFactory {
protected:
    // Plant card information to display on dashboard
    string model;
    int posX;
    int posY;
    int cost;
    bool isAvailable;

public:
    // Getters
    string getModel() const;
    int getPosX() const;
    int getPosY() const;
    int getCost() const;

    FloatRect getBounds();

    // Pure virtual functions
    virtual Plant* createPlant(int &totalSun, int posX, int posY, float elapsedGameTime) = 0;
};

// Concrete PlantFactory classes

class PeaShooterFactory : public PlantFactory {
public:
    PeaShooterFactory(int x, int y, bool isAvailable = true);
    Plant* createPlant(int &totalSun, int posX, int posY, float elapsedGameTime) override;
};

class SunflowerFactory : public PlantFactory {
public:
    SunflowerFactory(int x, int y, bool isAvailable = true);
    Plant* createPlant(int &totalSun, int posX, int posY, float elapsedGameTime) override;
};

class RepeaterFactory : public PlantFactory {
public:
    RepeaterFactory(int x, int y, bool isAvailable = true);
    Plant* createPlant(int &totalSun, int posX, int posY, float elapsedGameTime) override;
};

class WallnutFactory : public PlantFactory {
public:
    WallnutFactory(int x, int y, bool isAvailable = true);
    Plant* createPlant(int &totalSun, int posX, int posY, float elapsedGameTime) override;
};

class SnowPeaFactory : public PlantFactory {
public:
    SnowPeaFactory(int x, int y, bool isAvailable = true);
    Plant* createPlant(int &totalSun, int posX, int posY, float elapsedGameTime) override;
};

class CherryBombFactory : public PlantFactory {
public:
    CherryBombFactory(int x, int y, bool isAvailable = true);
    Plant* createPlant(int &totalSun, int posX, int posY, float elapsedGameTime) override;
};

class FumeShroomFactory : public PlantFactory {
public:
    FumeShroomFactory(int x, int y, bool isAvailable = true);
    Plant* createPlant(int &totalSun, int posX, int posY, float elapsedGameTime) override;
};

#endif // PLANTFACTORY_H