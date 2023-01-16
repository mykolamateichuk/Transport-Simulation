#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <queue>
#include <stack> 
#include <vector>

#include "Map.h"
#include "Point.h"

using namespace std;

struct Edge {
    int begin;
    int end;
};

class Navigator {
private:
    Map map;
public:
    Navigator();
    Navigator(const Map&);
    Navigator(const Navigator&);

    std::vector<int> findroad(int, int);
};

#endif