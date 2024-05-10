#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include "PeaShooter.h"
#include "Sunflower.h"

// Abstract PlantFactory class
class PlantFactory {
public:
    virtual Plant* createPlant() = 0;
};

// Concrete PlantFactory classes

class PeaShooterFactory : public PlantFactory {
public:
    Plant* createPlant() override;
};

class SunflowerFactory : public PlantFactory {
public:
    Plant* createPlant() override;
};

#endif // PLANTFACTORY_H