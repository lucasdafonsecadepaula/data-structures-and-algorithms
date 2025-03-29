#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

int ternarySearch(const vector<int> &arr, int left, int right, int target)
{
    while (left <= right)
    {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == target)
            return mid1;
        if (arr[mid2] == target)
            return mid2;

        if (target < arr[mid1])
        {
            right = mid1 - 1;
        }
        else if (target > arr[mid2])
        {
            left = mid2 + 1;
        }
        else
        {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    return -1;
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

void testTernarySearch()
{
    vector<int> arr = {-5, -2, 0, 3, 7, 10, 15, 20, 25};
    assert(ternarySearch(arr, 0, arr.size() - 1, 10) == 5);
    assert(ternarySearch(arr, 0, arr.size() - 1, 3) == 3);
    assert(ternarySearch(arr, 0, arr.size() - 1, 25) == 8);
    assert(ternarySearch(arr, 0, arr.size() - 1, -5) == 0);
    assert(ternarySearch(arr, 0, arr.size() - 1, 100) == -1);
    assert(ternarySearch(arr, 0, arr.size() - 1, -10) == -1);

    cout << "All ternary search tests passed!" << endl;
}

int main()
{
    testTernarySearch();
    return 0;
}
