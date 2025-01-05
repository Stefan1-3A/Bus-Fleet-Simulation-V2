#include "SimulationEngine.h"
#include <iostream>
#include <algorithm>
#include <unordered_map>

SimulationEngine::SimulationEngine() : currentTime(0) {}

SimulationEngine::~SimulationEngine() {
    for (auto* route : routes) {
        delete route;
    }
}

void SimulationEngine::addStation(Station* station) {
    stations.push_back(station);
    std::cout << "Station added: " << station->getName() << std::endl;
}

void SimulationEngine::addBus(const Bus& bus) {
    fleet.addBus(bus);
    std::cout << "Bus added to fleet: " << bus.getId() << std::endl;
}

void SimulationEngine::addRoute(Route* route) {
    routes.push_back(route);
    std::cout << "Route added: " << route->getName() << std::endl;
}

Route* SimulationEngine::getRouteById(int routeId) {
    for (auto* route : routes) {
        if (route->getId() == routeId) {
            return route;
        }
    }
    return nullptr;
}

void SimulationEngine::advanceTime(int minutes) {
    currentTime += minutes;
    std::cout << "Simulation time advanced by " << minutes << " minutes. Current time: " << currentTime << "\n";

    static std::unordered_map<int, size_t> busStopIndex;

    for (const auto& bus : fleet.getFleet()) {
        Route* route = bus.getRoute();
        if (route) {
            int busId = bus.getId();
            const auto& stops = route->getStops();

            size_t currentIndex = busStopIndex[busId];
            Station* currentStation = stops[currentIndex];
            currentStation->removeBus(busId);

            currentIndex = (currentIndex + 1) % stops.size();
            busStopIndex[busId] = currentIndex;

            Station* nextStation = stops[currentIndex];
            nextStation->addBus(&bus);

            std::cout << "Bus " << busId << " moved from " << currentStation->getName()
                << " to " << nextStation->getName() << ".\n";
        }
    }

    for (auto* station : stations) {
        station->update(currentTime);
    }
}

void SimulationEngine::runSimulation(int duration) {
    for (int t = 0; t < duration; t += 10) {
        advanceTime(10);
        displayStatus();

        std::cout << "\n";
        std::cout << "============================================================\n";
        system("pause");
        std::cout << "============================================================\n";
        std::cout << "\n";
    }
}

void SimulationEngine::displayStatus() const {
    std::cout << "Simulation Status at time " << currentTime << ":" << std::endl;
    fleet.displayFleetStatus();

    for (const auto* station : stations) {
        station->displayStationStatus();
    }

    std::cout << "\nRoutes in Simulation:" << std::endl;
    for (const auto* route : routes) {
        route->displayRoute();
    }
}
