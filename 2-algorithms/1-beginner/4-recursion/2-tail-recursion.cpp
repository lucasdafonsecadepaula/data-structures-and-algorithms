#include <iostream>
#include <chrono>
using namespace std;

long long tailRecFactorial(int n, long long result) {
    if(n == 0) return result;
    return tailRecFactorial(n - 1, result * n);
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

void testTailRecursion() {
    const int TEST_VALUE = 100000;

    if (tailRecFactorial(5, 1) != iterativeFactorial(5)) {
        cout << "Test failed for n = 5!" << endl;
        return;
    }
    if (tailRecFactorial(10, 1) != iterativeFactorial(10)) {
        cout << "Test failed for n = 10!" << endl;
        return;
    }

    auto start = chrono::high_resolution_clock::now();
    long long result = tailRecFactorial(TEST_VALUE, 1);
    auto end = chrono::high_resolution_clock::now();

    cout << "Tail recursion executed successfully for n = " << TEST_VALUE << endl;
    cout << "Execution time: "
              << chrono::duration_cast<chrono::milliseconds>(end - start).count()
              << " ms" << endl;
}

int main() {
    testTailRecursion();
    return 0;
}
