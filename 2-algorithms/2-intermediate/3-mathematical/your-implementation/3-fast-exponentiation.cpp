// (Binary Exponentiation)
#include <iostream>
#include <cassert>
using namespace std;

// Function to perform Fast Exponentiation: base^exp
long long fastExpo(long long base, long long exp)
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

void testFastExponentiation()
{
    assert(fastExpo(2, 10) == 1024);
    assert(fastExpo(3, 5) == 243);
    assert(fastExpo(5, 3) == 125);
    assert(fastExpo(10, 0) == 1);
    assert(fastExpo(7, 2) == 49);
    cout << "All fast exponentiation tests passed!" << endl;
}

int main()
{
    testFastExponentiation();
    return 0;
}