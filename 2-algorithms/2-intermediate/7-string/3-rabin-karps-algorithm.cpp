#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// Function to calculate the hash value of a string using a rolling hash function
unsigned long long calculateHash(const string &str, int prime, int mod)
{
    unsigned long long hashValue = 0;
    int length = str.length();
    for (int i = 0; i < length; i++)
    {
        hashValue = (hashValue * prime + str[i]) % mod;
    }
    return hashValue;
}

// Rabin-Karp Algorithm for pattern searching
vector<int> rabinKarp(const string &text, const string &pattern)
{
    vector<int> result;
    int n = text.length();
    int m = pattern.length();
    int prime = 101;   // A prime number to use for the hash function
    int mod = 1e9 + 9; // A large prime number for modulus

    if (m > n)
        return result; // If the pattern is longer than the text, no match is possible

    unsigned long long patternHash = calculateHash(pattern, prime, mod);
    unsigned long long textHash = calculateHash(text.substr(0, m), prime, mod);
    unsigned long long primePower = 1;

    // Compute prime^(m-1) % mod for efficient rolling hash
    for (int i = 0; i < m - 1; i++)
    {
        primePower = (primePower * prime) % mod;
    }

    // Slide the window over the text
    for (int i = 0; i <= n - m; i++)
    {
        // If hashes match, check if the actual strings match
        if (patternHash == textHash && text.substr(i, m) == pattern)
        {
            result.push_back(i);
        }

        // If this is not the last window, update the hash for the next window
        if (i < n - m)
        {
            textHash = (textHash - text[i] * primePower) % mod; // Remove the leading character
            textHash = (textHash * prime + text[i + m]) % mod;  // Add the next character

            // Ensure the hash is positive
            if (textHash < 0)
            {
                textHash += mod;
            }
        }
    }

    return result;
}

int main()
{
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    vector<int> matches = rabinKarp(text, pattern);

    if (matches.empty())
    {
        cout << "Pattern not found." << endl;
    }
    else
    {
        cout << "Pattern found at indices: ";
        for (int index : matches)
        {
            cout << index << " ";
        }
        cout << endl;
    }

    return 0;
}
