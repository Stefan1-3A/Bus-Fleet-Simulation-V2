#include "Bus.h"
#include "Station.h"
#include "FleetManagementSystem.h"
#include "SimulationEngine.h"
#include "Route.h"
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    SimulationEngine simulation;

    Station station1("Central Station");
    Station station2("East Station");
    Station station3("West Station");

    simulation.addStation(&station1);
    simulation.addStation(&station2);
    simulation.addStation(&station3);

    Route* route1 = new Route(100, "Route 100");
    route1->addStop(&station1);
    route1->addStop(&station2);

    Route* route2 = new Route(101, "Route 101");
    route2->addStop(&station2);
    route2->addStop(&station3);

    simulation.addRoute(route1);
    simulation.addRoute(route2);

    Bus bus1(101, 50);
    Bus bus2(102, 40);

    bus1.setRoute(route1);
    bus2.setRoute(route2);

    simulation.addBus(bus1);
    simulation.addBus(bus2);

    station1.addBus(&bus1);

    station2.addBus(&bus2);

    simulation.runSimulation(60);

    return 0;
}
