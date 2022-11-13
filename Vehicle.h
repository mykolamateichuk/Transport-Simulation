#ifndef T_VEHICLE
#define T_VEHICLE

#include <queue>
#include <vector>
#include <iostream>
#include "navigator.cpp"

using namespace std;

class Vehicle
{
private:
    int position;

    string number = "CB0000AX";
    int speed = 40;
    bool canMove = true;

    int gasCapacity = 100;
    float gasLevel = 65;

    int removal = 0;
    queue<int> route;
    queue<int> appointments;

    Navigator *navigator;

    void update_position();
    void update_gasLevel();

    void expandRoute(vector<int> poins);

public:
    Vehicle(string number, int speed, int gasCapacity, int gasLevel, int position, Navigator *navigator);

    void setAppointment(int point);
    void addAppointment(int point);

    void setSpeed(int speed);

    void refuel();

    void update();

    int getPosition() { return position; }
    int getAppointment()
    {
        if (appointments.empty())
            return -1;
        return appointments.front();
    }
    queue<int> getRoute() { return route; }

    int getSpeed() { return speed; }
    string getNumber() { return number; }

    int getGasLevel() { return gasLevel; }
    int getGasCapacity() { return gasCapacity; }
};

#endif