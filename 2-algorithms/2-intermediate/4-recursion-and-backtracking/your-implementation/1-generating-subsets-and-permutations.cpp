#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{
}

vector<vector<int>> permutations(vector<int> &nums)
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