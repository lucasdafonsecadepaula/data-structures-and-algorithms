#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int longestIncreasingSubsequence(const vector<int> &nums)
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
    assert(longestIncreasingSubsequence({10, 9, 2, 5, 3, 7, 101, 18}) == 4);
    assert(longestIncreasingSubsequence({0, 1, 0, 3, 2, 3}) == 4);
    assert(longestIncreasingSubsequence({7, 7, 7, 7, 7, 7, 7}) == 1);
    assert(longestIncreasingSubsequence({}) == 0);
    assert(longestIncreasingSubsequence({1, 2, 3, 4, 5}) == 5);
    assert(longestIncreasingSubsequence({5, 4, 3, 2, 1}) == 1);

    cout << "All tests passed!" << endl;
    return 0;
}
