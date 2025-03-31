#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

vector<int> badCharacterHeuristic(const string &pattern)
{
    const int ALPHABET_SIZE = 256;
    vector<int> badChar(ALPHABET_SIZE, -1);

    for (int i = 0; i < pattern.length(); i++)
    {
        badChar[pattern[i]] = i;
    }

    return badChar;
}

vector<int> boyerMoore(const string &text, const string &pattern)
{
    vector<int> result;
    int m = pattern.length();
    int n = text.length();

    if (m > n)
        return result;

    vector<int> badChar = badCharacterHeuristic(pattern);

    int s = 0;
    while (s <= (n - m))
    {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j])
        {
            j--;
        }

        if (j < 0)
        {
            result.push_back(s);
            s += (s + m < n) ? m - badChar[text[s + m]] : 1;
        }
        else
        {
            s += max(1, j - badChar[text[s + j]]);
        }
    }

    return result;
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

int main()
{
    string text = "ABAAABCDABAAABCDBABCDABDE";
    string pattern = "ABC";
    vector<int> res = {4, 12, 17};
    assert(boyerMoore(text, pattern) == res);
    cout << "All tests passed!" << endl;
    return 0;
}
