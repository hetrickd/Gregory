#include <iostream>
#include <chrono>
#include <cassert>
#include "../src/Event.h"

void testEventCreation() {
    auto begin = std::chrono::system_clock::now();
    std::chrono::minutes duration(30);

    Event event(begin, duration);
    assert(event.getBeginTime() == begin);
    assert(event.getDuration() == duration);
    assert(event.getEndTime() == begin + duration);

    std::cout << "testEventCreation passed." << std::endl;
}

void testInvalidDuration() {
    try {
        auto begin = std::chrono::system_clock::now();
        std::chrono::minutes duration(-10); // Invalid duration

        Event event(begin, duration);
        assert(false); // Should not reach here
    } catch (const std::invalid_argument&) {
        std::cout << "testInvalidDuration passed." << std::endl;
    }
}

int main() {
    testEventCreation();
    testInvalidDuration();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}