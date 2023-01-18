#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <queue>
#include <stack> 
#include <vector>

#include <algorithm>

#include "Map.h"

struct Edge {
    unsigned int begin;
    unsigned int end;
};

class Navigator {
private:
    Map map;
    unsigned int numberOfNodes;
public:
    Navigator();
    Navigator(const Map&);
    Navigator(const Navigator&);

    Navigator& setMap(const Map&);
    Navigator& setNumberOfNodes(unsigned int);

    std::vector<unsigned int> findRoute(unsigned int, unsigned int);
};

#endif