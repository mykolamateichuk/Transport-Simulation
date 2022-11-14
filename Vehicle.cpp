#include "Vehicle.h"

using namespace std;

// private

void Vehicle::update_position()
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
}

void Vehicle::update_gasLevel()
{
    gasLevel--;

    if (gasLevel <= 0)
    {
        gasLevel = 0;
        speed = 0;
    }
}

void Vehicle::expandRoute(vector<int> poins)
{
    for (int i = 0; i < poins.size(); i++)
        route.push(poins[i]);
}

// public

Vehicle::Vehicle(string number, int speed, int gasCapacity, int gasLevel, int position, Navigator *navigator)
{
    this->removal = 0;
    this->canMove = true;
    this->number = number;
    this->position = position;
    this->navigator = navigator;

    if (speed < 0 || gasCapacity < 0 || gasLevel < 0 || gasCapacity < gasLevel)
    {
        this->speed = 40;
        this->gasCapacity = 100;
        this->gasLevel = this->gasCapacity;
        return;
    }

    this->speed = speed;
    this->gasCapacity = gasCapacity;
    this->gasLevel = gasLevel;
}

void Vehicle::setAppointment(int point)
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
}

void Vehicle::setSpeed(int speed)
{
    if (speed < 0)
        speed = 0;

    this->speed = speed;
}

void Vehicle::refuel() { gasLevel = gasCapacity; }

void Vehicle::update()
{
    if (!canMove || speed <= 0 || gasLevel <= 0)
        return;

    if (route.empty())
    {
        removal = 0;
        return;
    }

    update_gasLevel();
    update_position();
}

// get
int Vehicle::getPosition() { return position; }

int Vehicle::getAppointment()
{
    if (appointments.empty())
        return -1;

    return appointments.front();
}

queue<int> Vehicle::getRoute() { return route; }

int Vehicle::getSpeed() { return speed; }
string Vehicle::getNumber() { return number; }

int Vehicle::getGasLevel() { return gasLevel; }
int Vehicle::getGasCapacity() { return gasCapacity; }

// set
void Vehicle::setNumber(string number) { this->number = number; }
void Vehicle::setSpeed(int speed) { this->speed = speed >= 0 ? speed : 0; }
void Vehicle::setGasLevel(int gasLevel) { this->gasLevel = gasLevel <= gasCapacity ? gasLevel : gasCapacity; }
void Vehicle::setGasCapacity(int gasCapacity) { this->gasCapacity = gasCapacity > gasLevel ? gasCapacity : gasLevel; }