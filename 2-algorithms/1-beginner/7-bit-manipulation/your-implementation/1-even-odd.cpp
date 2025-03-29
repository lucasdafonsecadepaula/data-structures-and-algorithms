#include <iostream>
#include <cassert>
using namespace std;

// the representation of 1 in binary is 00...1
// so if we do the AND bitwise oparator we only check the least significant bit.
// lets do an example using 9:
// the representation of 9 is 00001001, so:
// 9  -> 00001001
// 1  -> 00000001
// res-> 00000001 -> this is equal to the number 1, so is odd;

bool isEven(int n)
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

void testEvenOdd()
{
    assert(isEven(2) == true);
    assert(isEven(3) == false);
    assert(isEven(0) == true);
    assert(isEven(-4) == true);
    assert(isEven(-7) == false);
    assert(isEven(1001) == false);
    assert(isEven(2048) == true);

    cout << "All even-odd tests passed!" << endl;
}

int main()
{
    testEvenOdd();
    return 0;
}
