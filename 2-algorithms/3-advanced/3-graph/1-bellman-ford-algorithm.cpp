//  (Shortest Path with Negative Weights - DP)
#include <iostream>
#include <vector>
#include <limits>
#include <cassert>
using namespace std;

vector<int> bellmanFord(vector<vector<pair<int, int>>> adjList, int src, bool &hasNegativeCycle)
{
    int V = adjList.size();
    vector<int> dist(V, numeric_limits<int>::max());
    dist[src] = 0;
    hasNegativeCycle = false;

    for (int i = 1; i < V; i++)
    {
        for (int u = 0; u < V; u++)
        {
            for (const auto &edge : adjList[u])
            {
                int v = edge.first, weight = edge.second;
                if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                }
            }
        }
    }

    for (int u = 0; u < V; u++)
    {
        for (const auto &edge : adjList[u])
        {
            int v = edge.first, weight = edge.second;
            if (dist[u] != numeric_limits<int>::max() && dist[u] + weight < dist[v])
            {
                hasNegativeCycle = true;
                return {};
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

void runBellmanFordTests()
{
    vector<vector<pair<int, int>>> graph1 = {
        {{1, 4}, {2, 1}},
        {{3, 1}},
        {{1, 2}, {3, 5}},
        {}};
    bool hasNegativeCycle;
    vector<int> result1 = bellmanFord(graph1, 0, hasNegativeCycle);
    assert(!hasNegativeCycle);
    assert(result1[0] == 0);
    assert(result1[1] == 3);
    assert(result1[2] == 1);
    assert(result1[3] == 4);

    vector<vector<pair<int, int>>> graph2 = {
        {{1, 1}},
        {{2, -1}},
        {{3, 2}},
        {}};
    vector<int> result2 = bellmanFord(graph2, 0, hasNegativeCycle);
    assert(!hasNegativeCycle);
    assert(result2[0] == 0);
    assert(result2[1] == 1);
    assert(result2[2] == 0);
    assert(result2[3] == 2);

    vector<vector<pair<int, int>>> graph3 = {
        {{1, 3}},
        {},
        {{3, 2}},
        {}};
    vector<int> result3 = bellmanFord(graph3, 0, hasNegativeCycle);
    assert(!hasNegativeCycle);
    assert(result3[0] == 0);
    assert(result3[1] == 3);
    assert(result3[2] == numeric_limits<int>::max());
    assert(result3[3] == numeric_limits<int>::max());

    vector<vector<pair<int, int>>> graph4 = {
        {{1, 1}},
        {{2, -1}},
        {{0, -2}},
        {}};
    bellmanFord(graph4, 0, hasNegativeCycle);
    assert(hasNegativeCycle);

    cout << "All tests passed successfully!\n";
}

int main()
{
    runBellmanFordTests();
    return 0;
}
