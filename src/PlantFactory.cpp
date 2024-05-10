#include "PlantFactory.h"

Plant* PeaShooterFactory::createPlant() {
    return new PeaShooter();
}

Plant* SunflowerFactory::createPlant() {
    return new Sunflower();
}