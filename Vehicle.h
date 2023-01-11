#ifndef T_VEHICLE
#define T_VEHICLE

#include <queue>
#include <vector>
#include <iostream>
#include "navigator.h"

using namespace std;

class Vehicle
{
private:
    int position;

    string number;
    int speed;
    bool canMove;

    int gasCapacity;
    float gasLevel;

    int removal;
    queue<int> route;
    queue<int> appointments;

    Navigator *navigator;

    void update_position();
    void update_gasLevel();

    void expandRoute(vector<int>);

public:
    Vehicle(string, int, int, int, int, Navigator *);

    void setAppointment(int);
    void addAppointment(int);

    void refuel();

    void update();

    // get
    int getPosition();
    int getAppointment();
    queue<int> getRoute();

    int getSpeed();
    string getNumber();

    int getGasLevel();
    int getGasCapacity();

    // set
    void setGasLevel(int);
    void setGasCapacity(int);

    void setSpeed(int);
    void setNumber(string);
};

#endif