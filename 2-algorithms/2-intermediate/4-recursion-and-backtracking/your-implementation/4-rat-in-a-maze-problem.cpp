#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

vector<vector<int>> solveMaze(vector<vector<int>> &maze)
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

void testRatInMaze()
{
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}};
    vector<vector<int>> solution = solveMaze(maze);
    assert(!solution.empty());
}

int main()
{
    testRatInMaze();
    cout << "All tests passed!" << endl;
    return 0;
}
