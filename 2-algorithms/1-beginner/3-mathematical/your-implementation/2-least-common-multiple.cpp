#include <iostream>
#include <cassert>
using namespace std;

int lcm(int a, int b)
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

void testLCM()
{
    assert(lcm(4, 5) == 20);
    assert(lcm(6, 8) == 24);
    assert(lcm(21, 6) == 42);
    assert(lcm(0, 5) == 0);
    assert(lcm(7, 0) == 0);
    assert(lcm(13, 17) == 221);
    assert(lcm(-4, 5) == 20);
    assert(lcm(-6, -8) == 24);

    cout << "All LCM tests passed!" << endl;
}

int main()
{
    testLCM();
    return 0;
}
