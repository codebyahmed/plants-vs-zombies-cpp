#include "Time.h"

Time::Time() : startTime(steady_clock::now()) {}

float Time::elapsedTime() const {
    auto currentTime = steady_clock::now();
    duration<float> elapsed = currentTime - startTime;
    return elapsed.count();
}

void Time::reset() {
    startTime = steady_clock::now();
}
