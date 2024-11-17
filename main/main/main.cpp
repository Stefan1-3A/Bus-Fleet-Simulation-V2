#include "Bus.h"
#include "Station.h"
#include "FleetManagementSystem.h"

int main() {

    FleetManagementSystem fleetSystem;

    Bus bus1(101, 5, 50);
    Bus bus2(102, 10, 40);

    fleetSystem.addBus(bus1);
    fleetSystem.addBus(bus2);

    fleetSystem.displayFleetStatus();

    Station station1("Central Station");

    station1.addBus(&bus1);
    station1.displayStationStatus();

    bus1.startBus();
    bus1.boardPassengers(30);
    station1.removeBus(bus1.getId());
    bus1.displayBusStatus();

    return 0;
}
