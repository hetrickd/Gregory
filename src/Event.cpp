#include "Event.h"

#include <stdexcept>

using namespace std::chrono;

Event::Event(const time_point<system_clock>& beginTime, const minutes& duration) : beginTime(beginTime), duration(duration) {
    if (duration.count() < 0) {
        throw std::invalid_argument("Duration cannot be negative.");
    }
}

time_point<system_clock> Event::getBeginTime() const {
    return beginTime;
}

time_point<system_clock> Event::getEndTime() const {
    return beginTime + duration;
}

minutes Event::getDuration() const {
    return duration;
}