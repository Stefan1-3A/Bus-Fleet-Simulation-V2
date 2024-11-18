#include "SimulationEngine.h"
#include <iostream>


SimulationEngine::SimulationEngine() : currentTime(0) {}

void SimulationEngine::addStation(Station* station) {
    stations.push_back(*station);
    std::cout << "Station added: " << station->getName() << std::endl;
}


void SimulationEngine::addBus(const Bus& bus) {
    fleet.addBus(bus);
    std::cout << "Bus added to fleet: " << bus.getId() << std::endl;
}

void SimulationEngine::advanceTime(int minutes) {
    currentTime += minutes;
    std::cout << "Simulation time advanced by " << minutes << " minutes. Current time: " << currentTime << std::endl;

    for (auto& station : stations) {
        station.update(currentTime);
    }

    if (!stations.empty()) {
        stations[0].removeBus(101);
        stations[1].addBus(fleet.getBusById(101));
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

    for (const auto& station : stations) {
        station.displayStationStatus();
    }
}
