#include "Vehicle.h"

using namespace std;

// private

/*void Vehicle::update_position()
{
    removal += speed;

    if (removal >= 1000)
    {
        removal = 0;
        position = route.front();
        route.pop();
    }

    if (!appointments.empty() && appointments.front() == position)
        appointments.pop();
}*/
/*void Vehicle::update_gasLevel()
{
    gasLevel--;

    if (gasLevel <= 0)
    {
        gasLevel = 0;
        speed = 0;
    }
}*/

void Vehicle::expandRoute(std::vector<Point*> poins) {
    for (int i = 0; i < poins.size(); i++)
        route.push(poins[i]);
}

// public

Vehicle::Vehicle()
    : number(""), speed(0), canMove(true), gasCapacity(15), gasLevel(1.0f)
{
    route.push(nullptr);
}

Vehicle::Vehicle
(std::string _number, unsigned int _speed, bool _canMove, unsigned int _gasCapacity, float _gasLevel, std::queue<Point*> _route)
    : number(_number),
      speed(_speed),
      canMove(_canMove),
      gasCapacity(_gasCapacity),
      gasLevel(_gasLevel),
      route(_route)
{}

Vehicle::Vehicle(const Vehicle& _vehicle)
    : number(_vehicle.number),
      speed(_vehicle.speed),
      canMove(_vehicle.canMove),
      gasCapacity(_vehicle.gasCapacity),
      gasLevel(_vehicle.gasLevel),
      route(_vehicle.route)
{}

/*void Vehicle::setAppointment(int point)
{
    appointments = queue<int>();
    route = queue<int>();

    expandRoute(navigator->findroad(position, point));
    route.push(point);
}

void Vehicle::addAppointment(int point)
{
    appointments.push(point);

    if (!route.empty())
        expandRoute(navigator->findroad(route.back(), point));
    else
        expandRoute(navigator->findroad(position, point));

    route.push(point);
}/**/

void Vehicle::setSpeed(int speed)
{
    if (speed < 0)
        speed = 0;

    this->speed = speed;
}

void Vehicle::refuel() { gasLevel = gasCapacity; }

/*
void Vehicle::update()
{
    if (!canMove || speed <= 0 || gasLevel <= 0)
        return;

    if (route.empty())
    {
        return;
    }

    update_gasLevel();
    update_position();
}
*/

// get
//int Vehicle::getPosition() { return position; }

/*int Vehicle::getAppointment()
{
    if (appointments.empty())
        return -1;

    return appointments.front();
}*/

std::queue<Point*> Vehicle::getRoute() { return route; }

int Vehicle::getSpeed() { return speed; }
string Vehicle::getNumber() { return number; }

int Vehicle::getGasLevel() { return gasLevel; }
int Vehicle::getGasCapacity() { return gasCapacity; }

// set
void Vehicle::setNumber(string number) { this->number = number; }
//void Vehicle::setSpeed(int speed) { this->speed = speed >= 0 ? speed : 0; }
void Vehicle::setGasLevel(int gasLevel) { this->gasLevel = gasLevel <= gasCapacity ? gasLevel : gasCapacity; }
void Vehicle::setGasCapacity(int gasCapacity) { this->gasCapacity = gasCapacity > gasLevel ? gasCapacity : gasLevel; }