#include "PlantFactory.h"

////////////////// PlantFactory //////////////////

string PlantFactory::getModel() const {
    return model;
}

int PlantFactory::getPosX() const {
    return posX;
}

int PlantFactory::getPosY() const {
    return posY;
}

int PlantFactory::getCost() const {
    return cost;
}

bool PlantFactory::getIsAvailable() const {
    return isAvailable;
}

FloatRect PlantFactory::getBounds() {
    return FloatRect(posX, posY, 56, 82);
}

////////////////// PeaShooterFactory //////////////////

PeaShooterFactory::PeaShooterFactory(int x, int y, bool isAvailable) {
    model = "crd_peashooter.png";
    posX = x;
    posY = y;
    cost = 100;
    this->isAvailable = isAvailable;
}

Plant *PeaShooterFactory::createPlant(int &totalSun, int posX, int posY, float elapsedGameTime) {
    if (totalSun >= cost) {
        totalSun -= cost;
        return new PeaShooter(posX, posY, elapsedGameTime);
    }
    return nullptr;
}

////////////////// SunflowerFactory //////////////////

SunflowerFactory::SunflowerFactory(int x, int y, bool isAvailable) {
    model = "crd_sunflower.png";
    posX = x;
    posY = y;
    cost = 100;
    this->isAvailable = isAvailable;
}

Plant *SunflowerFactory::createPlant(int &totalSun, int posX, int posY, float elapsedGameTime) {
    if (totalSun >= cost) {
        totalSun -= cost;
        return new Sunflower(posX, posY, elapsedGameTime);
    }
    return nullptr;
}

////////////////// RepeaterFactory //////////////////

RepeaterFactory::RepeaterFactory(int x, int y, bool isAvailable) {
    model = "crd_repeater.png";
    posX = x;
    posY = y;
    cost = 200;
    this->isAvailable = isAvailable;
}

Plant *RepeaterFactory::createPlant(int &totalSun, int posX, int posY, float elapsedGameTime) {
    if (totalSun >= cost) {
        totalSun -= cost;
        return new Repeater(posX, posY, elapsedGameTime);
    }
    return nullptr;
}

////////////////// WallnutFactory //////////////////

WallnutFactory::WallnutFactory(int x, int y, bool isAvailable) {
    model = "crd_wallnut.png";
    posX = x;
    posY = y;
    cost = 50;
    this->isAvailable = isAvailable;
}

Plant *WallnutFactory::createPlant(int &totalSun, int posX, int posY, float elapsedGameTime) {
    if (totalSun >= cost) {
        totalSun -= cost;
        return new Wallnut(posX, posY, elapsedGameTime);
    }
    return nullptr;
}

////////////////// SnowPeaFactory //////////////////

SnowPeaFactory::SnowPeaFactory(int x, int y, bool isAvailable) {
    model = "crd_snowpea.png";
    posX = x;
    posY = y;
    cost = 175;
    this->isAvailable = isAvailable;
}

Plant *SnowPeaFactory::createPlant(int &totalSun, int posX, int posY, float elapsedGameTime) {
    if (totalSun >= cost) {
        totalSun -= cost;
        return new SnowPea(posX, posY, elapsedGameTime);
    }
    return nullptr;
}

////////////////// CherryBombFactory //////////////////

CherryBombFactory::CherryBombFactory(int x, int y, bool isAvailable) {
    model = "crd_cherrybomb.png";
    posX = x;
    posY = y;
    cost = 150;
    this->isAvailable = isAvailable;
}

Plant *CherryBombFactory::createPlant(int &totalSun, int posX, int posY, float elapsedGameTime) {
    if (totalSun >= cost) {
        totalSun -= cost;
        return new CherryBomb(posX, posY, elapsedGameTime);
    }
    return nullptr;
}

////////////////// FumeShroomFactory //////////////////

FumeShroomFactory::FumeShroomFactory(int x, int y, bool isAvailable) {
    model = "crd_fumeshroom.png";
    posX = x;
    posY = y;
    cost = 75;
    this->isAvailable = isAvailable;
}

Plant *FumeShroomFactory::createPlant(int &totalSun, int posX, int posY, float elapsedGameTime) {
    if (totalSun >= cost) {
        totalSun -= cost;
        return new FumeShroom(posX, posY, elapsedGameTime);
    }
    return nullptr;
}