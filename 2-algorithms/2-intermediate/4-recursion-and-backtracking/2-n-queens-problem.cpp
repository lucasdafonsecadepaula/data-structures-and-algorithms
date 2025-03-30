#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col, int n)
{
    for (int i = 0; i < row; i++)
        if (board[i][col] == 1)
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 1)
            return false;

    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 1)
            return false;

    return true;
}

bool solveNQueensUtil(vector<vector<int>> &board, int row, int n, vector<vector<vector<int>>> &solutions)
{
    if (row == n)
    {
        solutions.push_back(board);
        return true;
    }

    bool res = false;
    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 1;
            res = solveNQueensUtil(board, row + 1, n, solutions) || res;
            board[row][col] = 0;
        }
    }
    return res;
}

vector<vector<vector<int>>> solveNQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<vector<int>>> solutions;
    solveNQueensUtil(board, 0, n, solutions);
    return solutions;
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
