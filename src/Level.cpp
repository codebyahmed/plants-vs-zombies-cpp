#include "Level.h"

void Level::drawOnScreen(RenderWindow &window, string img, int x, int y, float scale) {
    Texture t;
	t.loadFromFile("./images/" + img);
	Sprite s(t);
    s.setPosition(x, y);
    s.setScale(scale, scale);
	window.draw(s);
}

Level::Level(string levelName, string background) {
    this->levelName = levelName;
    this->background = background;
    this->startImage = "scr_start.png";
    this->cardSelected = false;
    this->isPaused = false;
}

void Level::initZombies() {
    //Initialise a 1D array of int, size 5 with y values of block positions
    int verticalPos[5] = { 100, 194, 288, 382, 476};

    int zombiesCreatedCount[4] = {0, 0, 0, 0};

    // Create totalZombieCount simple zombies and give them a random y position
    for (int i = 0; i < totalZombieCount; i++) {
        int randomY = verticalPos[rand() % 5];
        int goTime = rand() % 60;
        
        // Check if the go time is already used by another zombie
        bool isGoTimeUsed = false;
        for (int j = 0; j < i; j++) {
            if (zombieGoTime[j] == goTime) {
                isGoTimeUsed = true;
                break;
            }
        }
        
        // If go time is already used, generate a new one
        while (isGoTimeUsed) {
            goTime = rand() % 60;
            isGoTimeUsed = false;
            for (int j = 0; j < i; j++) {
                if (zombieGoTime[j] == goTime) {
                    isGoTimeUsed = true;
                    break;
                }
            }
        }
        
        // Create a simple zombie
        if (zombiesCreatedCount[0] < zombieCount[0]) {
            zombies[i] = zombieFactory[0]->createZombie(900, randomY);
            zombiesCreatedCount[0]++;
        }
        // Create a football zombie
        else if (zombiesCreatedCount[1] < zombieCount[1]) {
            zombies[i] = zombieFactory[1]->createZombie(900, randomY);
            zombiesCreatedCount[1]++;
        }
        // Create a flying zombie
        else if (zombiesCreatedCount[2] < zombieCount[2]) {
            zombies[i] = zombieFactory[2]->createZombie(900, randomY);
            zombiesCreatedCount[2]++;
        }
        // Create a dancing zombie
        else if (zombiesCreatedCount[3] < zombieCount[3]) {
            zombies[i] = zombieFactory[3]->createZombie(900, randomY);
            zombiesCreatedCount[3]++;
        }
        zombieGoTime[i] = goTime;
    }

    // Increase go time by 5 seconds because of start screen
    for (int i = 0; i < totalZombieCount; i++) {
        zombieGoTime[i] += 5;
    }
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
                if (plantFactory[i] != nullptr && plantFactory[i]->getIsAvailable()) {
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
            plants[i]->attack(window, gameTime.elapsedTime(), zombies, totalZombieCount);
        }
    }
}

