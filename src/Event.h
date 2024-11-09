#ifndef EVENT_H
#define EVENT_H

#include <chrono>

class Event {

public:
    Event(const std::chrono::time_point<std::chrono::system_clock>& beginTime, const std::chrono::minutes& duration);

    std::chrono::time_point<std::chrono::system_clock> getBeginTime() const;
    std::chrono::minutes getDuration() const;
    std::chrono::time_point<std::chrono::system_clock> getEndTime() const;

private:
    const std::chrono::time_point<std::chrono::system_clock> beginTime;
    const std::chrono::minutes duration;
    
};

#endif // EVENT_H