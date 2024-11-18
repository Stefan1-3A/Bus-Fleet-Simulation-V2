#include "Station.h"
#include <iostream>

Station::Station(const std::string& stationName) : name(stationName) {}

void Station::addBus(Bus* bus) {
    busesAtStation.push_back(bus);
    std::cout << "Bus " << bus->getId() << " has arrived at " << name << " station." << std::endl;
}

void Station::removeBus(int busId) {
    for (auto it = busesAtStation.begin(); it != busesAtStation.end(); ++it) {
        if ((*it)->getId() == busId) {
            busesAtStation.erase(it);
            std::cout << "Bus " << busId << " has left " << name << " station." << std::endl;
            break;
        }
    }
}

void Station::update(int currentTime) {
    std::cout << "Updating station " << name << " at time " << currentTime << std::endl;
    for (auto it = busesAtStation.begin(); it != busesAtStation.end(); ++it) {
        Bus* bus = *it;
        if (bus->getLocation() == "station") {
            std::cout << "Bus " << bus->getId() << " is leaving station " << name << "." << std::endl;
            bus->startBus();
        }
    }
}


void Station::displayStationStatus() const {
    std::cout << "Station " << name << " has the following buses:" << std::endl;
    for (const auto* bus : busesAtStation) {
        bus->displayBusStatus();
    }
}

std::string Station::getName() const {
    return name;
}
