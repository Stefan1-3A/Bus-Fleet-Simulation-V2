#include "FleetManagementSystem.h"
#include <iostream>

void FleetManagementSystem::addBus(const Bus& bus) {
    fleet.push_back(bus);
    std::cout << "Bus " << bus.getId() << " added to the fleet." << std::endl;
}

void FleetManagementSystem::removeBus(int busId) {
    for (auto it = fleet.begin(); it != fleet.end(); ++it) {
        if (it->getId() == busId) {
            std::cout << "Bus " << busId << " removed from the fleet." << std::endl;
            fleet.erase(it);
            break;
        }
    }
}

void FleetManagementSystem::displayFleetStatus() {
    std::cout << "Fleet Status:" << std::endl;
    for (const auto& bus : fleet) {
        bus.displayBusStatus();
    }
}
