#include <SFML/Graphics.hpp>

#include "BeginnersGarden.h"
#include "PlantFactory.h"
#include "ZombieFactory.h"
#include "Time.h"


int main()
{
	//Create a window, n*n
	RenderWindow window(VideoMode(1067, 600), "Plants Vs Zombies");

	//Game icon
	Image icon;
	if (!icon.loadFromFile("./images/icon.png")) {
		return 1;
	}
	window.setIcon(100, 100, icon.getPixelsPtr());

	Level *bg = new BeginnersGarden();
	
	//Game loop
	while (window.isOpen()) {
		//Check if the window is closed
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		bg->drawGame(window);
		bg->addPlant(window, event);
		bg->actionPlants(window, event);
		bg->actionZombies(window);

		//Display the window
		window.display();
	}
}