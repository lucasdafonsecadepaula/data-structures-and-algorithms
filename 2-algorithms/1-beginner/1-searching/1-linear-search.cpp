#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// Linear Search Function: Works on both sorted & unsorted arrays
int linearSearch(const vector<int> &arr, int target)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
            return i;
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

int main()
{
    vector<int> emptyData;
    assert(linearSearch(emptyData, 10) == -1);

    vector<int> data1 = {10, 20, 30, 40, 50};
    assert(linearSearch(data1, 10) == 0);

    assert(linearSearch(data1, 50) == 4);

    assert(linearSearch(data1, 60) == -1);

    vector<int> data2 = {10, 20, 30, 40};
    assert(linearSearch(data2, 20) == 1);

    vector<int> largeData(10000);
    for (int i = 0; i < 10000; ++i)
    {
        largeData[i] = i * 2;
    }
    assert(linearSearch(largeData, 5000) == 2500);

    cout << "All tests passed!" << endl;
    return 0;
}
