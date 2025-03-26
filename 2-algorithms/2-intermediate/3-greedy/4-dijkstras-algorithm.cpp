// (Shortest Path - Greedy)
#include <iostream>
#include <vector>
#include <limits>
#include <cassert>
#include <queue>
using namespace std;

vector<int> dijkstras(vector<vector<pair<int, int>>> adjList, int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    int V = adjList.size();
    vector<int> dist(V, numeric_limits<int>::max());
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (const auto &edge : adjList[u])
        {
            int v = edge.first, weight = edge.second;
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

void runDijkstrasTests()
{
    vector<vector<pair<int, int>>> adj1 = {
        {{1, 1}},
        {{0, 1}, {2, 2}},
        {{1, 2}}};
    vector<int> res1 = dijkstras(adj1, 0);
    assert(res1 == vector<int>({0, 1, 3}));

    vector<vector<pair<int, int>>> adj2 = {
        {{1, 4}, {2, 1}},
        {{0, 4}, {2, 2}, {3, 1}},
        {{0, 1}, {1, 2}, {3, 5}},
        {{1, 1}, {2, 5}}};
    vector<int> res2 = dijkstras(adj2, 0);
    assert(res2 == vector<int>({0, 3, 1, 4}));

    vector<vector<pair<int, int>>> adj3 = {
        {{1, 2}},
        {{0, 2}},
        {}};
    vector<int> res3 = dijkstras(adj3, 0);
    assert(res3 == vector<int>({0, 2, numeric_limits<int>::max()}));

    vector<vector<pair<int, int>>> adj4 = {
        {{1, 1}},
        {{2, 1}},
        {{3, 1}},
        {{0, 1}}};
    vector<int> res4 = dijkstras(adj4, 0);
    assert(res4 == vector<int>({0, 1, 2, 3}));

    vector<vector<pair<int, int>>> adj5 = {
        {{1, 0}},
        {{2, 0}},
        {{3, 0}},
        {{4, 0}},
        {{}}};
    vector<int> res5 = dijkstras(adj5, 0);
    assert(res5 == vector<int>({0, 0, 0, 0, 0}));

    vector<vector<pair<int, int>>> adj6 = {{}};
    vector<int> res6 = dijkstras(adj6, 0);
    assert(res6 == vector<int>({0}));

    cout << "All tests passed successfully!\n";
}

int main()
{
    runDijkstrasTests();
    return 0;
}
