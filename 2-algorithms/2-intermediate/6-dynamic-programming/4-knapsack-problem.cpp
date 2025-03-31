#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int knapsack(int W, const vector<int> &weights, const vector<int> &values)
{
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (weights[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
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
    assert(knapsack(50, {10, 20, 30}, {60, 100, 120}) == 220);
    assert(knapsack(10, {1, 2, 3, 8}, {10, 20, 30, 40}) == 40);
    assert(knapsack(5, {3, 2, 4}, {30, 20, 50}) == 50);
    assert(knapsack(0, {1, 2, 3}, {10, 20, 30}) == 0);
    assert(knapsack(7, {3, 4, 5}, {30, 40, 50}) == 70);

    cout << "All tests passed!" << endl;
    return 0;
}