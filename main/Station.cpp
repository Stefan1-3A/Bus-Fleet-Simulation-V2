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
            std::cout << "Bus " << busId << " has left " << name << " station." << std::endl;
            busesAtStation.erase(it);
            break;
        }
    }
}

void Station::displayStationStatus() {
    std::cout << "Station " << name << " currently has the following buses:" << std::endl;
    for (auto bus : busesAtStation) {
        bus->displayBusStatus();
    }
}
