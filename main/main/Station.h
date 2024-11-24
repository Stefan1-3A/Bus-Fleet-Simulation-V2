#ifndef STATION_H
#define STATION_H

#include "Bus.h"
#include <vector>

class Station {
private:
    std::string name;
    std::vector<Bus*> busesAtStation;

public:
    Station(const std::string& stationName);

    void addBus(Bus* bus);
    void removeBus(int busId);
    void displayStationStatus() const;
    void update(int currentTime);
    std::string getName() const;
    const std::vector<Bus*>& getBusesAtStation() const;
};

#endif
