#include "Time.h"

GameTime::GameTime() : startTime(steady_clock::now()) {}

float GameTime::elapsedTime() const {
    auto currentTime = steady_clock::now();
    duration<float> elapsed = currentTime - startTime;
    return elapsed.count();
}

void GameTime::reset() {
    startTime = steady_clock::now();
}
