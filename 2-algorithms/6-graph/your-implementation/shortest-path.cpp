#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <tuple>
#include <queue>
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

int shortestPath(vector<tuple<string, string>> edges, string nodeA, string nodeB)
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
        vector<tuple<string, string>> edges;
        assert(shortestPath(edges, "A", "B") == -1);
    }
    {
        vector<tuple<string, string>> edges = {{"A", "B"}};
        assert(shortestPath(edges, "A", "B") == 1);
    }
    {
        vector<tuple<string, string>> edges = {{"A", "B"}, {"B", "C"}, {"C", "D"}};
        assert(shortestPath(edges, "A", "D") == 3);
    }
    {
        vector<tuple<string, string>> edges = {{"A", "B"}, {"B", "C"}, {"C", "D"}, {"A", "D"}};
        assert(shortestPath(edges, "A", "D") == 1);
    }
    {
        vector<tuple<string, string>> edges = {{"X", "Y"}, {"Y", "Z"}, {"A", "B"}, {"B", "C"}, {"C", "D"}};
        assert(shortestPath(edges, "A", "Z") == -1);
    }
    {
        vector<tuple<string, string>> edges = {{"A", "B"}, {"B", "C"}, {"C", "D"}, {"D", "E"}, {"E", "F"}};
        assert(shortestPath(edges, "A", "F") == 5);
    }
    {
        vector<tuple<string, string>> edges = {{"A", "B"}, {"B", "C"}, {"C", "D"}, {"D", "E"}, {"E", "F"}, {"B", "D"}};
        assert(shortestPath(edges, "A", "F") == 3);
    }
    {
        vector<tuple<string, string>> edges = {{"A", "B"}, {"B", "C"}, {"C", "D"}, {"D", "E"}, {"E", "F"}, {"B", "D"}, {"C", "E"}};
        assert(shortestPath(edges, "A", "F") == 2);
    }
}

void run()
{
    runTests();
    cout << "All tests passed successfully!\n";
}
