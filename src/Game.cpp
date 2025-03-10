#include "Game.h"

Game::Game() {
    titleImage = "scr_title.png";
    homeImage = "scr_home.png";
    loseImage = "scr_lose.png";
    startImage = "scr_start.png";
    iconImage = "icon.png";
    lvl1Image = "lvl_1.png";
    lvl2Image = "lvl_2.png";
    lvl3Image = "lvl_3.png";
    isPlaying = false;
    isPaused = false;
}

Level* Game::loadState(string filename) {
    string levelName;
    int lives;
    int sunPoints;
    float elapsedTime;
    int plantCount;
    int zombieCount;
    string plants; //Plant information
    string zombies; //Zombie information

    ifstream file;
    file.open(filename);
    string line;
    int lineCount = 0;
    while (getline(file, line)) {
        if (lineCount == 0) {
            levelName = line;
        }
        else if (lineCount == 1) {
            lives = stoi(line);
        }
        else if (lineCount == 2) {
            sunPoints = stoi(line);
        }
        else if (lineCount == 3) {
            elapsedTime = stof(line);
        }
        else if (lineCount == 4) {
            plantCount = stoi(line);
        }
        else if (lineCount == 5) {
            zombieCount = stoi(line);
        }
        else {
            if (line == "plants") {
                while (getline(file, line)) {
                    if (line == "zombies") {
                        break;
                    }
                    plants += line + "\n";
                }
            }
            if (line == "zombies") {
                while (getline(file, line)) {
                    if (line == "end") {
                        break;
                    }
                    zombies += line + "\n";
                }
            }
        }
        
        lineCount += 1;
    }
    file.close();

    if (levelName == "Beginner's Garden") {
        return new BeginnersGarden(lives, sunPoints, elapsedTime, plantCount, zombieCount, plants, zombies);
    }
    else if (levelName == "Zombie Outskirts") {
        return new ZombieOutskirts(lives, sunPoints, elapsedTime, plantCount, zombieCount, plants, zombies);
    }
    else if (levelName == "Sunflower Fields") {
        return new SunflowerFields(lives, sunPoints, elapsedTime, plantCount, zombieCount, plants, zombies);
    }

    return nullptr;
}

void Game::drawOnScreen(RenderWindow &window, string img, int x, int y, float scale) {
    Texture t;
	t.loadFromFile("./images/" + img);
	Sprite s(t);
    s.setPosition(x, y);
    s.setScale(scale, scale);
	window.draw(s);
}

void Game::homeMenu(RenderWindow &window, Event &event) {
    //Background
    drawOnScreen(window, homeImage, 0, 0, 1);

    //Title
    drawOnScreen(window, titleImage, 375, 0, 1);

    //Levels
    drawOnScreen(window, lvl1Image, 250, 225, 1);
    drawOnScreen(window, lvl2Image, 450, 225, 1);
    drawOnScreen(window, lvl3Image, 650, 225, 1);

    //Draw blue box for load game with text
    RectangleShape loadGameBox(Vector2f(200, 50));
    loadGameBox.setFillColor(Color(0, 0, 255, 100));
    loadGameBox.setPosition(440, 400);
    window.draw(loadGameBox);

    Font font;
    font.loadFromFile("./fonts/serio.ttf");
    Text loadGameText;
    loadGameText.setFont(font);
    loadGameText.setString("Load Game");
    loadGameText.setCharacterSize(24);
    loadGameText.setFillColor(Color::White);
    loadGameText.setPosition(480, 410);
    window.draw(loadGameText);


    //Event handling
    if (event.type == Event::MouseButtonPressed) {
        if (event.mouseButton.button == Mouse::Left) {
            if (event.mouseButton.x >= 250 && event.mouseButton.x <= 250 + 178 && event.mouseButton.y >= 225 && event.mouseButton.y <= 225 + 100) {
                isPlaying = true;
                currentLevel = new BeginnersGarden();
            }
            else if (event.mouseButton.x >= 450 && event.mouseButton.x <= 450 + 178 && event.mouseButton.y >= 225 && event.mouseButton.y <= 225 + 100) {
                isPlaying = true;
                currentLevel = new ZombieOutskirts();
            }
            else if (event.mouseButton.x >= 650 && event.mouseButton.x <= 650 + 178 && event.mouseButton.y >= 225 && event.mouseButton.y <= 225 + 100) {
                isPlaying = true;
                currentLevel = new SunflowerFields();
            }
            else if (event.mouseButton.x >= 440 && event.mouseButton.x <= 440 + 200 && event.mouseButton.y >= 400 && event.mouseButton.y <= 400 + 50) {
                isPlaying = true;
                currentLevel = loadState("save.txt");
            }
        }
    }
}

void Game::play() {
    //Create a window, n*n
	RenderWindow window(VideoMode(1067, 600), "Plants Vs Zombies");

	//Game icon
	Image icon;
	icon.loadFromFile("./images/" + iconImage);
	window.setIcon(100, 100, icon.getPixelsPtr());

    int gameStatus = 0;
    int statusChangeTimer = 0;

	while (window.isOpen()) {
		//Check if the window is closed
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

        if (!isPlaying && !isPaused) {
            homeMenu(window, event);
        }
        else if (isPlaying && !isPaused) {
            gameStatus = currentLevel->play(window, event);
        }

        if (gameStatus == 2) {
            isPlaying = false;
            isPaused = false;
            drawOnScreen(window, loseImage, 0, 0, 1);
            if (statusChangeTimer < 100) {
                statusChangeTimer += 1;
            }
            else {
                statusChangeTimer = 0;
                gameStatus = 0;
            }
        }
        else if (gameStatus == 1) {
            isPlaying = false;
            isPaused = false;
            //You won screen
        }

		//Display the window
		window.display();
	}
}
