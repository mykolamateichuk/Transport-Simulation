#include "Navigator.h"

Navigator::Navigator()
    : map(Map()), numberOfNodes(0)
{}

Navigator::Navigator(const Map& _map)
    : map(_map), numberOfNodes(_map.getSize())
{}

Navigator::Navigator(const Navigator& _nav) 
    : map(_nav.map), numberOfNodes(_nav.numberOfNodes)
{}

Navigator& Navigator::setNumberOfNodes(unsigned int _numOfNodes) {
    numberOfNodes = _numOfNodes;
    return *this;
}

Navigator& Navigator::setMap(const Map& _map) {
    map = _map;
    numberOfNodes = _map.getSize();
    return *this;
}

std::vector<unsigned int> Navigator::findRoute(unsigned int start, unsigned int finish) {
    std::queue<unsigned int> queue;
    std::stack<Edge> edges;
    std::vector<unsigned int> road;

    std::vector<unsigned int> nodes(numberOfNodes, 0);

    queue.push(start - 1);
    while (!queue.empty()) {
        int curr_node = queue.front();
        Edge edge;
        queue.pop();

        nodes[curr_node] = 2;
        for (int j = 0; j < numberOfNodes; j++) {
            if (map.getMap()[curr_node][j] == 1 && nodes[j] == 0) {
                queue.push(j);
                nodes[j] = 1;

                edge.begin = curr_node;
                edge.end = j;
                edges.push(edge);

                if (curr_node == finish) break;
            }
        }
    }
    road.push_back(finish + 1);

    while (!edges.empty()) {
        Edge edge = edges.top();
        edges.pop();

        if (edge.end == finish) {
            finish = edge.begin;
            road.push_back(finish + 1);
        }
    }
    road.pop_back();

    std::reverse(road.begin(), road.end());
    return road;
}
