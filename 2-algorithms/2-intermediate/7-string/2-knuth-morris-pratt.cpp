#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to preprocess the pattern and create the LPS (Longest Prefix Suffix) array
vector<int> computeLPSArray(const string &pattern)
{
    int m = pattern.length();
    vector<int> lps(m, 0); // LPS array initialized to 0
    int length = 0;        // length of the previous longest prefix suffix
    int i = 1;

    while (i < m)
    {
        if (pattern[i] == pattern[length])
        {
            length++;
            lps[i] = length;
            i++;
        }
        else
        {
            // mismatch after length matches
            if (length != 0)
            {
                length = lps[length - 1]; // Use the LPS array to skip characters
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// KMP Algorithm for pattern searching
vector<int> KMP_Search(const string &text, const string &pattern)
{
    vector<int> result;
    int n = text.length();
    int m = pattern.length();

    vector<int> lps = computeLPSArray(pattern); // Preprocess pattern
    int i = 0;                                  // index for text
    int j = 0;                                  // index for pattern

    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == m)
        { // Pattern found, append the starting index to the result
            result.push_back(i - j);
            j = lps[j - 1]; // Use LPS to shift the pattern
        }
        else if (i < n && pattern[j] != text[i])
        { // Mismatch
            if (j != 0)
            {
                j = lps[j - 1]; // Use LPS to avoid unnecessary comparisons
            }
            else
            {
                i++;
            }
        }
    }

    return result;
}

int main()
{
    string text = "ABABDABACDABABCABAB";
    string pattern = "ABABCABAB";

    vector<int> matches = KMP_Search(text, pattern);

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
