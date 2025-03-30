#include <iostream>
#include <cassert>
using namespace std;

// Function to implement the Extended Euclidean Algorithm
// It finds gcd(a, b) and also finds x, y such that ax + by = gcd(a, b)
int extendedGCD(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
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

void testExtendedGCD()
{
    int x, y;
    assert(extendedGCD(30, 20, x, y) == 10);
    assert(extendedGCD(35, 15, x, y) == 5);
    assert(extendedGCD(101, 10, x, y) == 1);
    assert(extendedGCD(48, 18, x, y) == 6);
    cout << "All extended Euclidean algorithm tests passed!" << endl;
}

int main()
{
    testExtendedGCD();
    return 0;
}
