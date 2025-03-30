#include <iostream>
#include <cassert>
using namespace std;

// Function to perform Modular Exponentiation: (base^exp) % mod
long long modExpo(long long base, long long exp, long long mod)
{
}

// Function to calculate Modular Inverse using Fermat's Theorem (when mod is prime)
long long modInverse(long long a, long long mod)
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

void testModularArithmetic()
{
    assert(modExpo(2, 10, 1000) == 24); // 2^10 % 1000 = 1024 % 1000 = 24
    assert(modExpo(3, 7, 13) == 9);     // 3^7 % 13 = 2187 % 13 = 9
    assert(modInverse(3, 11) == 4);     // 3^-1 % 11 = 4 (since 3*4 % 11 = 1)
    assert(modInverse(10, 17) == 12);   // 10^-1 % 17 = 12 (since 10*12 % 17 = 1)
    cout << "All modular arithmetic tests passed!" << endl;
}

int main()
{
    testModularArithmetic();
    return 0;
}
