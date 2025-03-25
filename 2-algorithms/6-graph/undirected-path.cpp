#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <string>
#include <cassert>
#include <iostream>
using namespace std;

bool findRec(string &src, string &dst, unordered_map<string, vector<string>> &adjList, unordered_set<string> s)
{
    auto res = s.insert(src);
    if (!res.second)
        return false;

    if (src == dst)
        return true;

    for (auto &n : adjList[src])
    {
        if (findRec(n, dst, adjList, s))
        {
            return true;
        }
    }

    return false;
}

bool undirectedPath(vector<tuple<string, string>> edges, string src, string dst)
{
    unordered_map<string, vector<string>> adjList;

    for (auto &edge : edges)
    {
        adjList[get<0>(edge)].push_back(get<1>(edge));
        adjList[get<1>(edge)].push_back(get<0>(edge));
    }

    unordered_set<string> s;

    return findRec(src, dst, adjList, s);
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
        assert(undirectedPath(edges, "A", "B") == false);
    }
    {
        vector<tuple<string, string>> edges = {{"A", "B"}, {"B", "C"}, {"C", "D"}};
        assert(undirectedPath(edges, "A", "D") == true);
    }
    {
        vector<tuple<string, string>> edges = {{"A", "B"}, {"C", "D"}};
        assert(undirectedPath(edges, "A", "D") == false);
    }
    {
        vector<tuple<string, string>> edges = {{"A", "B"}, {"B", "C"}, {"C", "A"}};
        assert(undirectedPath(edges, "A", "C") == true);
    }
    {
        vector<tuple<string, string>> edges = {{"A", "B"}, {"B", "C"}, {"C", "D"}, {"E", "F"}};
        assert(undirectedPath(edges, "A", "F") == false);
    }
    {
        vector<tuple<string, string>> edges = {{"A", "B"}, {"B", "C"}, {"C", "D"}, {"D", "A"}};
        assert(undirectedPath(edges, "A", "D") == true);
    }
    {
        vector<tuple<string, string>> edges = {
            {"A", "B"},
            {"B", "C"},
            {"C", "D"},
            {"D", "E"},
            {"E", "F"},
            {"F", "G"}};
        assert(undirectedPath(edges, "A", "G") == true);
    }
    {
        vector<tuple<string, string>> edges = {
            {"A", "B"},
            {"B", "C"},
            {"C", "D"},
            {"E", "F"},
            {"F", "G"}};
        assert(undirectedPath(edges, "A", "G") == false);
    }
}

int main()
{
    runTests();
    cout << "All tests passed successfully!\n";
    return 0;
}
