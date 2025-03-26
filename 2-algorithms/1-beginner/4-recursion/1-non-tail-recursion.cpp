#include <iostream>
#include <chrono>
using namespace std;

long long nonTailFactorial(int n) {
    if(n ==0) return 1;
    return n * nonTailFactorial(n - 1);
};

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


long long iterativeFactorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

void testNonTailRecursion() {
    const int TEST_VALUE = 100000;

    if (nonTailFactorial(5) != iterativeFactorial(5)) {
        cout << "Test failed for n = 5!" << endl;
        return;
    }
    if (nonTailFactorial(10) != iterativeFactorial(10)) {
        cout << "Test failed for n = 10!" << endl;
        return;
    }

    auto start = chrono::high_resolution_clock::now();
    long long result = nonTailFactorial(TEST_VALUE);
    auto end = chrono::high_resolution_clock::now();

    cout << "Non-tail recursion executed successfully for n = " << TEST_VALUE << endl;
    cout << "Execution time: "
              << chrono::duration_cast<chrono::microseconds>(end - start).count()
              << " µs" << endl;
}

int main() {
    testNonTailRecursion();
    return 0;
}
