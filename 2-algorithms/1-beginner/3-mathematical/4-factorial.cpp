#include <iostream>
#include <cassert>
using namespace std;

// Function to calculate the factorial of a number
long long factorial(int n)
{
    if (n < 0)
        return -1; // Factorial is not defined for negative numbers
    long long result = 1;
    for (int i = 1; i <= n; ++i)
    {
        result *= i;
    }
    return result;
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

void testFactorial()
{
    assert(factorial(0) == 1);        // 0! = 1
    assert(factorial(1) == 1);        // 1! = 1
    assert(factorial(2) == 2);        // 2! = 2
    assert(factorial(3) == 6);        // 3! = 6
    assert(factorial(4) == 24);       // 4! = 24
    assert(factorial(5) == 120);      // 5! = 120
    assert(factorial(10) == 3628800); // 10! = 3628800
    assert(factorial(-1) == -1);      // Negative numbers return -1

    cout << "All factorial tests passed!" << endl;
}

int main()
{
    testFactorial();
    return 0;
}
