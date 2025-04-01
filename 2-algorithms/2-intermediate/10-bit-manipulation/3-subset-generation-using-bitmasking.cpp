#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(const vector<int> &nums)
{
    int n = nums.size();
    // There are 2^n subsets
    int subsetCount = 1 << n; // 2^n

    for (int mask = 0; mask < subsetCount; mask++)
    {
        vector<int> subset;

        // Check each bit of mask
        for (int i = 0; i < n; i++)
        {
            // If the ith bit is set, include nums[i] in the current subset
            if (mask & (1 << i))
            {
                subset.push_back(nums[i]);
            }
        }

        // Print the current subset
        cout << "{ ";
        for (int elem : subset)
        {
            cout << elem << " ";
        }
        cout << "}\n";
    }
}

int main()
{
    vector<int> nums = {1, 2, 3};
    cout << "The subsets are:\n";
    generateSubsets(nums);
    return 0;
}
