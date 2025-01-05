#ifndef ROUTE_H
#define ROUTE_H

#include "Station.h"
#include <vector>
#include <string>

class Route {
private:
    int routeId;
    std::string name;
    std::vector<Station*> stops;

public:
    Route(int id, const std::string& routeName);

    void addStop(Station* station);
    void removeStop(const std::string& stationName);
    void displayRoute() const;

    int getId() const;
    const std::string& getName() const;
    const std::vector<Station*>& getStops() const;
};

#endif
