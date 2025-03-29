#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

//             ((target - arr[low]) * (high - low))
// pos = low + ------------------------------------
//                 (arr[high] - arr[low])
int interpolationSearch(const vector<int> &arr, int target)
{
    if (arr.empty())
        return -1;

    int low = 0, high = arr.size() - 1;
    while (low <= high && target >= arr[low] && target <= arr[high])
    {
        if (low == high)
        {
            return (arr[low] == target) ? low : -1;
        }

        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == target)
            return pos;

        if (arr[pos] < target)
            low = pos + 1;
        else
            high = pos - 1;
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

void testInterpolationSearch()
{
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    assert(interpolationSearch(arr, 7) == 3);
    assert(interpolationSearch(arr, 19) == 9);
    assert(interpolationSearch(arr, 1) == 0);
    assert(interpolationSearch(arr, 2) == -1);
    assert(interpolationSearch(arr, 15) == 7);
    assert(interpolationSearch(arr, 20) == -1);
    vector<int> emptyArr;
    assert(interpolationSearch(emptyArr, 5) == -1);
    cout << "All interpolation search tests passed!" << endl;
}

int main()
{
    testInterpolationSearch();
    return 0;
}
