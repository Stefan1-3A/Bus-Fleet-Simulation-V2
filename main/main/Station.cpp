#include "Station.h"
#include "Route.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

Station::Station(const std::string& stationName) : name(stationName) {}

void Station::addBus(const Bus* bus) {
    for (auto* existingBus : busesAtStation) {
        if (existingBus->getId() == bus->getId()) {
            std::cout << "Bus " << bus->getId() << " is already at " << name << " station.\n";
            return;
        }
    }
    busesAtStation.push_back(const_cast<Bus*>(bus));
    std::cout << "Bus " << bus->getId() << " has arrived at " << name << " station.\n";
}

void Station::removeBus(int busId) {
    auto it = std::find_if(busesAtStation.begin(), busesAtStation.end(),
        [busId](const Bus* bus) { return bus->getId() == busId; });

    if (it != busesAtStation.end()) {
        busesAtStation.erase(it);
        std::cout << "\nBus " << busId << " has left " << name << " station." << std::endl;
    }
    else {
        std::cout << "Bus " << busId << " not found at " << name << " station." << std::endl;
    }
}

void Station::update(int currentTime) {
    std::cout << "\nUpdating station " << name << " at time " << currentTime << "\n";

    for (auto* bus : busesAtStation) {
        if (bus->getLocation() == "station") {
            bus->deboardPassengers(name);

            int arrivingPassengers = std::rand() % 20 + 5;
            std::cout << arrivingPassengers << " passengers arrived at " << name << ".\n";

            for (int i = 0; i < arrivingPassengers; ++i) {
                std::string randomDestination = "Unknown";
                const auto& stops = bus->getRoute()->getStops();

                if (!stops.empty()) {
                    randomDestination = stops[std::rand() % stops.size()]->getName();
                }

                addPassengers(randomDestination, 1);
            }

            Route* route = bus->getRoute();
            if (route) {
                const auto& stops = route->getStops();
                auto it = std::find_if(stops.begin(), stops.end(), [&](Station* station) {
                    return station->getName() == name;
                    });

                if (it != stops.end()) {
                    size_t nextStopIndex = (std::distance(stops.begin(), it) + 1) % stops.size();
                    std::string nextDestination = stops[nextStopIndex]->getName();
                    int passengersToBoard = std::min(bus->getCapacity() - bus->getCurrentPassengers(), passengerDestinationCounts[nextDestination]);
                    bus->boardPassengers(passengersToBoard, nextDestination);
                    removePassengers(nextDestination, passengersToBoard);
                }
            }
        }
    }

    std::cout << "Passenger status at " << name << ":\n";
    for (const auto& entry : passengerDestinationCounts) {
        std::cout << "  - " << entry.second << " passengers waiting for " << entry.first << ".\n";
    }
}

void Station::displayStationStatus() const {
    std::cout << "\nStation " << name << " has the following buses:" << std::endl;
    for (const auto* bus : busesAtStation) {
        bus->displayBusStatus();
    }
}

void Station::addPassengers(const std::string& destination, int count) {
    passengerDestinationCounts[destination] += count;
}

void Station::removePassengers(const std::string& destination, int count) {
    if (passengerDestinationCounts[destination] >= count) {
        passengerDestinationCounts[destination] -= count;
        if (passengerDestinationCounts[destination] == 0) {
            passengerDestinationCounts.erase(destination);
        }
    }
    else {
        passengerDestinationCounts.erase(destination);
    }
}

std::string Station::getName() const {
    return name;
}

const std::vector<Bus*>& Station::getBusesAtStation() const {
    return busesAtStation;
}
