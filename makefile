SRCDIR := src
OBJDIR := obj

$(OBJDIR):
	mkdir -p $(OBJDIR)

compile: $(OBJDIR) $(OBJDIR)/main.o $(OBJDIR)/Plant.o $(OBJDIR)/Sunflower.o $(OBJDIR)/Time.o $(OBJDIR)/Zombie.o $(OBJDIR)/SimpleZombie.o $(OBJDIR)/PeaShooter.o $(OBJDIR)/ZombieFactory.o $(OBJDIR)/PlantFactory.o $(OBJDIR)/Level.o $(OBJDIR)/BeginnersGarden.o $(OBJDIR)/FootballZombie.o $(OBJDIR)/FlyingZombie.o $(OBJDIR)/DancingZombie.o $(OBJDIR)/Repeater.o $(OBJDIR)/SnowPea.o $(OBJDIR)/Wallnut.o $(OBJDIR)/CherryBomb.o $(OBJDIR)/FumeShroom.o $(OBJDIR)/Game.o $(OBJDIR)/ZombieOutskirts.o $(OBJDIR)/SunflowerFields.o
	g++ $(OBJDIR)/main.o $(OBJDIR)/Plant.o $(OBJDIR)/Sunflower.o $(OBJDIR)/Time.o $(OBJDIR)/Zombie.o $(OBJDIR)/SimpleZombie.o $(OBJDIR)/PeaShooter.o $(OBJDIR)/ZombieFactory.o $(OBJDIR)/PlantFactory.o $(OBJDIR)/Level.o $(OBJDIR)/BeginnersGarden.o $(OBJDIR)/FootballZombie.o $(OBJDIR)/FlyingZombie.o $(OBJDIR)/DancingZombie.o $(OBJDIR)/Repeater.o $(OBJDIR)/SnowPea.o $(OBJDIR)/Wallnut.o $(OBJDIR)/CherryBomb.o $(OBJDIR)/FumeShroom.o $(OBJDIR)/Game.o $(OBJDIR)/ZombieOutskirts.o $(OBJDIR)/SunflowerFields.o -o app -lsfml-system -lsfml-window -lsfml-graphics

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	g++ -c $< -o $@

run:
	./app

clean:
	rm -rf $(OBJDIR) app