#include <vector>
#include <queue>
#include <cassert>
#include <iostream>
using namespace std;

int minimumIsland(vector<vector<char>> grid)
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
