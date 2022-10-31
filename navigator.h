#include <iostream>
#include <queue>
#include <stack> 
#include <vector>
using namespace std;
struct Edge {
    int begin;
    int end;
};
class Navigator {
private:
    vector<vector<int>> mas;
public:
    Navigator(vector<vector<int>> mas) {this->mas = mas;}
    vector<int> findroad(int start, int finish);
};