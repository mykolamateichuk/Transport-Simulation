#include"navigator.h"
using namespace std;
void print(vector<int> road) {
    for (int i = 0; i <= road.size() - 1; i++) {
        cout << road[i] << " -> ";
    }
}
int main()
{
    vector<vector<int>> mas = { {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                       { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                       { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
                       { 0, 1, 1, 0, 1, 0, 0, 0, 0, 0},
                       { 0, 0, 0, 1, 0, 0, 1, 0, 0, 0},
                       { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                       { 0, 0, 0, 0, 1, 0, 0, 1, 1, 0},
                       { 0, 0, 0, 0, 0, 1, 1, 0, 0, 1},
                       { 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                       { 0, 0, 0, 0, 0, 0, 0, 1, 1, 0} };
    int start = 6;
    int finish = 0;
    Navigator navigator(mas);
    print(navigator.findroad(start, finish));
    cin.get(); cin.get();
    return 0;
}