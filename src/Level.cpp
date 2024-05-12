#include "Level.h"

Level::Level(string levelName, string background) {
    this->levelName = levelName;
    this->background = background;
    this->cardSelected = false;
}

void Level::addPlant(RenderWindow &window, Event &event) {
    // Check if mouse is clicked on the plant cards (plant factory)
    if (event.type == Event::MouseButtonPressed) {
        if (event.mouseButton.button == Mouse::Left) {
            int x = event.mouseButton.x;
            int y = event.mouseButton.y;

            if (cardSelected) {
                // Check if mouse is clicked on the grid (plant factory)
                for (int i = 0; i < 9; i++) {
                    for (int j = 0; j < 5; j++) {
                        if (FloatRect(170 + i * 80, 100 + j * 94, 80, 94).contains(x, y)) {
                            // Check if the plant can be placed on the grid
                            bool canPlace = true;
                            for (int k = 0; k < plantCount; k++) {
                                if (plants[k]->getBounds().contains(170 + i * 80, 100 + j * 94)) {
                                    canPlace = false;
                                    break;
                                }
                            }
                            // Place after checking sun (dont in factory)
                            if (canPlace) {
                                Plant* plant = plantFactory[selectedCard]->createPlant(sunPoints, 170 + i * 80, 100 + j * 94, gameTime.elapsedTime());
                                if (plant != nullptr) {
                                    plants[plantCount++] = plant;
                                    break;
                                }
                            }

                        }
                    }
                }
                cardSelected = false;
            }

            for (int i = 0; i < 7; i++) {
                if (plantFactory[i] != nullptr) {
                    FloatRect bounds = plantFactory[i]->getBounds();
                    if (bounds.contains(x, y)) {
                        cardSelected = true;
                        selectedCard = i;
                        break;
                    }
                }
            }
        }        
    }
}

void Level::actionPlants(RenderWindow &window, Event &event) {
    for (int i = 0; i < plantCount; i++) {
        if (plants[i]->isAlive()) {
            this->sunPoints += plants[i]->produce(window, gameTime.elapsedTime(), event);
            plants[i]->attack(window, gameTime.elapsedTime(), zombies, zombieCount);
        }
    }
}

void Level::actionZombies(RenderWindow &window) {
    for (int i = 0; i < zombieCount; i++) {
        if (zombies[i]->isAlive() && zombieGoTime[i] <= gameTime.elapsedTime()) {
            zombies[i]->move(gameTime.elapsedTime());
            //zombies[i]->attack(window, gameTime.elapsedTime(), plants, plantCount);
        }
        // Check if zombie reached the house
        if (zombies[i]->isAlive() && zombies[i]->getReached()) {
            lives -= 1;
            zombies[i]->setAlive(false);
        }
    }
}

int Level::zombiesAlive() {
    int count = 0;
    for (int i = 0; i < zombieCount; i++) {
        if (zombies[i]->isAlive()) {
            count++;
        }
    }
    return count;
}

void Level::drawGame(RenderWindow &window) {
    drawBackground(window);
    drawDashboard(window);
    //drawGrid(window);
    drawZombies(window);
    drawPlants(window);
}

void Level::drawBackground(RenderWindow &window) {
    Texture t;
	t.loadFromFile("./images/" + background);
	Sprite s(t);
	window.draw(s);
}

void Level::drawCard(RenderWindow &window, int x, int y, string image) {
    Texture t;
    t.loadFromFile(image);
    Sprite s(t);
    s.setPosition(x, y);
    s.setScale(0.6, 0.6);
    window.draw(s);
}

void Level::drawDashboard(RenderWindow &window) {
    // Lives card
    drawCard(window, 10, 0, "./images/crd_lives.png");

    // Sun card
    drawCard(window, 90, 0, "./images/crd_sun.png");

    // Zombie card
    drawCard(window, 170, 0, "./images/crd_zombie.png");

    // Plant cards
    for (int i = 0; i < 7; i++) {
        if (plantFactory[i] != nullptr) {
            int posX = plantFactory[i]->getPosX();
            int posY = plantFactory[i]->getPosY();
            string image = plantFactory[i]->getModel();
            drawCard(window, posX, posY, "./images/" + image);
        }
    }

    // Sun points text
    Font font;
    font.loadFromFile("./fonts/serio.ttf");
    Text text;
    text.setFont(font);
    text.setString(to_string(sunPoints));
    text.setCharacterSize(12);
    text.setFillColor(Color::Black);
    text.setPosition(100, 65);
    window.draw(text);

    // Lives text
    text.setString(to_string(lives));
    text.setPosition(35, 65);
    window.draw(text);

    // Zombie count text
    text.setString(to_string(zombiesAlive()));
    text.setPosition(190, 65);
    window.draw(text);
}

void Level::drawZombies(RenderWindow &window) {
    for (int i = 0; i < zombieCount; i++) {
        if (zombies[i]->isAlive() && zombieGoTime[i] <= gameTime.elapsedTime() && zombies[i]->getReached() == false) {
            zombies[i]->draw(window);
        }
    }
}

void Level::drawPlants(RenderWindow &window) {
    for (int i = 0; i < plantCount; i++) {
        if (plants[i]->isAlive()) {
            plants[i]->draw(window);
        }
    }
}

void Level::drawGrid(RenderWindow &window) {
    RectangleShape grid[9][5];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 5; j++) {
            grid[i][j].setSize(Vector2f(80, 94));
            grid[i][j].setFillColor(Color::Transparent);
            grid[i][j].setOutlineThickness(1);
            grid[i][j].setOutlineColor(Color(0, 100, 0)); // Dark green color
            grid[i][j].setPosition(170 + i * 80, 90 + j * 94);
            window.draw(grid[i][j]);
        }
    }
}

