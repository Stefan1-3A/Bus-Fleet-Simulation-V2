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
            return;
        }
    }
    std::cout << "Bus with ID " << busId << " not found." << std::endl;
}

void FleetManagementSystem::displayFleetStatus() const {
    if (fleet.empty()) {
        std::cout << "Fleet is empty." << std::endl;
        return;
    }
    std::cout << "Fleet Status:" << std::endl;
    for (const auto& bus : fleet) {
        bus.displayBusStatus();
    }
}

Bus* FleetManagementSystem::getBusById(int busId) {
    for (auto& bus : fleet) {
        if (bus.getId() == busId) {
            return &bus;
        }
    }
    return nullptr;
}
