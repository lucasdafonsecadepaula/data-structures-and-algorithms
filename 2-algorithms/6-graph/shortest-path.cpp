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
    unordered_map<string, vector<string>> adjList;

    for (auto edge : edges)
    {
        adjList[get<0>(edge)].push_back(get<1>(edge));
        adjList[get<1>(edge)].push_back(get<0>(edge));
    }

    queue<pair<string, int>> q;
    unordered_set<string> s;
    q.push({nodeA, 0});

    while (!q.empty())
    {
        auto cur = q.front();
        q.pop();

        if (cur.first == nodeB)
            return cur.second;

        for (auto n : adjList[cur.first])
        {
            if (s.find(n) == s.end())
            {
                s.insert(n);
                q.push({n, cur.second + 1});
            }
        }
    }

    return -1;
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
