#ifndef NAVIGATOR_H
#define NAVIGATOR_H

//#include <iostream>
#include <queue>
#include <stack> 
#include <vector>

#include "Map.h"
#include "Point.h"

//using namespace std;

struct Edge {
    Point* begin;
    Point* end;
};

class Navigator {
private:
    Map map;
public:
    Navigator();
    Navigator(const Map&);
    Navigator(const Navigator&);

    //queue<Point*> findRoute(Point*, Point*);

    std::vector<int> findroad(int, int);
};

#endif