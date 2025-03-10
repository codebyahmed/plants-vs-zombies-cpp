#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <fstream>
#include "BeginnersGarden.h"
#include "SunflowerFields.h"
#include "ZombieOutskirts.h"
using namespace sf;

class Game {
private:
    string titleImage;
    string homeImage;
    string loseImage;
    string startImage;
    string iconImage;
    string lvl1Image;
    string lvl2Image;
    string lvl3Image;

    Level* currentLevel;
    bool isPlaying;
    bool isPaused;

public:
    Game();
    Level* loadState(string filename);
    void drawOnScreen(RenderWindow &window, string img, int x, int y, float scale);
    void homeMenu(RenderWindow &window, Event &event);
    void play();
};

#endif // GAME_H