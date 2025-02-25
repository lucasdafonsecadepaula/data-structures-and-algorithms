#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cassert>
using namespace std;

vector<pair<int, int>> aStar(vector<vector<int>> &grid, pair<int, int> start, pair<int, int> end)
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

void testAStar()
{
    {
        vector<vector<int>> grid = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}};
        pair<int, int> start = {0, 0};
        pair<int, int> end = {2, 2};

        vector<pair<int, int>> path = aStar(grid, start, end);
        vector<pair<int, int>> expected = {{0, 0}, {1, 0}, {1, 1}, {2, 1}, {2, 2}};
        assert(!path.empty());
        assert(path.front() == start);
        assert(path.back() == end);
    }

    {
        vector<vector<int>> grid = {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}};
        pair<int, int> start = {0, 0};
        pair<int, int> end = {2, 3};

        vector<pair<int, int>> path = aStar(grid, start, end);
        assert(!path.empty());
        assert(path.front() == start);
        assert(path.back() == end);
    }

    {
        vector<vector<int>> grid = {
            {0, 0, 0, 0},
            {1, 1, 1, 1},
            {0, 0, 0, 0}};
        pair<int, int> start = {0, 0};
        pair<int, int> end = {2, 3};

        vector<pair<int, int>> path = aStar(grid, start, end);
        assert(path.empty());
    }

    {
        vector<vector<int>> grid = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}};
        pair<int, int> start = {1, 1};
        pair<int, int> end = {1, 1};

        vector<pair<int, int>> path = aStar(grid, start, end);
        assert(path.size() == 1);
        assert(path.front() == start);
    }

    {
        vector<vector<int>> grid = {
            {0, 0, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}};
        pair<int, int> start = {0, 0};
        pair<int, int> end = {2, 3};

        vector<pair<int, int>> path = aStar(grid, start, end);
        assert(!path.empty());
        assert(path.front() == start);
        assert(path.back() == end);
    }

    cout << "All test cases passed!" << endl;
}

int main()
{
    testAStar();
    return 0;
}
