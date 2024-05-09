#ifndef TIME_H
#define TIME_H

#include <chrono>
using namespace std::chrono;

class Time {
private:
    time_point<steady_clock> startTime;

public:
    // Constructor
    Time();
    
    // Get the elapsed time since the start of the game
    float elapsedTime() const;
    
    // Reset the start time
    void reset();
};

#endif // TIME_H
