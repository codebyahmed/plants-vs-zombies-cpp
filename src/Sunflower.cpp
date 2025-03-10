#include "Sunflower.h"

Sunflower::Sunflower(int x, int y, float elapsedGameTime) {
    model = "plt_sunflower.png";
    posX = x;
    posY = y;
    health = 100;

    prjModel = "prj_sun.png";
    prjX = x - 15;
    prjY = y + 25;

    sunValue = 25;
    lastSunTime = elapsedGameTime;
    sunInterval = 3;
    isSunAvailable = false;
}

Sunflower::Sunflower(int posX, int posY, int health, int prjX, int prjY, float lastSunTime, bool isSunAvailable) {
    model = "plt_sunflower.png";
    this->posX = posX;
    this->posY = posY;
    this->health = health;

    prjModel = "prj_sun.png";
    this->prjX = prjX;
    this->prjY = prjY;

    sunValue = 25;
    this->lastSunTime = lastSunTime;
    sunInterval = 3;
    this->isSunAvailable = isSunAvailable;
}

void Sunflower::saveState(ofstream &file) {
    file << "Sunflower" << endl;
    file << posX << endl;
    file << posY << endl;
    file << health << endl;
    file << prjX << endl;
    file << prjY << endl;
    file << lastSunTime << endl;
    file << isSunAvailable << endl;
}

int Sunflower::produce(RenderWindow &window, float elapsedGameTime, Event &event) {
    if (!isSunAvailable) {
        if (elapsedGameTime - lastSunTime >= sunInterval) {
            isSunAvailable = true;
            lastSunTime = elapsedGameTime;
        }
    }
    else if (isSunAvailable) {
        Texture t;
        t.loadFromFile("./images/" + prjModel);
        Sprite s(t);
        s.setPosition(prjX, prjY);
        s.setScale(0.5, 0.5);
        window.draw(s);

        // Check if the sun is clicked
        if (event.type == Event::MouseButtonPressed) {
            if (event.mouseButton.button == Mouse::Left) {
                Vector2i mousePos = Mouse::getPosition(window);
                FloatRect bounds = s.getGlobalBounds();
                if (bounds.contains(mousePos.x, mousePos.y)) {
                    isSunAvailable = false;
                    lastSunTime = elapsedGameTime;
                    return sunValue; // Assuming sunValue is a member of Sunflower
                }
            }
        }
    }
    return 0; // Return 0 if no sun is clicked
}