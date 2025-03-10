#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <iostream>
#include <fstream>
using namespace std;

class Scoreboard {
    
public:
    int hscore[3];
    string hname[3];
    int score;

    void readFromFile(string filename);
};

#endif // SCOREBOARD_H