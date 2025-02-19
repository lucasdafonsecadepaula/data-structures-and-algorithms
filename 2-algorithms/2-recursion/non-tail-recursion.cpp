#include <iostream>
#include <chrono>

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
        std::cout << "Test failed for n = 5!" << std::endl;
        return;
    }
    if (nonTailFactorial(10) != iterativeFactorial(10)) {
        std::cout << "Test failed for n = 10!" << std::endl;
        return;
    }

    auto start = std::chrono::high_resolution_clock::now();
    long long result = nonTailFactorial(TEST_VALUE);
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Non-tail recursion executed successfully for n = " << TEST_VALUE << std::endl;
    std::cout << "Execution time: "
              << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
              << " µs" << std::endl;
}

int main() {
    testNonTailRecursion();
    return 0;
}
