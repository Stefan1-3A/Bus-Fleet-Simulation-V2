#include <iostream>
#include <string>

// using namespace std;

class Bus {
private:
    int id, routeNumber, capacity, currentPassengers;
    std::string location;

public:
    Bus(int busId, int route, int busCapacity) {
        id = busId;
        routeNumber = route;
        capacity = busCapacity;
        currentPassengers = 0;
        location = "station";
    }

    void startBus() {
        location = "on the road";
        std::cout << "Bus" << id << " has started its route on route " << routeNumber << "." << std::endl;
    }

    void stopBusAtStation() {
        location = "station";
        std::cout << "Bus" << id << " has stopped at a station." << std::endl;
    }

    void boardPassengers(int passengers) {
        if (currentPassengers + passengers <= capacity) {
            currentPassengers += passengers;
            std::cout << passengers << " passengers boarded bus " << id << "." << std::endl;
        }
        else {
           std::cout << "Not enough capacity to board " << passengers << " passengers." << std::endl;
        }
    }

    void deboardPassengers(int passengers) {
        if (passengers <= currentPassengers) {
            currentPassengers -= passengers;
            std::cout << passengers << "passengers left bus " << id << "." << std::endl;
        }
        else {
            std::cout << "Only" << currentPassengers << " passengers on the bus." << std::endl;
        }
    }

    void displayBusStatus() {
        std::cout << "Bus ID: " << id << std::endl;
        std::cout << "Route Number " << routeNumber << std::endl;
        std::cout << "Capacity: " << capacity << std::endl;
        std::cout << "Current Passengers: " << currentPassengers << std::endl;
        std::cout << "Location: " << location << std::endl;
    }

};

/*
// TEST

int main() {

    Bus bus1(101, 5, 50);

    bus1.displayBusStatus();

    bus1.startBus();
    bus1.displayBusStatus();

    bus1.boardPassengers(20);
    bus1.displayBusStatus();

    bus1.deboardPassengers(5);
    bus1.displayBusStatus();

    bus1.stopBusAtStation();
    bus1.displayBusStatus();

    return 0;
}
*/