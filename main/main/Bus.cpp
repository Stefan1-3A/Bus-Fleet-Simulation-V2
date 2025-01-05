#include "Bus.h"
#include "Route.h"
#include <iostream>
#include <vector>

Bus::Bus(int busId, int busCapacity)
    : id(busId), capacity(busCapacity), currentPassengers(0), location("station"), assignedRoute(nullptr) {
}

void Bus::startBus() {
    location = "on the road";
    std::cout << "Bus " << id << " has started its route.\n";
}

void Bus::stopBusAtStation() {
    location = "station";
    std::cout << "Bus " << id << " has stopped at a station.\n";
}

void Bus::boardPassengers(int passengers, const std::string& destination) {
    int spaceAvailable = capacity - currentPassengers;
    int toBoard = (spaceAvailable >= passengers) ? passengers : spaceAvailable;

    for (int i = 0; i < toBoard; ++i) {
        this->passengers.push_back({ destination });
    }
    currentPassengers += toBoard;

    std::cout << toBoard << " passengers boarded bus " << id << " with destination " << destination << ".\n";
    if (passengers > toBoard) {
        std::cout << (passengers - toBoard) << " passengers are waiting.\n";
    }
}

void Bus::deboardPassengers(const std::string& stationName) {
    auto it = passengers.begin();
    int deboarded = 0;

    while (it != passengers.end()) {
        if (it->destination == stationName) {
            it = passengers.erase(it);
            currentPassengers--;
            deboarded++;
        }
        else {
            ++it;
        }
    }

    std::cout << deboarded << " passengers deboarded at " << stationName << ".\n";
}

void Bus::displayBusStatus() const {
    std::cout << "Bus ID: " << id << "\n";
    std::cout << "Capacity: " << capacity << "\n";
    std::cout << "Current Passengers: " << currentPassengers << "\n";
    std::cout << "Location: " << location << "\n";
    if (assignedRoute) {
        std::cout << "Assigned Route: " << assignedRoute->getName() << "\n";
    }
    else {
        std::cout << "No route assigned.\n";
    }
}

void Bus::setRoute(Route* route) {
    assignedRoute = route;
}

Route* Bus::getRoute() const {
    return assignedRoute;
}

int Bus::getCapacity() const {
    return capacity;
}

int Bus::getId() const { return id; }
int Bus::getCurrentPassengers() const { return currentPassengers; }
std::string Bus::getLocation() const { return location; }
