#include "Navigator.h"

/*vector<int> Navigator::findroad(int start, int finish) {
    queue<int> Queue;
    stack<Edge> Edges;
    vector<int> road;
    Edge e;
    int nodes[10];
    for (int i = 0; i < 10; i++)
        nodes[i] = 0;
    Queue.push(start - 1);
    while (!Queue.empty())
    {
        int node = Queue.front();
        Queue.pop();
        nodes[node] = 2;
        for (int j = 0; j < 10; j++)
        {
            if (map[node][j] == 1 && nodes[j] == 0)
            {
                Queue.push(j);
                nodes[j] = 1;
                e.begin = node; e.end = j;
                Edges.push(e);
                if (node == finish) break;
            }
        }
    }
    road.push_back(finish + 1);
    while (!Edges.empty()) {
        e = Edges.top();
        Edges.pop();
        if (e.end == finish) {
            finish = e.begin;
            road.push_back(finish + 1);

        }
    }
    road.pop_back();
    vector<int> finalroad;
    for (int i = road.size() - 1; i >= 0; i--) {
        finalroad.push_back(road[i]);
    }
    return finalroad;
}/**/