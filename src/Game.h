#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Level.h"
using namespace sf;

class Game {
private:
    int sunPoints;
    int lives;
    Level* currentLevel;
    bool isPlaying;
    bool isPaused;

public:
    Game();
    
    void pauseGame();




};

#endif // GAME_H