#ifndef LEVEL_H
#define LEVEL_H

#include <fstream>
#include "Time.h"
#include "PlantFactory.h"
#include "ZombieFactory.h"

class Level {
protected:
    string levelName;
    string background;
    string startImage;
    GameTime gameTime;

    PlantFactory* plantFactory[7];
    Plant** plants;
    int plantCount;

    ZombieFactory* zombieFactory[4];
    Zombie** zombies;
    int *zombieGoTime;
    int totalZombieCount;
    int zombieCount[4];

    int lives;
    int sunPoints;

    bool cardSelected;
    int selectedCard;

    bool isPaused;
    float pauseTime;

    void drawOnScreen(RenderWindow &window, string img, int x, int y, float scale);

public:
    Level(string levelName = "Level Name", string background = "Background.png");
    void initZombies();

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

    void toggleSave(RenderWindow &window, Event &event);
    void togglePause(RenderWindow &window, Event &event);

    void saveState(string filename);
    void loadPlants(string plantsData);
    void loadZombies(string zombiesData);

    int play(RenderWindow &window, Event &event);

    ~Level();
};

#endif // LEVEL_H