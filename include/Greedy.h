#ifndef GREEDY_H
#define GREEDY_H
#include <vector>
using namespace std;

class Greedy{

    public:

    Greedy();

    vector<int> Dijkstra(vector<vector<int>> cost, int n, int s);
};

#endif // GREEDY_H