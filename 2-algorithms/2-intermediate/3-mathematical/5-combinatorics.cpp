#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// Function to compute nCr using Pascal's Triangle
long long binomialCoefficient(int n, int r)
{
    if (r > n)
        return 0;
    vector<vector<long long>> C(n + 1, vector<long long>(r + 1, 0));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, r); j++)
        {
            if (j == 0 || j == i)
                C[i][j] = 1;
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
    return C[n][r];
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

void testCombinatorics()
{
    assert(binomialCoefficient(5, 2) == 10);
    assert(binomialCoefficient(6, 3) == 20);
    assert(binomialCoefficient(7, 0) == 1);
    assert(binomialCoefficient(8, 8) == 1);
    assert(binomialCoefficient(10, 5) == 252);
    assert(binomialCoefficient(10, 2) == 45);
    cout << "All combinatorics tests passed!" << endl;
}

int main()
{
    testCombinatorics();
    return 0;
}