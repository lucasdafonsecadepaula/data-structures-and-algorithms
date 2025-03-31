#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int longestCommonSubsequence(const string &s1, const string &s2)
{
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
    assert(longestCommonSubsequence("abcde", "ace") == 3);
    assert(longestCommonSubsequence("abc", "abc") == 3);
    assert(longestCommonSubsequence("abc", "def") == 0);
    assert(longestCommonSubsequence("abcdef", "acf") == 3);
    assert(longestCommonSubsequence("abcd", "bc") == 2);
    assert(longestCommonSubsequence("", "") == 0);

    cout << "All tests passed!" << endl;
    return 0;
}
