#include "Bus.h"
#include <iostream>

Bus::Bus(int busId, int route, int busCapacity)
    : id(busId), routeNumber(route), capacity(busCapacity), currentPassengers(0), location("station") {}

void Bus::startBus() {
    location = "on the road";
    std::cout << "Bus " << id << " has started its route on route " << routeNumber << "." << std::endl;
}

void Bus::stopBusAtStation() {
    location = "station";
    std::cout << "Bus " << id << " has stopped at a station." << std::endl;
}

void Bus::boardPassengers(int passengers) {
    int spaceAvailable = capacity - currentPassengers;
    if (spaceAvailable >= passengers) {
        currentPassengers += passengers;
        std::cout << passengers << " passengers boarded bus " << id << "." << std::endl;
    }
    else {
        currentPassengers += spaceAvailable;
        std::cout << spaceAvailable << " passengers boarded bus " << id << ". "
            << (passengers - spaceAvailable) << " passengers are waiting." << std::endl;
    }
}

void Bus::deboardPassengers(int passengers) {
    if (passengers <= currentPassengers) {
        currentPassengers -= passengers;
        std::cout << passengers << " passengers left bus " << id << "." << std::endl;
    }
    else {
        std::cout << "Only " << currentPassengers << " passengers on the bus." << std::endl;
    }
}

void Bus::setRouteNumber(int newRouteNumber) {
    this->routeNumber = newRouteNumber;
}

void Bus::displayBusStatus() const {
    std::cout << "Bus ID: " << id << std::endl;
    std::cout << "Route Number: " << routeNumber << std::endl;
    std::cout << "Capacity: " << capacity << std::endl;
    std::cout << "Current Passengers: " << currentPassengers << std::endl;
    std::cout << "Location: " << location << std::endl;
}

int Bus::getId() const { return id; }
int Bus::getRouteNumber() const { return routeNumber; }
int Bus::getCurrentPassengers() const { return currentPassengers; }
std::string Bus::getLocation() const { return location; }
