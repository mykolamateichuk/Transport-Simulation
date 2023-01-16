#ifndef T_VEHICLE
#define T_VEHICLE

#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

#include "Navigator.h"
#include "Point.h"

class Vehicle {
protected:
    unsigned int number;
    unsigned int speed;
    bool canMove;

    unsigned int gasCapacity;
    float gasLevel;

    std::vector<int> route;
    Navigator* navigator;

    int currentPoint;
    unsigned int stopCount;
    
    void update_currPoint();
    void update_gasLevel(float);
    
    void expandRoute(std::vector<int>);
public:
    Vehicle();
    Vehicle(unsigned int, unsigned int, bool, unsigned int, float, std::vector<int>, Navigator*, int, unsigned int);
    Vehicle(const Vehicle&);

    //void refuel();

    void update(float);

    // get
    std::vector<int> getRoute();

    int getSpeed();
    unsigned int getNumber();

    float getGasLevel();
    int getGasCapacity();

    int getCurrentPoint() const;
    Navigator* getNavigator() const;
    bool getCanMove() const;
    unsigned int getStopCount() const;

    // set
    void setGasLevel(float);
    void setGasCapacity(int);

    void setRoute(std::vector<int>);

    void setSpeed(int);
    void setNumber(unsigned int);

    void setCurrentPoint(int);
    void setNavigator(Navigator*);
    void setCanMove(bool);
    void setStopCount(unsigned int);

    virtual void print() const;
};

class Bus : public Vehicle {
private:
    unsigned int maxNumberOfPassengers;
    unsigned int currNumberOfPassengers;

public:
    Bus();
    Bus(unsigned int, unsigned int, unsigned int, unsigned int, bool, unsigned int, float, std::vector<int>, Navigator*, int, unsigned int);
    Bus(const Bus&);

    unsigned int getMaxNumberOfPassengers() const;
    unsigned int getCurrNumberOfPassengers() const;

    Bus& setMaxNumberOfPassengers(unsigned int);
    Bus& setCurrNumberOfPassengers(unsigned int);

    void print() const override;

    void update(float);
};

class Truck : public Vehicle {
private:
    float maxMassOfCargo;
    float currMassOfCargo;

public:
    Truck();
    Truck(float, float, unsigned int, unsigned int, bool, unsigned int, float, std::vector<int>, Navigator*, int, unsigned int);
    Truck(const Truck&);

    float getMaxMassOfCargo() const;
    float getCurrMassOfCargo() const;

    Truck& setMaxMassOfCargo(float);
    Truck& setCurrMassOfCargo(float);

    void print() const override;
};

class Bicycle : public Vehicle {
private:
    float chanceOfGoingOffRoad;

    void update_currPoint();
public:
    Bicycle();
    Bicycle(float, unsigned int, unsigned int, bool, unsigned int, float, std::vector<int>, Navigator*, int, unsigned int);
    Bicycle(const Bicycle&);

    float getChanceOfGoingOffRoad() const;

    Bicycle& setChanceOfGoingOffRoad(float);

    void print() const override;

    void update();
};

#endif