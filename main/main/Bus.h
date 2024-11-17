#ifndef BUS_H
#define BUS_H

#include <string>

class Bus {
private:
    int id, routeNumber, capacity, currentPassengers;
    std::string location;

public:
    Bus(int busId, int route, int busCapacity);
    void startBus();
    void stopBusAtStation();
    void boardPassengers(int passengers);
    void deboardPassengers(int passengers);
    void displayBusStatus() const;

    int getId() const;
    int getRouteNumber() const;
    int getCurrentPassengers() const;
    std::string getLocation() const;
};

#endif
