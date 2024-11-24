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

    Bus* bus = fleet.getBusById(101);
    if (bus) {
        stations[0]->removeBus(bus->getId());

        if (std::find_if(stations[1]->getBusesAtStation().begin(),
            stations[1]->getBusesAtStation().end(),
            [bus](const Bus* b) { return b->getId() == bus->getId(); }) == stations[1]->getBusesAtStation().end()) {
            stations[1]->addBus(bus);
        }

        bus->startBus();
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
