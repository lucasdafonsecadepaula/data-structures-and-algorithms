#include <iostream>
#include <cassert>
using namespace std;

// Function to perform Modular Exponentiation: (base^exp) % mod
long long modExpo(long long base, long long exp, long long mod)
{
    long long result = 1;
    base = base % mod;
    while (exp > 0)
    {
        if (exp % 2 == 1) // If exp is odd, multiply base with result
            result = (result * base) % mod;
        exp = exp >> 1; // Divide exp by 2
        base = (base * base) % mod;
    }
    return result;
}

// Function to calculate Modular Inverse using Fermat's Theorem (when mod is prime)
long long modInverse(long long a, long long mod)
{
    return modExpo(a, mod - 2, mod); // a^(mod-2) % mod (Fermat's theorem)
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
