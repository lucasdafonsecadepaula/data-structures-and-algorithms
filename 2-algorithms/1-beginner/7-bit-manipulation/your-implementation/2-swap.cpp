#include <iostream>
#include <cassert>
using namespace std;

// Function to swap two numbers using bitwise XOR
// ex: a = 9, b = 1
// bit representation a = 00001001, b = 00000001

// first operation -> a = 00001001 ^ 00000001 -> 00001000
// secon operation -> b = 00000001 ^ 00001000 -> 00001001
// third operation -> a = 00001000 ^ 00001001 -> 00000001

void swapNumbers(int &a, int &b)
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

void testSwapNumbers()
{
    int x = 5, y = 10;
    swapNumbers(x, y);
    assert(x == 10 && y == 5);

    int a = -3, b = 7;
    swapNumbers(a, b);
    assert(a == 7 && b == -3);

    int p = 42, q = 42;
    swapNumbers(p, q);
    assert(p == 42 && q == 42);

    cout << "All swap tests passed!" << endl;
}

int main()
{
    testSwapNumbers();
    return 0;
}