#ifndef T_VEHICLE
#define T_VEHICLE

#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class Point // -
{
private:
    int length;
    string name;

public:
    Point()
    {
        this->length = 500;
        this->name = "Unsigned";
    }
    
    Point(int length, string name)
    {
        this->length = length;
        this->name = name;
    }

    string getName() {return name;} 
    int getLength(Point* point) {return length;} // !
};


class Navigator // -
{
public:
    vector<Point*> findRoute(Point* begin, Point* end)
    {
        vector<Point*> route;

        for(int i = 0; i < 5; i++) route.push_back(new Point(800, "Point " + to_string(i)));
        route.push_back(end);

        return route;
    }
};


class Vehicle
{
private:
    Point* position;

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
    Vehicle(int speed, int gasCapacity, int gasLevel, Point* position, Navigator* navigator);
   
    void setAppointment(Point* point);
    void addAppointment(Point* point);

    void setSpeed(int speed); 

    void refuel();

    void update();
    
    Point* getAppointment(); 
    Point* getPosition() {return position;}

    int getSpeed() {return speed;}
    int getGasLevel() {return gasLevel;}
    int getGasCapacity() {return gasCapacity;}
};

#endif