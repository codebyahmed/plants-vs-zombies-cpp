SRCDIR := src
OBJDIR := obj

compile: $(OBJDIR)/main.o $(OBJDIR)/Plant.o $(OBJDIR)/Sunflower.o $(OBJDIR)/Time.o $(OBJDIR)/Zombie.o $(OBJDIR)/SimpleZombie.o $(OBJDIR)/PeaShooter.o $(OBJDIR)/ZombieFactory.o $(OBJDIR)/PlantFactory.o $(OBJDIR)/Level.o $(OBJDIR)/BeginnersGarden.o $(OBJDIR)/FootballZombie.o $(OBJDIR)/FlyingZombie.o $(OBJDIR)/DancingZombie.o $(OBJDIR)/Repeater.o $(OBJDIR)/SnowPea.o $(OBJDIR)/Wallnut.o $(OBJDIR)/CherryBomb.o $(OBJDIR)/FumeShroom.o
	g++ $(OBJDIR)/main.o $(OBJDIR)/Plant.o $(OBJDIR)/Sunflower.o $(OBJDIR)/Time.o $(OBJDIR)/Zombie.o $(OBJDIR)/SimpleZombie.o $(OBJDIR)/PeaShooter.o $(OBJDIR)/ZombieFactory.o $(OBJDIR)/PlantFactory.o $(OBJDIR)/Level.o $(OBJDIR)/BeginnersGarden.o $(OBJDIR)/FootballZombie.o $(OBJDIR)/FlyingZombie.o $(OBJDIR)/DancingZombie.o $(OBJDIR)/Repeater.o $(OBJDIR)/SnowPea.o $(OBJDIR)/Wallnut.o $(OBJDIR)/CherryBomb.o $(OBJDIR)/FumeShroom.o -o app -lsfml-graphics -lsfml-window -lsfml-system

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp
	g++ -c $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/Plant.o: $(SRCDIR)/Plant.cpp
	g++ -c $(SRCDIR)/Plant.cpp -o $(OBJDIR)/Plant.o

$(OBJDIR)/Sunflower.o: $(SRCDIR)/Sunflower.cpp
	g++ -c $(SRCDIR)/Sunflower.cpp -o $(OBJDIR)/Sunflower.o

$(OBJDIR)/Time.o: $(SRCDIR)/Time.cpp
	g++ -c $(SRCDIR)/Time.cpp -o $(OBJDIR)/Time.o

$(OBJDIR)/Zombie.o: $(SRCDIR)/Zombie.cpp
	g++ -c $(SRCDIR)/Zombie.cpp -o $(OBJDIR)/Zombie.o

$(OBJDIR)/SimpleZombie.o: $(SRCDIR)/SimpleZombie.cpp
	g++ -c $(SRCDIR)/SimpleZombie.cpp -o $(OBJDIR)/SimpleZombie.o

$(OBJDIR)/PeaShooter.o: $(SRCDIR)/PeaShooter.cpp
	g++ -c $(SRCDIR)/PeaShooter.cpp -o $(OBJDIR)/PeaShooter.o

$(OBJDIR)/ZombieFactory.o: $(SRCDIR)/ZombieFactory.cpp
	g++ -c $(SRCDIR)/ZombieFactory.cpp -o $(OBJDIR)/ZombieFactory.o

$(OBJDIR)/PlantFactory.o: $(SRCDIR)/PlantFactory.cpp
	g++ -c $(SRCDIR)/PlantFactory.cpp -o $(OBJDIR)/PlantFactory.o

$(OBJDIR)/Level.o: $(SRCDIR)/Level.cpp
	g++ -c $(SRCDIR)/Level.cpp -o $(OBJDIR)/Level.o

$(OBJDIR)/BeginnersGarden.o: $(SRCDIR)/BeginnersGarden.cpp
	g++ -c $(SRCDIR)/BeginnersGarden.cpp -o $(OBJDIR)/BeginnersGarden.o

$(OBJDIR)/FootballZombie.o: $(SRCDIR)/FootballZombie.cpp
	g++ -c $(SRCDIR)/FootballZombie.cpp -o $(OBJDIR)/FootballZombie.o

$(OBJDIR)/FlyingZombie.o: $(SRCDIR)/FlyingZombie.cpp
	g++ -c $(SRCDIR)/FlyingZombie.cpp -o $(OBJDIR)/FlyingZombie.o

$(OBJDIR)/DancingZombie.o: $(SRCDIR)/DancingZombie.cpp
	g++ -c $(SRCDIR)/DancingZombie.cpp -o $(OBJDIR)/DancingZombie.o

$(OBJDIR)/Repeater.o: $(SRCDIR)/Repeater.cpp
	g++ -c $(SRCDIR)/Repeater.cpp -o $(OBJDIR)/Repeater.o

$(OBJDIR)/SnowPea.o: $(SRCDIR)/SnowPea.cpp
	g++ -c $(SRCDIR)/SnowPea.cpp -o $(OBJDIR)/SnowPea.o

$(OBJDIR)/Wallnut.o: $(SRCDIR)/Wallnut.cpp
	g++ -c $(SRCDIR)/Wallnut.cpp -o $(OBJDIR)/Wallnut.o

$(OBJDIR)/CherryBomb.o: $(SRCDIR)/CherryBomb.cpp
	g++ -c $(SRCDIR)/CherryBomb.cpp -o $(OBJDIR)/CherryBomb.o

$(OBJDIR)/FumeShroom.o: $(SRCDIR)/FumeShroom.cpp
	g++ -c $(SRCDIR)/FumeShroom.cpp -o $(OBJDIR)/FumeShroom.o

run:
	./app
