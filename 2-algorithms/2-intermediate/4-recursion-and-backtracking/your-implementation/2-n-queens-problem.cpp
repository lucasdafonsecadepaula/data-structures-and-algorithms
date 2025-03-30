#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

vector<vector<vector<int>>> solveNQueens(int n)
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

void testNQueens()
{
    vector<vector<vector<int>>> solutions = solveNQueens(4);
    assert(solutions.size() == 2);
}

int main()
{
    testNQueens();
    cout << "All tests passed!" << endl;
    return 0;
}
