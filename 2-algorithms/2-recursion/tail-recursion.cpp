#include <iostream>
#include <chrono>

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
        std::cout << "Test failed for n = 5!" << std::endl;
        return;
    }
    if (tailRecFactorial(10, 1) != iterativeFactorial(10)) {
        std::cout << "Test failed for n = 10!" << std::endl;
        return;
    }

    auto start = std::chrono::high_resolution_clock::now();
    long long result = tailRecFactorial(TEST_VALUE, 1);
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Tail recursion executed successfully for n = " << TEST_VALUE << std::endl;
    std::cout << "Execution time: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
              << " ms" << std::endl;
}

int main() {
    testTailRecursion();
    return 0;
}
