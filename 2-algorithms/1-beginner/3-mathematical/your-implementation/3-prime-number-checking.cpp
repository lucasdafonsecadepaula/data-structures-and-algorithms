#include <iostream>
#include <cassert>
using namespace std;

bool isPrime(int n)
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

void testPrime()
{
    assert(isPrime(2) == true);
    assert(isPrime(3) == true);
    assert(isPrime(4) == false);
    assert(isPrime(5) == true);
    assert(isPrime(10) == false);
    assert(isPrime(29) == true);
    assert(isPrime(1) == false);
    assert(isPrime(0) == false);
    assert(isPrime(-7) == false);

    cout << "All prime checking tests passed!" << endl;
}

int main()
{
    testPrime();
    return 0;
}
