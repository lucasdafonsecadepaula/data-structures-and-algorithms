# Modular Arithmetic - Overview and Applications
#
# Modular arithmetic is a system of arithmetic for integers where numbers "wrap around" after they reach a certain value, known as the modulus.
# This is especially useful in scenarios where you need to operate with large numbers while keeping them within a manageable range.
#
# ## Key Concepts:
# 
# 1. **Modular Exponentiation**:
#    - Modular exponentiation involves computing powers of numbers under a modulus. 
#    - The operation `a^b % m` means calculating the result of `a^b` and then taking the remainder when divided by `m`.
#    - It's important because calculating large powers directly can be computationally expensive, but modular exponentiation allows for efficient computation via **Exponentiation by Squaring**.
#    - Example: `3^13 % 7` can be computed efficiently using modular exponentiation.
#
# 2. **Modular Inverse**:
#    - The modular inverse of a number `a` modulo `m` is a number `x` such that:
#      `a * x ≡ 1 (mod m)`
#    - This is useful when you need to "divide" in modular arithmetic, as division in modular arithmetic is not directly defined.
#    - The modular inverse exists if and only if `gcd(a, m) = 1`.
#    - It's found using the **Extended Euclidean Algorithm**, which also computes the greatest common divisor (GCD).
#
# ## Why is Modular Arithmetic Important?
# 
# 1. **Efficiency in Computation**:
#    - Modular arithmetic helps efficiently compute large numbers in cryptography, algorithms, and number theory.
#    - Algorithms like **RSA** (used in encryption) rely on modular exponentiation and inverses.
# 
# 2. **Chinese Remainder Theorem**:
#    - The **Chinese Remainder Theorem (CRT)** is a powerful tool that allows you to solve systems of simultaneous congruences. 
#    - In modular arithmetic, the CRT can be used to find a unique solution modulo the product of the moduli, given the system of congruences.
#    - Example: Given `x ≡ a1 (mod m1)` and `x ≡ a2 (mod m2)`, the CRT provides a method to find the unique `x` modulo `m1 * m2`.
#    - This is especially useful in cryptography, distributed systems, and solving problems involving multiple modulus conditions.
# 
# 3. **Real-World Applications**:
#    - **Cryptography**: RSA encryption, Diffie-Hellman key exchange.
#    - **Hashing**: Modular arithmetic is used in hash functions and checksums.
#    - **Computational Geometry**: For problems involving large numbers or repeating patterns.
#    - **Error Detection**: In computer science, error-checking algorithms like checksums and cyclic redundancy checks (CRC) use modular arithmetic.
#
# ## LeetCode Problems that Use Modular Arithmetic:
#
# Here are some common LeetCode problems that require knowledge of modular arithmetic, modular exponentiation, and modular inverses:
#
# 1. **LeetCode Problem 29: Divide Two Integers**:
#    - Involves integer division, and knowing how to perform division using modular inverses can help.
# 
# 2. **LeetCode Problem 50: Pow(x, n)**:
#    - This problem asks you to compute `x^n`, and it involves efficient computation of powers using modular exponentiation techniques.
#
# 3. **LeetCode Problem 36: Valid Sudoku**:
#    - While not directly involving modular arithmetic, this problem often requires efficient checking methods that can benefit from modular techniques for constraints and grouping.
#
# 4. **LeetCode Problem 387: First Unique Character in a String**:
#    - Involves string hashing and could be solved more efficiently using modular arithmetic techniques.
#
# 5. **LeetCode Problem 976: Largest Perimeter Triangle**:
#    - Involves number theory and working with moduli to check the feasibility of conditions.
#
# 6. **check-if-digits-are-equal-in-string-after-operations**:
#    - https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-ii/solutions/6457300/easy-to-understand-c-code-using-binomial-coefficients/
#
# ## Conclusion:
# Modular arithmetic is a critical concept for understanding efficient computation, particularly when dealing with large numbers. It's foundational for fields like cryptography and is widely used in algorithms and data structures.
# If you're learning about cryptography or number theory, these topics are essential, and understanding them will make solving complex problems much easier.
