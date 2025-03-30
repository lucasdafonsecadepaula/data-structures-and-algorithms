#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// Function to compute nCr using Pascal's Triangle
long long binomialCoefficient(int n, int r)
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