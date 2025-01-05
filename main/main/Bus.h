#ifndef BUS_H
#define BUS_H

class Route;
#include <string>
#include <vector>

struct Passenger {
    std::string destination;
};

class Bus {
private:
    int id, capacity, currentPassengers;
    Route* assignedRoute;
    std::string location;
    std::vector<Passenger> passengers;

public:
    Bus(int busId, int busCapacity);

    void startBus();
    void stopBusAtStation();
    void boardPassengers(int passengers, const std::string& destination);
    void deboardPassengers(const std::string& stationName);
    void displayBusStatus() const;

    void setRoute(Route* route);
    Route* getRoute() const;

    int getId() const;
    int getCurrentPassengers() const;
    int getCapacity() const;
    std::string getLocation() const;
};

#endif