void Level::actionZombies(RenderWindow &window) {
    for (int i = 0; i < totalZombieCount; i++) {
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
    for (int i = 0; i < totalZombieCount; i++) {
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
        if (plantFactory[i] != nullptr && plantFactory[i]->getIsAvailable()) {
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

    // Pause button
    RectangleShape pauseButton(Vector2f(30, 30));
    pauseButton.setFillColor(Color::White);
    pauseButton.setOutlineThickness(1);
    pauseButton.setOutlineColor(Color::Black);
    pauseButton.setPosition(1000, 10);
    window.draw(pauseButton);

    // Pause text
    Text pauseText;
    pauseText.setFont(font);
    pauseText.setString("P");
    pauseText.setCharacterSize(20);
    pauseText.setFillColor(Color::Black);
    pauseText.setPosition(1010, 13);
    window.draw(pauseText);

    // Save button, green box with black text, left of pause buton
    RectangleShape saveButton(Vector2f(30, 30));
    saveButton.setFillColor(Color::Green);
    saveButton.setOutlineThickness(1);
    saveButton.setOutlineColor(Color::Black);
    saveButton.setPosition(960, 10);
    window.draw(saveButton);

    // Save text
    Text saveText;
    saveText.setFont(font);
    saveText.setString("S");
    saveText.setCharacterSize(20);
    saveText.setFillColor(Color::Black);
    saveText.setPosition(970, 13);
    window.draw(saveText);
}

void Level::drawZombies(RenderWindow &window) {
    for (int i = 0; i < totalZombieCount; i++) {
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

void Level::toggleSave(RenderWindow &window, Event &event) {
    if (event.type == Event::MouseButtonPressed) {
        if (event.mouseButton.button == Mouse::Left) {
            int x = event.mouseButton.x;
            int y = event.mouseButton.y;

            if (FloatRect(960, 10, 30, 30).contains(x, y)) {
                saveState("save.txt");
            }
        }
    }
}

void Level::togglePause(RenderWindow &window, Event &event) {
    if (event.type == Event::MouseButtonPressed) {
        if (event.mouseButton.button == Mouse::Left) {
            int x = event.mouseButton.x;
            int y = event.mouseButton.y;

            if (FloatRect(1000, 5, 40, 40).contains(x, y)) {
                if (isPaused) {
                    isPaused = false;
                    gameTime.addTime(gameTime.elapsedTime() - pauseTime);
                }
                else {
                    isPaused = true;
                    pauseTime = gameTime.elapsedTime();
                }
            }
        }
    }
}

void Level::saveState(string filename) {
    // Save the state of the level to a file
    ofstream file;
    file.open(filename);

    // Save level information
    file << levelName << endl;
    file << lives << endl;
    file << sunPoints << endl;
    file << gameTime.elapsedTime() << endl;
    file << plantCount << endl;
    file << totalZombieCount << endl;

    // Save the state of the plants
    file << "plants" << endl;
    for (int i = 0; i < plantCount; i++) {
        plants[i]->saveState(file);
    }

    // Save the state of the zombies
    file << "zombies" << endl;
    for (int i = 0; i < totalZombieCount; i++) {
        zombies[i]->saveState(file);
        file << zombieGoTime[i] << endl;
    }
    file << "end" << endl;

    file.close();
}

void Level::loadPlants(string plantsData) {
    // Load the state of the plants from a file
    istringstream iss(plantsData);
    string line;
    plantCount = 0;
     
    while (getline(iss, line)) {
        if (line == "PeaShooter") {
            int posX, posY, health, prjX, prjY;
            float lastPeaTime;
            bool isPeaAttacking;
            int lineCount = 0;
            while (getline(iss, line)) {
                if (lineCount == 0) {
                    posX = stoi(line);
                }
                else if (lineCount == 1) {
                    posY = stoi(line);
                }
                else if (lineCount == 2) {
                    health = stoi(line);
                }
                else if (lineCount == 3) {
                    prjX = stoi(line);
                }
                else if (lineCount == 4) {
                    prjY = stoi(line);
                }
                else if (lineCount == 5) {
                    lastPeaTime = stof(line);
                }
                else if (lineCount == 6) {
                    isPeaAttacking = stoi(line);
                }
                lineCount += 1;
            }
            plants[plantCount++] = new PeaShooter(posX, posY, health, prjX, prjY, lastPeaTime, isPeaAttacking);
        }
        else if (line == "Sunflower") {
            int posX, posY, health, prjX, prjY;
            float lastSunTime;
            bool isSunAvailable;
            int lineCount = 0;
            while (getline(iss, line)) {
                if (lineCount == 0) {
                    posX = stoi(line);
                }
                else if (lineCount == 1) {
                    posY = stoi(line);
                }
                else if (lineCount == 2) {
                    health = stoi(line);
                }
                else if (lineCount == 3) {
                    prjX = stoi(line);
                }
                else if (lineCount == 4) {
                    prjY = stoi(line);
                }
                else if (lineCount == 5) {
                    lastSunTime = stof(line);
                }
                else if (lineCount == 6) {
                    isSunAvailable = stoi(line);
                }
                lineCount += 1;
            }
            plants[plantCount++] = new Sunflower(posX, posY, health, prjX, prjY, lastSunTime, isSunAvailable);
        }
        else if (line == "Repeater") {
            int posX, posY, health, prjX, prjY, prj1X, prj1Y;
            float lastPeaTime0, lastPeaTime1;
            bool isPeaAttacking0, isPeaAttacking1;
            int lineCount = 0;
            while (getline(iss, line)) {
                if (lineCount == 0) {
                    posX = stoi(line);
                }
                else if (lineCount == 1) {
                    posY = stoi(line);
                }
                else if (lineCount == 2) {
                    health = stoi(line);
                }
                else if (lineCount == 3) {
                    prjX = stoi(line);
                }
                else if (lineCount == 4) {
                    prjY = stoi(line);
                }
                else if (lineCount == 5) {
                    prj1X = stoi(line);
                }
                else if (lineCount == 6) {
                    prj1Y = stoi(line);
                }
                else if (lineCount == 7) {
                    lastPeaTime0 = stof(line);
                }
                else if (lineCount == 8) {
                    lastPeaTime1 = stof(line);
                }
                else if (lineCount == 9) {
                    isPeaAttacking0 = stoi(line);
                }
                else if (lineCount == 10) {
                    isPeaAttacking1 = stoi(line);
                }
                lineCount += 1;
            }
            plants[plantCount++] = new Repeater(posX, posY, health, prjX, prjY, prj1X, prj1Y, lastPeaTime0, lastPeaTime1, isPeaAttacking0, isPeaAttacking1);
        }
        else if (line == "Wallnut") {
            int posX, posY, health;
            bool isWallnutAvailable;
            int lineCount = 0;
            while (getline(iss, line)) {
                if (lineCount == 0) {
                    posX = stoi(line);
                }
                else if (lineCount == 1) {
                    posY = stoi(line);
                }
                else if (lineCount == 2) {
                    health = stoi(line);
                }
                lineCount += 1;
            }
            plants[plantCount++] = new Wallnut(posX, posY, health);
        }
        else if (line == "SnowPea") {
            int posX, posY, health, prjX, prjY;
            float lastPeaTime;
            bool isPeaAttacking;
            int lineCount = 0;
            while (getline(iss, line)) {
                if (lineCount == 0) {
                    posX = stoi(line);
                }
                else if (lineCount == 1) {
                    posY = stoi(line);
                }
                else if (lineCount == 2) {
                    health = stoi(line);
                }
                else if (lineCount == 3) {
                    prjX = stoi(line);
                }
                else if (lineCount == 4) {
                    prjY = stoi(line);
                }
                else if (lineCount == 5) {
                    lastPeaTime = stof(line);
                }
                else if (lineCount == 6) {
                    isPeaAttacking = stoi(line);
                }
                lineCount += 1;
            }
            plants[plantCount++] = new SnowPea(posX, posY, health, prjX, prjY, lastPeaTime, isPeaAttacking);
        }
        else if (line == "CherryBomb") {
            int posX, posY, health, prjX, prjY, blastDamage;
            float blastRadius, blastTime, creationTime;
            int lineCount = 0;
            while (getline(iss, line)) {
                if (lineCount == 0) {
                    posX = stoi(line);
                }
                else if (lineCount == 1) {
                    posY = stoi(line);
                }
                else if (lineCount == 2) {
                    health = stoi(line);
                }
                else if (lineCount == 3) {
                    prjX = stoi(line);
                }
                else if (lineCount == 4) {
                    prjY = stoi(line);
                }
                else if (lineCount == 5) {
                    blastRadius = stof(line);
                }
                else if (lineCount == 6) {
                    blastDamage = stoi(line);
                }
                else if (lineCount == 7) {
                    blastTime = stof(line);
                }
                else if (lineCount == 8) {
                    creationTime = stof(line);
                }
                lineCount += 1;
            }
        }
        else if (line == "FumeShroom") {
            int posX, posY, health, prjX, prjY;
            float lastShroomTIme;
            bool isShrooming;
            int lineCount = 0;
            while (getline(iss, line)) {
                if (lineCount == 0) {
                    posX = stoi(line);
                }
                else if (lineCount == 1) {
                    posY = stoi(line);
                }
                else if (lineCount == 2) {
                    health = stoi(line);
                }
                else if (lineCount == 3) {
                    prjX = stoi(line);
                }
                else if (lineCount == 4) {
                    prjY = stoi(line);
                }
                else if (lineCount == 5) {
                    lastShroomTIme = stof(line);
                }
                else if (lineCount == 6) {
                    isShrooming = stoi(line);
                }
                lineCount += 1;
            }
            plants[plantCount++] = new FumeShroom(posX, posY, health, prjX, prjY, lastShroomTIme, isShrooming);
        }
    }   
}

void Level::loadZombies(string zombiesData) {
    // Load the state of the zombies from a file
    istringstream iss(zombiesData);
    string line;
    totalZombieCount = 0;
    while (getline(iss, line)) {
        if (line == "SimpleZombie") {
            float posX, posY, frozenTime;
            int health;
            bool isAttacking, reached, frozen;
            int lineCount = 0;
            while (getline(iss, line)) {
                if (lineCount == 0) {
                    posX = stof(line);
                }
                else if (lineCount == 1) {
                    posY = stof(line);
                }
                else if (lineCount == 2) {
                    health = stoi(line);
                }
                else if (lineCount == 3) {
                    isAttacking = stoi(line);
                }
                else if (lineCount == 4) {
                    reached = stoi(line);
                }
                else if (lineCount == 5) {
                    frozen = stoi(line);
                }
                else if (lineCount == 6) {
                    frozenTime = stof(line);
                }
                else if (lineCount == 7) {
                    zombieGoTime[totalZombieCount] = stoi(line);
                }
                lineCount += 1;
            }
            zombies[totalZombieCount++] = new SimpleZombie(posX, posY, health, isAttacking, reached, frozen, frozenTime);
        }
        else if (line == "FootballZombie") {
            float posX, posY, frozenTime;
            int health;
            bool isAttacking, reached, frozen;
            int lineCount = 0;
            while (getline(iss, line)) {
                if (lineCount == 0) {
                    posX = stof(line);
                }
                else if (lineCount == 1) {
                    posY = stof(line);
                }
                else if (lineCount == 2) {
                    health = stoi(line);
                }
                else if (lineCount == 3) {
                    isAttacking = stoi(line);
                }
                else if (lineCount == 4) {
                    reached = stoi(line);
                }
                else if (lineCount == 5) {
                    frozen = stoi(line);
                }
                else if (lineCount == 6) {
                    frozenTime = stof(line);
                }
                else if (lineCount == 7) {
                    zombieGoTime[totalZombieCount] = stoi(line);
                }
                lineCount += 1;
            }
            zombies[totalZombieCount++] = new FootballZombie(posX, posY, health, isAttacking, reached, frozen, frozenTime);
        }
        else if (line == "FlyingZombie") {
            float posX, posY, frozenTime;
            int health;
            bool isAttacking, reached, frozen;
            int lineCount = 0;
            while (getline(iss, line)) {
                if (lineCount == 0) {
                    posX = stof(line);
                }
                else if (lineCount == 1) {
                    posY = stof(line);
                }
                else if (lineCount == 2) {
                    health = stoi(line);
                }
                else if (lineCount == 3) {
                    isAttacking = stoi(line);
                }
                else if (lineCount == 4) {
                    reached = stoi(line);
                }
                else if (lineCount == 5) {
                    frozen = stoi(line);
                }
                else if (lineCount == 6) {
                    frozenTime = stof(line);
                }
                else if (lineCount == 7) {
                    zombieGoTime[totalZombieCount] = stoi(line);
                }
                lineCount += 1;
            }
            zombies[totalZombieCount++] = new FlyingZombie(posX, posY, health, isAttacking, reached, frozen, frozenTime);
        }
        else if (line == "DancingZombie") {
            float posX, posY, frozenTime;
            int health;
            bool isAttacking, reached, frozen;
            int lineCount = 0;
            while (getline(iss, line)) {
                if (lineCount == 0) {
                    posX = stof(line);
                }
                else if (lineCount == 1) {
                    posY = stof(line);
                }
                else if (lineCount == 2) {
                    health = stoi(line);
                }
                else if (lineCount == 3) {
                    isAttacking = stoi(line);
                }
                else if (lineCount == 4) {
                    reached = stoi(line);
                }
                else if (lineCount == 5) {
                    frozen = stoi(line);
                }
                else if (lineCount == 6) {
                    frozenTime = stof(line);
                }
                else if (lineCount == 7) {
                    zombieGoTime[totalZombieCount] = stoi(line);
                }
                lineCount += 1;
            }
            zombies[totalZombieCount++] = new DancingZombie(posX, posY, health, isAttacking, reached, frozen, frozenTime);
        }
    }
}

int Level::play(RenderWindow &window, Event &event) {

    drawGame(window);
    // Show start screen for 5 seconds after the level starts
    if (gameTime.elapsedTime() <= 5) {
        drawOnScreen(window, startImage, 400, 200, 1);
        return 0;
    }

    if (!isPaused) {
        addPlant(window, event);
        actionPlants(window, event);
        actionZombies(window);
        toggleSave(window, event);
    }
    
    togglePause(window, event);

    if (zombiesAlive() == 0) {
        return 1;
    }
    else if (lives == 0) {
        return 2;
    }
    else {
        return 0;
    }
}

Level::~Level() {
    for (int i = 0; i < 7; i++) {
        delete plantFactory[i];
    }

    for (int i = 0; i < plantCount; i++) {
        delete plants[i];
    }

    for (int i = 0; i < 4; i++) {
        delete zombieFactory[i];
    }

    for (int i = 0; i < totalZombieCount; i++) {
        delete zombies[i];
    }
}
