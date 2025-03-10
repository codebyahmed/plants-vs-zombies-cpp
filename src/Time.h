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

    //Setter
    void setStartTime(float time);
    
    // Get the elapsed time since the start of the game
    float elapsedTime() const;

    // Add time to the start time
    void addTime(float time);
    
    // Reset the start time
    void reset();
};

#endif // TIME_H
