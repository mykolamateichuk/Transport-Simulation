#ifndef T_VEHICLE
#define T_VEHICLE

#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class Point // -
{
};


class Navigator // -
{
public:
    vector<Point*> findRoute(Point* begin, Point* end);
};


class Vehicle
{
private:
    Point* position;

    string number = "CB0000AX";
    int speed = 40;
    bool canMove = true;

    int gasCapacity = 100;
    float gasLevel = 65;

    int removal = 0;
    queue<Point*> route;
    queue<Point*> appointments;

    Navigator* navigator; // !

    void update_position();
    void update_gasLevel();

    void expandRoute(vector<Point*> poins);

public:
    Vehicle(string number,int speed, int gasCapacity, int gasLevel, Point* position, Navigator* navigator);
   
    void setAppointment(Point* point);
    void addAppointment(Point* point);

    void setSpeed(int speed); 

    void refuel();

    void update();
    
    Point* getAppointment(); 
    Point* getPosition() {return position;}

    int getSpeed() {return speed;}
    string getNumber() {return number;}
    int getGasLevel() {return gasLevel;}
    int getGasCapacity() {return gasCapacity;}
};

#endif