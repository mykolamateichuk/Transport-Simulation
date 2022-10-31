#include "Vehicle.h"

using namespace std;

// private

// void Vehicle::update_position(){}

void Vehicle::update_gasLevel()
{
    gasLevel--;
    
    if (gasLevel <= 0) {gasLevel = 0; speed = 0;}
}

void Vehicle::expandRoute(vector<int> poins)
{
    for (int i = 0; i < poins.size(); i++)
        route.push(poins[i]);
}

// public

Vehicle::Vehicle(string number, int speed, int gasCapacity, int gasLevel, int position, Navigator* navigator)
{
    this->position = position;
    this->number = number;
    this->navigator = navigator;

    if (speed < 0 || gasCapacity < 0 || gasLevel < 0 || gasCapacity < gasLevel) return;

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

    if(!route.empty()) expandRoute(navigator->findroad(route.back(), point));
    else expandRoute(navigator->findroad(position, point));
    
    route.push(point);
}

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