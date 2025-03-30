#include <vector>
#include <queue>
#include <cassert>
#include <iostream>

using namespace std;

int bfs(int row, int col, vector<vector<char>> &grid, vector<vector<bool>> &visited)
{
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = true;
    int count = 1;
    vector<pair<int, int>> paths = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();

        for (auto [offsetY, offsetX] : paths)
        {
            int dy = y + offsetY;
            int dx = x + offsetX;
            bool isInBounds = dy >= 0 && dy < grid.size() && dx >= 0 && dx < grid[0].size();
            if (isInBounds && !visited[dy][dx] && grid[dy][dx] == 'L')
            {
                visited[dy][dx] = true;
                q.push({dy, dx});
                count++;
            }
        }
    }

    return count;
}

int minimumIsland(vector<vector<char>> grid)
{
    int minimumIslandCount = 0;
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

    for (int row = 0; row < grid.size(); row++)
    {
        for (int col = 0; col < grid[0].size(); col++)
        {
            if (!visited[row][col] && grid[row][col] == 'L')
            {
                int count = bfs(row, col, grid, visited);
                if (minimumIslandCount == 0)
                {
                    minimumIslandCount = count;
                }
                else
                {
                    minimumIslandCount = min(minimumIslandCount, count);
                }
            }
        }
    }

    return minimumIslandCount;
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

int main()
{
    vector<vector<char>> grid1 = {
        {'W', 'L', 'W', 'W', 'W'},
        {'W', 'L', 'W', 'L', 'L'},
        {'W', 'W', 'W', 'L', 'L'},
        {'L', 'W', 'W', 'W', 'W'},
        {'L', 'L', 'W', 'W', 'W'}};
    assert(minimumIsland(grid1) == 1);

    vector<vector<char>> grid2 = {
        {'L', 'L', 'W', 'W', 'L'},
        {'L', 'L', 'W', 'W', 'L'},
        {'W', 'W', 'W', 'L', 'L'},
        {'W', 'W', 'W', 'L', 'L'},
        {'L', 'W', 'L', 'L', 'L'}};
    assert(minimumIsland(grid2) == 2);

    vector<vector<char>> grid3 = {
        {'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'W', 'W'}};
    assert(minimumIsland(grid3) == 0);

    cout << "All tests passed!" << endl;
    return 0;
}
