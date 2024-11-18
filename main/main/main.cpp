#include "Bus.h"
#include "Station.h"
#include "FleetManagementSystem.h"
#include "SimulationEngine.h"

int main() {
    SimulationEngine simulation;

    Station station1("Central Station");
    Station station2("East Station");

    simulation.addStation(&station1);
    simulation.addStation(&station2);

    Bus bus1(101, 5, 50);
    Bus bus2(102, 10, 40);

    simulation.addBus(bus1);
    simulation.addBus(bus2);

    station1.addBus(&bus1);
    station2.addBus(&bus2);

    simulation.runSimulation(60);

    return 0;
}
