#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int longestIncreasingSubsequence(const vector<int> &nums)
{
    if (nums.empty())
        return 0;

    vector<int> dp(nums.size(), 1);
    int maxLength = 1;

    for (size_t i = 1; i < nums.size(); i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        maxLength = max(maxLength, dp[i]);
    }

    return maxLength;
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
