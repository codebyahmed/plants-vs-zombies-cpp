#ifndef LEVEL_H
#define LEVEL_H

#include "Time.h"
#include "PlantFactory.h"
#include "ZombieFactory.h"

class Level {
protected:
    string levelName;
    string background;
    GameTime gameTime;

    PlantFactory* plantFactory[7];
    Plant** plants;
    int plantCount;

    ZombieFactory* zombieFactory[4];
    Zombie** zombies;
    int *zombieGoTime;
    int zombieCount;

    int lives;
    int sunPoints;

    bool cardSelected;
    int selectedCard;

public:
    Level(string levelName = "Level Name", string background = "Background.png");
    virtual void initZombies() = 0;

    void addPlant(RenderWindow &window, Event &event);

    void actionPlants(RenderWindow &window, Event &event);
    void actionZombies(RenderWindow &window);

    int zombiesAlive();

    void drawGame(RenderWindow &window);
    void drawBackground(RenderWindow &window);
    void drawCard(RenderWindow &window, int x, int y, string image);
    void drawDashboard(RenderWindow &window);
    void drawZombies(RenderWindow &window);
    void drawPlants(RenderWindow &window);
    void drawGrid(RenderWindow &window);

};

#endif // LEVEL_H