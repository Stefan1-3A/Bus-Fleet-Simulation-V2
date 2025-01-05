#ifndef STATION_H
#define STATION_H

#include "Bus.h"
#include <unordered_map>
#include <vector>

class Station {
private:
    std::string name;
    std::vector<Bus*> busesAtStation;
    std::unordered_map<std::string, int> passengerDestinationCounts;

public:
    Station(const std::string& stationName);

    void addBus(const Bus* bus);
    void removeBus(int busId);
    void displayStationStatus() const;
    void update(int currentTime);
    void addPassengers(const std::string& destination, int count);
    void removePassengers(const std::string& destination, int count);

    std::string getName() const;
    const std::vector<Bus*>& getBusesAtStation() const;
};

#endif
