#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

#define N 4

bool isSafe(vector<vector<int>> &maze, int x, int y, vector<vector<int>> &sol)
{
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && sol[x][y] == 0);
}

bool solveMazeUtil(vector<vector<int>> &maze, int x, int y, vector<vector<int>> &sol)
{
    if (x == N - 1 && y == N - 1 && maze[x][y] == 1)
    {
        sol[x][y] = 1;
        return true;
    }

    if (isSafe(maze, x, y, sol))
    {
        sol[x][y] = 1;
        if (solveMazeUtil(maze, x + 1, y, sol))
            return true;
        if (solveMazeUtil(maze, x, y + 1, sol))
            return true;
        sol[x][y] = 0;
    }
    return false;
}

vector<vector<int>> solveMaze(vector<vector<int>> &maze)
{
    vector<vector<int>> sol(N, vector<int>(N, 0));
    if (solveMazeUtil(maze, 0, 0, sol))
        return sol;
    return {};
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
