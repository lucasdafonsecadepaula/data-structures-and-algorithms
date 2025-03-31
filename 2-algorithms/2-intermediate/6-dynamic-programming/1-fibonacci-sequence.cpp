#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// Bottom-Up Approach (Tabulation)
int fibonacciTabulation(int n)
{
    if (n <= 1)
        return n;

    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

// Top-Down Approach (Memoization)
int fibonacciMemoizationHelper(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = fibonacciMemoizationHelper(n - 1, dp) + fibonacciMemoizationHelper(n - 2, dp);
}

int fibonacciMemoization(int n)
{
    vector<int> dp(n + 1, -1);
    return fibonacciMemoizationHelper(n, dp);
}

// Space Optimized Bottom-Up Approach
int fibonacciOptimized(int n)
{
    if (n <= 1)
        return n;

    int prev2 = 0, prev1 = 1, curr;
    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}

// Recursive Approach (No DP)
int fibonacciRecursive(int n)
{
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
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


void testFibonacci()
{
    assert(fibonacciTabulation(0) == 0);
    assert(fibonacciTabulation(1) == 1);
    assert(fibonacciTabulation(2) == 1);
    assert(fibonacciTabulation(3) == 2);
    assert(fibonacciTabulation(4) == 3);
    assert(fibonacciTabulation(5) == 5);
    assert(fibonacciTabulation(10) == 55);

    assert(fibonacciMemoization(10) == 55);
    assert(fibonacciOptimized(10) == 55);
    assert(fibonacciRecursive(10) == 55);
}

int main()
{
    testFibonacci();
    cout << "All tests passed!" << endl;
    return 0;
}