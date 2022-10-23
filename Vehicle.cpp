#include "Vehicle.h"

using namespace std;

// private

void Vehicle::update_position()
{
}

void Vehicle::update_gasLevel()
{

}

void Vehicle::expandRoute(vector<Point*> poins)
{

}

// public

Vehicle::Vehicle(int speed, int gasCapacity, int gasLevel, Point* position, Navigator* navigator)
{
    this->position = position;
    this->navigator = navigator;

    if (speed < 0 || gasCapacity < 0 || gasLevel < 0 || gasCapacity < gasLevel) return;

    this->speed = speed;
    this->gasCapacity = gasCapacity;
    this->gasLevel = gasLevel;
}

void Vehicle::setAppointment(Point* point)
{

}

void Vehicle::addAppointment(Point* point) 
{

}

void Vehicle::setSpeed(int speed) 
{
    if (speed < 0) speed = 0;

    this->speed = speed;
}

void Vehicle::refuel() {gasLevel = gasCapacity;}

void Vehicle::update()
{

}

Point* Vehicle::getAppointment() 
{
    if (appointments.empty()) return nullptr;
    return appointments.front();
}