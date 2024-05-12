#ifndef TIME_H
#define TIME_H

#include <chrono>
#include <iomanip>
using namespace std::chrono;

class GameTime {
private:
    time_point<steady_clock> startTime;

public:
    // Constructor
    GameTime();
    
    // Get the elapsed time since the start of the game
    float elapsedTime() const;
    
    // Reset the start time
    void reset();
};

#endif // TIME_H
