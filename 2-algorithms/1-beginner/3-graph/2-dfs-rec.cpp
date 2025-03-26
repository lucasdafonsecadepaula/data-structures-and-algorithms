#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_set>
using namespace std;

bool dfsRecHelper(const vector<vector<int>> &adjList, int src, int dst, unordered_set<int> &set, vector<int> &path)
{
    if (adjList.empty())
        return false;
    auto res = set.insert(src);
    if (!res.second)
        return false;
    path.push_back(src);
    if (src == dst)
        return true;
    for (auto p : adjList[src])
    {
        if (dfsRecHelper(adjList, p, dst, set, path))
        {
            return true;
        }
    }
    return false;
}

bool dfsRec(const vector<vector<int>> &adjList, int src, int dst, vector<int> &path)
{
    unordered_set<int> set;
    return dfsRecHelper(adjList, src, dst, set, path);
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
        vector<vector<int>> graph;
        vector<int> path;
        assert(dfsRec(graph, 0, 0, path) == false);
        assert(path.empty());
    }

    {
        vector<vector<int>> graph = {{}};
        vector<int> path;
        assert(dfsRec(graph, 0, 0, path) == true);
        assert(path.size() == 1 && path[0] == 0);
    }

    {
        vector<vector<int>> graph = {{1}, {2}, {3}, {}};
        vector<int> path;
        vector<int> heuristc = {0, 1, 2, 3};
        bool result = dfsRec(graph, 0, 3, path);
        assert(result == true);
        assert(path == heuristc);
    }

    {
        vector<vector<int>> graph = {{1}, {0}, {3}, {2}};
        vector<int> path;
        assert(dfsRec(graph, 0, 2, path) == false);
    }

    {
        vector<vector<int>> graph = {{1, 2}, {0, 2}, {0, 1}};
        vector<int> path;
        vector<int> heuristc = {0, 1, 2};
        bool result = dfsRec(graph, 0, 2, path);
        assert(result == true);
        assert(path == heuristc);
    }

    {
        vector<vector<int>> graph = {{1, 2, 3}, {0}, {0}, {0}};
        vector<int> path;
        vector<int> heuristc = {0, 1, 2, 3};
        bool result = dfsRec(graph, 0, 3, path);
        assert(result == true);
        assert(path == heuristc);
    }

    {
        vector<vector<int>> graph = {{1}, {0}};
        vector<int> path;
        assert(dfsRec(graph, 0, 0, path) == true);
        assert(path.size() == 1 && path[0] == 0);
    }

    {
        vector<vector<int>> graph = {
            {1, 2, 3},
            {0, 2},
            {0, 1, 3, 4},
            {0, 2, 4},
            {2, 3, 5},
            {4}};
        vector<int> path;
        vector<int> heuristc = {0, 1, 2, 3, 4, 5};
        bool result = dfsRec(graph, 0, 5, path);
        assert(result == true);
        assert(path == heuristc);
    }
}

int main()
{
    runTests();
    cout << "All tests passed successfully!\n";
    return 0;
}