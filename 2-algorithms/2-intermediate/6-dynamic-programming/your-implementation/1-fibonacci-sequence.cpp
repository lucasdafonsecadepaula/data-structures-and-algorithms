#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// Bottom-Up Approach (Tabulation)
int fibonacciTabulation(int n)
{
}

// Top-Down Approach (Memoization)
int fibonacciMemoizationHelper(int n, vector<int> &dp)
{
}

int fibonacciMemoization(int n)
{
}

// Space Optimized Bottom-Up Approach
int fibonacciOptimized(int n)
{
}

// Recursive Approach (No DP)
int fibonacciRecursive(int n)
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