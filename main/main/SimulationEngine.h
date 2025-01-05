#ifndef SIMULATION_ENGINE_H
#define SIMULATION_ENGINE_H

#include "Route.h"
#include "Station.h"
#include "FleetManagementSystem.h"
#include <vector>

class SimulationEngine {
private:
    FleetManagementSystem fleet;
    std::vector<Station*> stations;
    std::vector<Route*> routes;
    int currentTime;

public:
    SimulationEngine();
    ~SimulationEngine();
    void addStation(Station* station);
    void addBus(const Bus& bus);
    void addRoute(Route* route);
    void advanceTime(int minutes);
    void runSimulation(int duration);
    void displayStatus() const;

    Route* getRouteById(int routeId);
};

#endif
