#ifndef SIMULATION_ENGINE_H
#define SIMULATION_ENGINE_H

#include "Bus.h"
#include "Station.h"
#include "FleetManagementSystem.h"
#include <vector>

class SimulationEngine {
private:
    FleetManagementSystem fleet;
    std::vector<Station*> stations;
    int currentTime;

public:
    SimulationEngine();
    void addStation(Station* station);
    void addBus(const Bus& bus);
    void advanceTime(int minutes);
    void runSimulation(int duration);
    void displayStatus() const;
};

#endif
