#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H
using namespace std;

#include "Plant.h"

// Abstract PlantFactory class
class PlantFactory {

public:
    virtual Plant* createPlant(const std::string& type) = 0;
    virtual ~PlantFactory() {}
};

#endif // PLANTFACTORY_H
