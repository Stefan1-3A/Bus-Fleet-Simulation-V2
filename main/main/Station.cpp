#include "Station.h"
#include <iostream>

Station::Station(const std::string& stationName) : name(stationName) {}

void Station::addBus(Bus* bus) {
    for (auto* existingBus : busesAtStation) {
        if (existingBus->getId() == bus->getId()) {
            std::cout << "Bus " << bus->getId() << " is already at " << name << " station." << std::endl;
            return;
        }
    }
    busesAtStation.push_back(bus);
    std::cout << "Bus " << bus->getId() << " has arrived at " << name << " station." << std::endl;
}

void Station::removeBus(int busId) {
    auto it = std::find_if(busesAtStation.begin(), busesAtStation.end(),
        [busId](const Bus* bus) { return bus->getId() == busId; });

    if (it != busesAtStation.end()) {
        busesAtStation.erase(it);
        std::cout << "Bus " << busId << " has left " << name << " station." << std::endl;
    }
    else {
        std::cout << "Bus " << busId << " not found at " << name << " station." << std::endl;
    }
}

void Station::update(int currentTime) {
    std::cout << "Updating station " << name << " at time " << currentTime << std::endl;
    for (auto* bus : busesAtStation) {
        if (bus->getLocation() == "station") {
            int passengersToBoard = 10;
            bus->boardPassengers(passengersToBoard);
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

const std::vector<Bus*>& Station::getBusesAtStation() const {
    return busesAtStation;
}
