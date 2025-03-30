#include <vector>
#include <queue>
#include <cassert>
#include <iostream>
using namespace std;

int islandCount(vector<vector<char>> grid)
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
