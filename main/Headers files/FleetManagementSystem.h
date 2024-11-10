#ifndef FLEETMANAGEMENTSYSTEM_H
#define FLEETMANAGEMENTSYSTEM_H

#include "Bus.h"
#include <vector>

class FleetManagementSystem {
private:
    std::vector<Bus> fleet;

public:
    void addBus(const Bus& bus);
    void removeBus(int busId);
    void displayFleetStatus();
};

#endif
