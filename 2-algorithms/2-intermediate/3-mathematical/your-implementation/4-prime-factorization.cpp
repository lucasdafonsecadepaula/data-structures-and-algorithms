#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// Function to perform Prime Factorization
vector<pair<int, int>> primeFactorization(int n)
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

void testNumberTheoryConcepts()
{
    vector<pair<int, int>> factors = primeFactorization(60);
    vector<pair<int, int>> testV = {{2, 2}, {3, 1}, {5, 1}};
    assert(factors == testV);

    cout << "All number theory tests passed!" << endl;
}

int main()
{
    testNumberTheoryConcepts();
    return 0;
}
