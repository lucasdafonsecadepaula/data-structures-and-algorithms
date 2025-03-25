#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <cassert>
#include <iostream>
using namespace std;

int dfs(int node, unordered_map<int, vector<int>> &graph, unordered_set<int> &s)
{
    s.insert(node);
    int count = 1;

    for (auto &n : graph[node])
    {
        if (s.find(n) == s.end())
        {
            count += dfs(n, graph, s);
        }
    }

    return count;
}

int largestComponent(unordered_map<int, vector<int>> graph)
{
    unordered_set<int> s;
    int largestValue = 0;

    for (auto &[node, neib] : graph)
    {
        if (s.find(node) == s.end())
        {
            int count = dfs(node, graph, s);
            largestValue = std::max(largestValue, count);
        }
    }

    return largestValue;
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

void runTests()
{
    {
        unordered_map<int, vector<int>> graph;
        assert(largestComponent(graph) == 0);
    }
    {
        unordered_map<int, vector<int>> graph = {{0, {}}};
        assert(largestComponent(graph) == 1);
    }
    {
        unordered_map<int, vector<int>> graph = {{0, {1}}, {1, {0}}};
        assert(largestComponent(graph) == 2);
    }
    {
        unordered_map<int, vector<int>> graph = {{0, {1}}, {1, {0}}, {2, {3}}, {3, {2}}};
        assert(largestComponent(graph) == 2);
    }
    {
        unordered_map<int, vector<int>> graph = {
            {0, {1, 2}},
            {1, {0}},
            {2, {0}},
            {3, {4}},
            {4, {3}},
            {5, {}}};
        assert(largestComponent(graph) == 3);
    }
    {
        unordered_map<int, vector<int>> graph = {{0, {1, 2, 3}}, {1, {0}}, {2, {0}}, {3, {0}}, {4, {5}}, {5, {4}}};
        assert(largestComponent(graph) == 4);
    }
    {
        unordered_map<int, vector<int>> graph = {{0, {1}}, {1, {0}}, {2, {3}}, {3, {2}}, {4, {5}}, {5, {4}}, {6, {}}};
        assert(largestComponent(graph) == 2);
    }
    {
        unordered_map<int, vector<int>> graph = {{0, {}}};
        assert(largestComponent(graph) == 1);
    }
}

int main()
{
    runTests();
    cout << "All tests passed successfully!\n";
    return 0;
}
