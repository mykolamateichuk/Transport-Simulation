#include "Vehicle.h"

using namespace std;

// private

// void Vehicle::update_position()
// {
// }

void Vehicle::update_gasLevel()
{
    gasLevel--;
    if (gasLevel <= 0)
    {
        gasLevel = 0;
        speed = 0;
    }
}

void Vehicle::expandRoute(vector<Point*> poins)
{
    for (int i = 0; i < poins.size(); i++)
        route.push(poins[i]);
}

// public

Vehicle::Vehicle(string number, int speed, int gasCapacity, int gasLevel, Point* position, Navigator* navigator)
{
    this->position = position;
    this->number = number;
    this->navigator = navigator;

    if (speed < 0 || gasCapacity < 0 || gasLevel < 0 || gasCapacity < gasLevel) return;

    this->speed = speed;
    this->gasCapacity = gasCapacity;
    this->gasLevel = gasLevel;
}

// void Vehicle::setAppointment(Point* point)
// {
// }

// void Vehicle::addAppointment(Point* point) 
// {
// }

void Vehicle::setSpeed(int speed) 
{
    if (speed < 0) speed = 0;

    this->speed = speed;
}

void Vehicle::refuel() {gasLevel = gasCapacity;}

void Vehicle::update()
{
    if (!canMove || speed <= 0 || gasLevel <= 0) return;

    update_gasLevel();
    // update_position();
}

Point* Vehicle::getAppointment() 
{
    if (appointments.empty()) return nullptr;
    return appointments.front();
}