#ifndef T_VEHICLE
#define T_VEHICLE

#include <queue>
#include <vector>
#include <iostream>

#include "navigator.h"
#include "Point.h"

class Vehicle {
private:
    std::string number;
    unsigned int speed;
    bool canMove;

    unsigned int gasCapacity;
    float gasLevel;

    std::queue<Point*> route;
    std::queue<Point*> appointments;

    //Navigator *navigator;
    /*
    void update_position();
    void update_gasLevel();
    */
    void expandRoute(std::vector<Point*>);
public:
    Vehicle();
    Vehicle(std::string, unsigned int, bool, unsigned int, float, std::queue<Point*>);
    Vehicle(const Vehicle&);

    //void setAppointment(Point*);
    //void addAppointment(Point*);

    void refuel();

    //void update();

    // get
    //int getPosition();
    //int getAppointment();
    std::queue<Point*> getRoute();

    int getSpeed();
    std::string getNumber();

    int getGasLevel();
    int getGasCapacity();

    // set
    void setGasLevel(int);
    void setGasCapacity(int);

    void setSpeed(int);
    void setNumber(std::string);
};

class Bus : public Vehicle {
private:
    unsigned int maxNumberOfPassengers;
    unsigned int currNumberOfPassengers;

public:
    Bus();
    Bus(unsigned int, unsigned int, std::string, unsigned int, bool, unsigned int, float, std::queue<Point*>);
    Bus(const Bus&);

    unsigned int getMaxNumberOfPassengers() const;
    unsigned int getCurrNumberOfPassengers() const;

    Bus& setMaxNumberOfPassengers(unsigned int);
    Bus& setCurrNumberOfPassengers(unsigned int);
};

class Truck : public Vehicle {
private:
    float maxMassOfCargo;
    float currMassOfCargo;

public:
    Truck();
    Truck(float, float, std::string, unsigned int, bool, unsigned int, float, std::queue<Point*>);
    Truck(const Truck&);

    float getMaxMassOfCargo() const;
    float getCurrMassOfCargo() const;

    Truck& setMaxMassOfCargo(float);
    Truck& setCurrMassOfCargo(float);
};

class Bicycle : public Vehicle {
private:
    float chanceOfGoingOffRoad;

public:
    Bicycle();
    Bicycle(float, std::string, unsigned int, bool, unsigned int, float, std::queue<Point*>);
    Bicycle(const Bicycle&);

    float getChanceOfGoingOffRoad() const;

    Bicycle& setChanceOfGoingOffRoad(float);
};

#endif