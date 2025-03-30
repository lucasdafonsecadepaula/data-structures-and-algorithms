#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

void generateSubsets(vector<int> &nums, vector<int> &current, int index, vector<vector<int>> &result)
{
    if (index == nums.size())
    {
        result.push_back(current);
        return;
    }

    generateSubsets(nums, current, index + 1, result);

    current.push_back(nums[index]);
    generateSubsets(nums, current, index + 1, result);
    current.pop_back();
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> result;
    vector<int> current;
    generateSubsets(nums, current, 0, result);
    return result;
}

void generatePermutations(vector<int> &nums, int index, vector<vector<int>> &result)
{
    if (index == nums.size())
    {
        result.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        generatePermutations(nums, index + 1, result);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permutations(vector<int> &nums)
{
    vector<vector<int>> result;
    generatePermutations(nums, 0, result);
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

void testSubsets()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = subsets(nums);
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[0].size(); j++)
        {
            cout << result[i][j] << ", ";
        }
        cout << endl;
    }
    cout << endl;
    assert(result.size() == 8);
}

void testPermutations()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = permutations(nums);
    assert(result.size() == 6);
}

int main()
{
    testSubsets();
    testPermutations();
    cout << "All tests passed!" << endl;
    return 0;
}