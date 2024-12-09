#include "SimulationEngine.h"
#include <iostream>
#include <algorithm>

SimulationEngine::SimulationEngine() : currentTime(0) {}

void SimulationEngine::addStation(Station* station) {
    stations.push_back(station);
    std::cout << "Station added: " << station->getName() << std::endl;
}

void SimulationEngine::addBus(const Bus& bus) {
    fleet.addBus(bus);
    std::cout << "Bus added to fleet: " << bus.getId() << std::endl;
}

void SimulationEngine::advanceTime(int minutes) {
    currentTime += minutes;
    std::cout << "Simulation time advanced by " << minutes << " minutes. Current time: " << currentTime << std::endl;

    for (auto* station : stations) {
        station->update(currentTime);
    }

    if (currentTime % 30 == 0) {
        Bus* bus1 = fleet.getBusById(101);
        Bus* bus2 = fleet.getBusById(102);

        if (bus1 && bus2) {
            for (auto* station : stations) {
                station->removeBus(bus1->getId());
                station->removeBus(bus2->getId());
            }

            int newRoute1 = (bus1->getRouteNumber() == 5) ? 10 : 5;
            int newRoute2 = (bus2->getRouteNumber() == 10) ? 5 : 10;
            bus1->setRouteNumber(newRoute1);
            bus2->setRouteNumber(newRoute2);

            std::cout << "Bus " << bus1->getId() << " switched to Route " << newRoute1 << "." << std::endl;
            std::cout << "Bus " << bus2->getId() << " switched to Route " << newRoute2 << "." << std::endl;

            stations[newRoute1 == 5 ? 0 : 1]->addBus(bus1);
            stations[newRoute2 == 10 ? 1 : 0]->addBus(bus2);
        }
    }
}

void SimulationEngine::runSimulation(int duration) {
    for (int t = 0; t < duration; t += 10) {
        advanceTime(10);
        displayStatus();
    }
}

void SimulationEngine::displayStatus() const {
    std::cout << "Simulation Status at time " << currentTime << ":" << std::endl;
    fleet.displayFleetStatus();

    for (const auto* station : stations) {
        station->displayStationStatus();
    }
}
