#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

bool hasPath(unordered_map<string, vector<string>> graph, string src, string dst)
{
    if (graph[src].size() == 0)
        return false;

    queue<string> q;
    unordered_set<string> visited;

    q.push(src);
    visited.insert(src);

    while (!q.empty())
    {
        string cur = q.front();
        q.pop();
        if (cur == dst)
            return true;

        for (string &n : graph[cur])
        {
            auto res = visited.insert(n);
            if (res.second)
                q.push(n);
        }
    }
    return false;
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
        unordered_map<string, vector<string>> graph;
        assert(hasPath(graph, "A", "B") == false);
    }
    {
        unordered_map<string, vector<string>> graph = {{"A", {}}};
        assert(hasPath(graph, "A", "A") == false);
    }
    {
        unordered_map<string, vector<string>> graph = {{"A", {"B"}}, {"B", {"C"}}, {"C", {}}};
        assert(hasPath(graph, "A", "C") == true);
    }
    {
        unordered_map<string, vector<string>> graph = {{"A", {"B"}}, {"B", {"A"}}};
        assert(hasPath(graph, "A", "C") == false);
    }
    {
        unordered_map<string, vector<string>> graph = {{"A", {"B", "C"}}, {"B", {"D"}}, {"C", {}}, {"D", {}}};
        assert(hasPath(graph, "A", "D") == true);
    }
    {
        unordered_map<string, vector<string>> graph = {
            {"A", {"B", "C", "D"}},
            {"B", {"E"}},
            {"C", {"F"}},
            {"D", {"G"}},
            {"E", {}},
            {"F", {}},
            {"G", {}}};
        assert(hasPath(graph, "A", "G") == true);
    }
    {
        unordered_map<string, vector<string>> graph = {
            {"A", {"B", "C"}},
            {"B", {"D"}},
            {"C", {"E"}},
            {"D", {}},
            {"E", {}}};
        assert(hasPath(graph, "A", "F") == false);
    }
    {
        unordered_map<string, vector<string>> graph = {
            {"A", {"B", "C"}},
            {"B", {"D", "E"}},
            {"C", {"F", "G"}},
            {"D", {}},
            {"E", {}},
            {"F", {}},
            {"G", {}}};
        assert(hasPath(graph, "A", "G") == true);
    }
    {
        unordered_map<string, vector<string>> graph = {
            {"A", {"B"}},
            {"B", {"C"}},
            {"C", {"D"}},
            {"D", {"E"}},
            {"E", {}}};
        assert(hasPath(graph, "A", "E") == true);
    }
    {
        unordered_map<string, vector<string>> graph = {
            {"A", {"B"}},
            {"B", {"C"}},
            {"C", {}}};
        assert(hasPath(graph, "C", "A") == false);
    }
}

int main()
{
    runTests();
    cout << "All tests passed successfully!\n";
    return 0;
}
