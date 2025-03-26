#include <vector>
#include <queue>
#include <cassert>
#include <iostream>

using namespace std;

void bfs(int row, int col, vector<vector<char>> &grid, vector<vector<bool>> &visited)
{
    int totalRows = grid.size();
    int totalCols = grid[0].size();
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = true;
    vector<pair<int, int>> paths = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    while (!q.empty())
    {
        auto [curRow, curCol] = q.front();
        q.pop();

        for (auto [offsetRow, offsetCol] : paths)
        {
            int dy = curRow + offsetRow;
            int dx = curCol + offsetCol;
            bool isInBounds = dy >= 0 && dy < totalRows && dx >= 0 && dx < totalCols;
            if (isInBounds && !visited[dy][dx] && grid[dy][dx] == 'L')
            {
                visited[dy][dx] = true;
                q.push({dy, dx});
            }
        }
    }
}

int islandCount(vector<vector<char>> grid)
{
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    int count = 0;
    for (int row = 0; row < grid.size(); row++)
    {
        for (int col = 0; col < grid[0].size(); col++)
        {
            if (!visited[row][col] && grid[row][col] == 'L')
            {
                bfs(row, col, grid, visited);
                count++;
            }
        }
    }
    return count;
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
        {'W', 'L', 'W', 'W', 'L'},
        {'L', 'L', 'W', 'W', 'W'},
        {'W', 'W', 'W', 'L', 'L'},
        {'W', 'W', 'W', 'W', 'W'},
        {'L', 'L', 'W', 'L', 'L'}};
    assert(islandCount(grid1) == 4);

    vector<vector<char>> grid2 = {
        {'L', 'L', 'L', 'W', 'W'},
        {'L', 'L', 'W', 'W', 'L'},
        {'W', 'W', 'W', 'L', 'L'},
        {'W', 'W', 'W', 'W', 'W'},
        {'L', 'W', 'L', 'L', 'L'}};
    assert(islandCount(grid2) == 5);

    vector<vector<char>> grid3 = {
        {'W', 'W', 'W'},
        {'W', 'W', 'W'},
        {'W', 'W', 'W'}};
    assert(islandCount(grid3) == 0);

    vector<vector<char>> grid4 = {
        {'L', 'L', 'L'},
        {'L', 'L', 'L'},
        {'L', 'L', 'L'}};
    assert(islandCount(grid4) == 1);

    cout << "All tests passed!" << endl;
    return 0;
}
