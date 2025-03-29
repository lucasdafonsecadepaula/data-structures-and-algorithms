#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <cassert>
using namespace std;

// This function should return true if there is path between src and dst
// and should insert the path of the nodes that it passed by;
bool dfs(vector<vector<int>> adjList, int src, int dst, vector<int> &path)
{
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
        assert(dfs(graph, 0, 0, path) == false);
        assert(path.empty());
    }

    {
        vector<vector<int>> graph = {{}};
        vector<int> path;
        assert(dfs(graph, 0, 0, path) == true);
        assert(path.size() == 1 && path[0] == 0);
    }

    {
        vector<vector<int>> graph = {{1}, {2}, {3}, {}};
        vector<int> path;
        vector<int> heuristc = {0, 1, 2, 3};
        bool result = dfs(graph, 0, 3, path);
        assert(result == true);
        assert(path == heuristc);
    }

    {
        vector<vector<int>> graph = {{1}, {0}, {3}, {2}};
        vector<int> path;
        assert(dfs(graph, 0, 2, path) == false);
    }

    {
        vector<vector<int>> graph = {{1, 2}, {0, 2}, {0, 1}};
        vector<int> path;
        vector<int> heuristc = {0, 2};
        bool result = dfs(graph, 0, 2, path);
        assert(result == true);
        assert(path == heuristc);
    }

    {
        vector<vector<int>> graph = {{1, 2, 3}, {0}, {0}, {0}};
        vector<int> path;
        vector<int> heuristc = {0, 3};
        bool result = dfs(graph, 0, 3, path);
        assert(result == true);
        assert(path == heuristc);
    }

    {
        vector<vector<int>> graph = {{1}, {0}};
        vector<int> path;
        assert(dfs(graph, 0, 0, path) == true);
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
        vector<int> heuristc = {0, 3, 4, 5};
        bool result = dfs(graph, 0, 5, path);
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