#include <iostream>
using namespace std;

int countSetBits(int n)
{
    int count = 0;

    while (n)
    {
        n = n & (n - 1); // Remove the rightmost set bit
        count++;
    }

    return count;
}

int main()
{
    int n = 29; // Example number: 29 in binary is 11101, which has 4 set bits
    cout << "The number of set bits in " << n << " is: " << countSetBits(n) << endl;
    return 0;
}
