#include <iostream>
#include <cassert>
using namespace std;

int gcd(int a, int b)
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

void testGCD()
{
    assert(gcd(48, 18) == 6);
    assert(gcd(101, 103) == 1);
    assert(gcd(56, 98) == 14);
    assert(gcd(0, 5) == 5);
    assert(gcd(7, 0) == 7);
    assert(gcd(0, 0) == 0);
    assert(gcd(-48, -18) == 6);
    assert(gcd(-48, 18) == 6);

    cout << "All GCD tests passed!" << endl;
}

int main()
{
    testGCD();
    return 0;
}
