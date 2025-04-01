#include <iostream>
#include <vector>
using namespace std;

int findSingleElement(const vector<int> &nums)
{
    int result = 0;

    for (int num : nums)
    {
        result ^= num;
    }

    return result;
}

int main()
{
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "The single non-repeating element is: " << findSingleElement(nums) << endl;
    return 0;
}
