#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

struct Edge
{
    int src, dest, weight;
};

struct DisjointSet
{
    vector<int> parent, rank;
    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int v)
    {
        if (parent[v] != v)
            parent[v] = find(parent[v]);
        return parent[v];
    }
    void unite(int u, int v)
    {
        int rootU = find(u), rootV = find(v);
        if (rootU != rootV)
        {
            if (rank[rootU] < rank[rootV])
                parent[rootU] = rootV;
            else if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else
            {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

// Comparator function to sort edges by weight
bool edgeCompare(const Edge &e1, const Edge &e2)
{
    return e1.weight < e2.weight;
}

// Function to find the Minimum Spanning Tree using Kruskal's algorithm
vector<Edge> kruskalMST(int n, vector<Edge> &edges)
{
    sort(edges.begin(), edges.end(), edgeCompare);
    DisjointSet ds(n);
    vector<Edge> mst;

    for (const Edge &edge : edges)
    {
        if (ds.find(edge.src) != ds.find(edge.dest))
        {
            mst.push_back(edge);
            ds.unite(edge.src, edge.dest);
        }
    }
    return mst;
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

void testKruskalAlgorithm()
{
    vector<Edge> edges = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};
    vector<Edge> mst = kruskalMST(4, edges);
    int totalWeight = 0;
    for (const Edge &e : mst)
        totalWeight += e.weight;
    assert(totalWeight == 19); // Expected MST weight: 4 + 5 + 10 = 19
    cout << "All Kruskal's algorithm tests passed!" << endl;
}

int main()
{
    testKruskalAlgorithm();
    return 0;
}
