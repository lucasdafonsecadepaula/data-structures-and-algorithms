#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// Function to perform Prime Factorization
vector<pair<int, int>> primeFactorization(int n)
{
    vector<pair<int, int>> factors;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int count = 0;
            while (n % i == 0)
            {
                n /= i;
                count++;
            }
            factors.push_back({i, count});
        }
    }
    if (n > 1)
    {
        factors.push_back({n, 1});
    }
    return factors;
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
