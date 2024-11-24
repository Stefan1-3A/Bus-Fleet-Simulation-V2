/*#include "Route.h"
#include "Station.h"
#include <iostream>

Route::Route(int routeNum, const std::vector<Station*>& stationList)
    : routeNumber(routeNum), stations(stationList), currentIndex(0) {}

int Route::getRouteNumber() const {
    return routeNumber;
}

Station* Route::getNextStation() {
    if (currentIndex < stations.size()) {
        return stations[currentIndex];
    }
    return nullptr;
}

bool Route::moveToNextStation() {
    if (currentIndex < stations.size() - 1) {
        ++currentIndex;
        return true;
    }
    return false;
}

void Route::displayRoute() const {
    std::cout << "Route " << routeNumber << " includes stations: ";
    for (const auto* station : stations) {
        std::cout << station->getName() << " ";
    }
    std::cout << std::endl;
}
*/