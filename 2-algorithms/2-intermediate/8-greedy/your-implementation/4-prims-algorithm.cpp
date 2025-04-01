#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

struct Edge
{
    int dest, weight;
};

struct Compare
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        return a.second > b.second;
    }
};

// Function to find the Minimum Spanning Tree using Prim's algorithm
int primMST(int n, vector<vector<Edge>> &adj)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    vector<bool> inMST(n, false);
    int totalWeight = 0, edgesUsed = 0;

    pq.push({0, 0}); // Start from node 0
    while (!pq.empty() && edgesUsed < n)
    {
        int u = pq.top().first, weight = pq.top().second;
        pq.pop();

        if (inMST[u])
            continue;

        inMST[u] = true;
        totalWeight += weight;
        edgesUsed++;

        for (const Edge &e : adj[u])
        {
            if (!inMST[e.dest])
            {
                pq.push({e.dest, e.weight});
            }
        }
    }
    return totalWeight;
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

void testPrimAlgorithm()
{
    vector<vector<Edge>> adj(5);
    adj[0] = {{1, 2}, {3, 6}};
    adj[1] = {{0, 2}, {2, 3}, {3, 8}, {4, 5}};
    adj[2] = {{1, 3}, {4, 7}};
    adj[3] = {{0, 6}, {1, 8}};
    adj[4] = {{1, 5}, {2, 7}};

    assert(primMST(5, adj) == 16); // Expected MST weight: 2 + 3 + 5 + 6 = 16
    cout << "All Prim's algorithm tests passed!" << endl;
}

int main()
{
    testPrimAlgorithm();
    return 0;
}
