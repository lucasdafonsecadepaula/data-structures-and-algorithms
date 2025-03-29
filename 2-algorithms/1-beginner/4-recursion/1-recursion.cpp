#include <iostream>
#include <chrono>
#include <vector>
#include <cassert>
using namespace std;

// Tail recursion can be better than non-tail recursion because it uses constant memory
// by leveraging a compiler optimization called tail call elimination,
// which avoids stack overflow issues in deep recursive calls.

// The main idea is to avoid having to backtrack to the previous function call's pointer
// to perform the last operation. Instead, we push the result forward in each step,
// which eliminates the need for additional stack frames.

long long nonTailFactorial(int n)
{
    if (n == 0)
        return 1;
    return n * nonTailFactorial(n - 1);
}

long long tailRecFactorial(int n, long long result = 1)
{
    if (n == 0)
        return result;
    return tailRecFactorial(n - 1, result * n);
}

long long nonTailFibonacci(int n)
{
    if (n <= 1)
        return n;
    return nonTailFibonacci(n - 1) + nonTailFibonacci(n - 2);
}

long long tailFibonacci(int n, long long acc = 0, long long prev = 1)
{
    if (n == 0)
        return acc;
    if (n == 1)
        return prev;
    return tailFibonacci(n - 1, prev, acc + prev);
}

long long nonTailPower(int v, int p)
{
    if (p == 0)
        return 1;
    return v * nonTailPower(v, p - 1);
}

long long tailPower(int v, int p, long long result = 1)
{
    if (p == 0)
        return result;
    return tailPower(v, p - 1, result * v);
}

int nonTailSumOfDigits(int n)
{
    if (n == 0)
        return 0;
    return (n % 10) + nonTailSumOfDigits(n / 10);
}

int tailSumOfDigits(int n, int sum = 0)
{
    if (n == 0)
        return sum;
    return tailSumOfDigits(n / 10, sum + (n % 10));
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

void testNonTailFactorial()
{
    assert(nonTailFactorial(5) == 120);
    assert(nonTailFactorial(10) == 3628800);
}

void testTailRecFactorial()
{
    assert(tailRecFactorial(5) == 120);
    assert(tailRecFactorial(10) == 3628800);
}

void testNonTailFibonacci()
{
    assert(nonTailFibonacci(5) == 5);
    assert(nonTailFibonacci(6) == 8);
}

void testTailFibonacci()
{
    assert(tailFibonacci(5) == 5);
    assert(tailFibonacci(6) == 8);
}

void testNonTailPower()
{
    assert(nonTailPower(2, 3) == 8);
    assert(nonTailPower(5, 4) == 625);
}

void testTailPower()
{
    assert(tailPower(2, 3) == 8);
    assert(tailPower(5, 4) == 625);
}

void testNonTailSumOfDigits()
{
    assert(nonTailSumOfDigits(123) == 6);
    assert(nonTailSumOfDigits(9876) == 30);
}

void testTailSumOfDigits()
{
    assert(tailSumOfDigits(123) == 6);
    assert(tailSumOfDigits(9876) == 30);
}

void performanceTest()
{
    const int TEST_VALUE = 100000;

    auto start = chrono::high_resolution_clock::now();
    nonTailFactorial(TEST_VALUE);
    auto end = chrono::high_resolution_clock::now();

    cout << "Non-Tail recursion executed successfully for n = " << TEST_VALUE << endl;
    cout << "Execution time: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl
         << endl;

    start = chrono::high_resolution_clock::now();
    tailRecFactorial(TEST_VALUE, 1);
    end = chrono::high_resolution_clock::now();

    cout << "Tail recursion executed successfully for n = " << TEST_VALUE << endl;
    cout << "Execution time: "
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl
         << endl;
}

int main()
{
    testNonTailFactorial();
    testTailRecFactorial();
    testNonTailFibonacci();
    testTailFibonacci();
    testNonTailPower();
    testTailPower();
    testNonTailSumOfDigits();
    testTailSumOfDigits();
    performanceTest();

    cout << "All tests passed!" << endl;
    return 0;
}
