SRCDIR := src
OBJDIR := obj

compile: $(SRCDIR)/main.cpp
	g++ -c $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o
	g++ $(OBJDIR)/main.o -o app -lsfml-graphics -lsfml-window -lsfml-system

run:
	./app