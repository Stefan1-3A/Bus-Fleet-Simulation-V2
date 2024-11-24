/*#ifndef ROUTE_H
#define ROUTE_H

#include <vector>
#include <string>

class Station;

class Route {
private:
    int routeNumber;
    std::vector<Station*> stations;
    int currentIndex;

public:
    Route(int routeNum, const std::vector<Station*>& stationList);

    int getRouteNumber() const;
    Station* getNextStation();
    bool moveToNextStation();
    void displayRoute() const;
};

#endif
*/