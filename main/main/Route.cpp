#include "Route.h"
#include <iostream>
#include <algorithm>

Route::Route(int id, const std::string& routeName)
    : routeId(id), name(routeName) {
}

void Route::addStop(Station* station) {
    stops.push_back(station);
    std::cout << "Station " << station->getName() << " added to route " << name << "." << std::endl;
}

void Route::removeStop(const std::string& stationName) {
    auto it = std::remove_if(stops.begin(), stops.end(),
        [&](Station* station) { return station->getName() == stationName; });

    if (it != stops.end()) {
        stops.erase(it, stops.end());
        std::cout << "Station " << stationName << " removed from route " << name << "." << std::endl;
    }
    else {
        std::cout << "Station " << stationName << " not found on route " << name << "." << std::endl;
    }
}

void Route::displayRoute() const {
    std::cout << "Route " << routeId << " (" << name << ") has the following stops:\n";
    for (const auto* stop : stops) {
        std::cout << " - " << stop->getName() << "\n";
    }
}

int Route::getId() const {
    return routeId;
}

const std::string& Route::getName() const {
    return name;
}

const std::vector<Station*>& Route::getStops() const {
    return stops;
}
