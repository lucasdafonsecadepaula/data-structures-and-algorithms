#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <cassert>
#include <iostream>
using namespace std;

int connectedComponentsCount(unordered_map<int, vector<int>> graph)
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
        unordered_map<int, vector<int>> graph;
        assert(connectedComponentsCount(graph) == 0);
    }
    {
        unordered_map<int, vector<int>> graph = {{0, {}}};
        assert(connectedComponentsCount(graph) == 1);
    }
    {
        unordered_map<int, vector<int>> graph = {{0, {1}}, {1, {0}}};
        assert(connectedComponentsCount(graph) == 1);
    }
    {
        unordered_map<int, vector<int>> graph = {{0, {1}}, {1, {0}}, {2, {3}}, {3, {2}}};
        assert(connectedComponentsCount(graph) == 2);
    }
    {
        unordered_map<int, vector<int>> graph = {
            {0, {1, 2}},
            {1, {0}},
            {2, {0}},
            {3, {4}},
            {4, {3}},
            {5, {}}};
        assert(connectedComponentsCount(graph) == 3);
    }
    {
        unordered_map<int, vector<int>> graph = {{0, {1, 2, 3}}, {1, {0}}, {2, {0}}, {3, {0}}, {4, {5}}, {5, {4}}};
        assert(connectedComponentsCount(graph) == 2);
    }
    {
        unordered_map<int, vector<int>> graph = {{0, {1}}, {1, {0}}, {2, {3}}, {3, {2}}, {4, {5}}, {5, {4}}, {6, {}}};
        assert(connectedComponentsCount(graph) == 4);
    }
    {
        unordered_map<int, vector<int>> graph = {{0, {}}};
        assert(connectedComponentsCount(graph) == 1);
    }
}

int main()
{
    runTests();
    cout << "All tests passed successfully!\n";
    return 0;
}
