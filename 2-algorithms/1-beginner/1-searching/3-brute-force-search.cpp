// pattern matching (basic string searching)
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool bruteForceSearch(const string &text, const string &pattern)
{
    int n = text.length();
    int m = pattern.length();
    bool found = false;

    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (text[i + j] != pattern[j])
            {
                break;
            }
        }
        if (j == m)
            return true;
    }

    return false;
}

int main()
{
    string text = "ababcabcabababd";
    string pattern = "ababd";

    assert(bruteForceSearch(text, pattern) == true);
    assert(bruteForceSearch(text, "zzzz") == false);

    cout << "All tests passed!" << endl;

    return 0;
}
