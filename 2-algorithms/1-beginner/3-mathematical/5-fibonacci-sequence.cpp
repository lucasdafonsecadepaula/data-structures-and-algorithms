#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

// Function to generate Fibonacci sequence up to n terms
vector<long long> fibonacci(int n)
{
    vector<long long> sequence;
    if (n <= 0)
        return sequence;   // Return an empty sequence if n is non-positive
    sequence.push_back(0); // F(0)
    if (n == 1)
        return sequence;
    sequence.push_back(1); // F(1)

    for (int i = 2; i < n; ++i)
    {
        sequence.push_back(sequence[i - 1] + sequence[i - 2]);
    }
    return sequence;
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

// Test function for Fibonacci sequence
void testFibonacci()
{
    vector<long long> result1 = fibonacci(0);
    assert(result1.empty()); // Should be empty

    vector<long long> result2 = fibonacci(1);
    assert(result2 == vector<long long>({0})); // Only 0

    vector<long long> result3 = fibonacci(2);
    assert(result3 == vector<long long>({0, 1})); // 0, 1

    vector<long long> result4 = fibonacci(5);
    assert(result4 == vector<long long>({0, 1, 1, 2, 3})); // First 5 Fibonacci numbers

    vector<long long> result5 = fibonacci(10);
    assert(result5 == vector<long long>({0, 1, 1, 2, 3, 5, 8, 13, 21, 34})); // First 10 Fibonacci numbers

    cout << "All Fibonacci sequence tests passed!" << endl;
}

int main()
{
    testFibonacci();
    return 0;
}
