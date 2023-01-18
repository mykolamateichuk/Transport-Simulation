#include "Vehicle.h"

using namespace std;

// private

void Vehicle::update_currPoint() {
    if (route.empty()) return;

    currentPoint = route.front();
    std::reverse(route.begin(), route.end());
    route.pop_back();
    std::reverse(route.begin(), route.end());
}

void Vehicle::update_gasLevel(float _consumption) {
    if (gasLevel > 0.2) {
        gasLevel -= _consumption;
    }
    else {
        route.clear();
        route = navigator->findRoute(currentPoint, 2);
        gasLevel = _consumption * route.size();
    }
}

void Vehicle::expandRoute(std::vector<int> poins) {
    for (int i = 0; i < poins.size(); i++)
        route.push_back(poins[i]);
}

// public

Vehicle::Vehicle()
    : number(0), speed(50), canMove(true), gasCapacity(15), gasLevel(1.0f), currentPoint(1), navigator(new Navigator()), stopCount(0)
{}

Vehicle::Vehicle
(unsigned int _number, unsigned int _speed, bool _canMove, unsigned int _gasCapacity, float _gasLevel, std::vector<unsigned int> _route, Navigator* _nav, int _currPoint, unsigned int _stopCount)
    : number(_number),
      speed(_speed),
      canMove(_canMove),
      gasCapacity(_gasCapacity),
      gasLevel(_gasLevel),
      route(_route),
      navigator(_nav),
      currentPoint(_currPoint),
      stopCount(_stopCount)
{}

Vehicle::Vehicle(const Vehicle& _vehicle)
    : number(_vehicle.number),
      speed(_vehicle.speed),
      canMove(_vehicle.canMove),
      gasCapacity(_vehicle.gasCapacity),
      gasLevel(_vehicle.gasLevel),
      route(_vehicle.route),
      navigator(_vehicle.navigator),
      currentPoint(_vehicle.currentPoint),
      stopCount(_vehicle.stopCount)
{}

void Vehicle::setSpeed(int speed)
{
    if (speed < 0)
        speed = 0;

    this->speed = speed;
}

void Vehicle::update(float _consumption) {
    if (!canMove) return;

    if (route.empty()) {
        route = navigator->findRoute(currentPoint, rand() % 10);
    }

    update_currPoint();
    update_gasLevel(_consumption);
}

// get

std::vector<unsigned int> Vehicle::getRoute() { return route; }

int Vehicle::getSpeed() { return speed; }
unsigned int Vehicle::getNumber() { return number; }

float Vehicle::getGasLevel() { return gasLevel; }
int Vehicle::getGasCapacity() { return gasCapacity; }

// set
void Vehicle::setNumber(unsigned int _number) {
    number = _number;
}
void Vehicle::setGasLevel(float _gasLevel) { gasLevel = _gasLevel; }
void Vehicle::setGasCapacity(int _gasCapacity) { gasCapacity = _gasCapacity; }

void Vehicle::print() const {
    std::cout << "***********************\n";
    std::cout << "Number: " << number << "\n";
    std::cout << "Gas level: " << gasLevel << "\n\n";

    if (!route.empty()) {
        std::cout << "Destination point: " << route.back() << "\n";
    }
    else {
        std::cout << "Destination point: " << currentPoint << "\n";
    }
    std::cout << "Current point: " << currentPoint << "\n";
    std::cout << "***********************\n";
}

int Vehicle::getCurrentPoint() const {
    return currentPoint;
}

void Vehicle::setCurrentPoint(int _currPoint) {
    currentPoint = _currPoint;
}

void Vehicle::setRoute(std::vector<unsigned int> _route) {
    route = _route;
}

Navigator* Vehicle::getNavigator() const {
    return navigator;
}

void Vehicle::setNavigator(Navigator* _nav) {
    navigator = _nav;
}

bool Vehicle::getCanMove() const {
    return canMove;
}

void Vehicle::setCanMove(bool _canMove) {
    canMove = _canMove;
}

unsigned int Vehicle::getStopCount() const {
    return stopCount;
}

void Vehicle::setStopCount(unsigned int _stopCount) {
    stopCount = _stopCount;
}