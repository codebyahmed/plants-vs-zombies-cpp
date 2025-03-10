#include "Time.h"

GameTime::GameTime() : startTime(steady_clock::now()) {}

void GameTime::setStartTime(float time) {
    startTime = steady_clock::now() - duration_cast<steady_clock::duration>(duration<float>(time));
}

float GameTime::elapsedTime() const {
    auto currentTime = steady_clock::now();
    duration<float> elapsed = currentTime - startTime;
    return elapsed.count();
}

void GameTime::addTime(float time) {
    startTime += duration_cast<steady_clock::duration>(duration<float>(time));
}

void GameTime::reset() {
    startTime = steady_clock::now();
}
