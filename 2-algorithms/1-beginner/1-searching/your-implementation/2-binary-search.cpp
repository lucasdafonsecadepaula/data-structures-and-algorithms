#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// Binary Search Function: Works only on sorted arrays
int binarySearch(const vector<int> &arr, int target)
{
}

int binarySearchRec(const vector<int> &arr, int target)
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
    vector<int> emptyData;
    assert(binarySearch(emptyData, 10) == -1);
    assert(binarySearchRec(emptyData, 10) == -1);

    vector<int> data1 = {10, 20, 30, 40, 50};
    assert(binarySearch(data1, 10) == 0);
    assert(binarySearchRec(data1, 10) == 0);

    assert(binarySearch(data1, 50) == 4);
    assert(binarySearchRec(data1, 50) == 4);

    assert(binarySearch(data1, 60) == -1);
    assert(binarySearchRec(data1, 60) == -1);

    vector<int> data2 = {10, 20, 30, 40};
    assert(binarySearch(data2, 20) == 1);
    assert(binarySearchRec(data2, 20) == 1);

    vector<int> largeData(10000);
    for (int i = 0; i < 10000; ++i)
    {
        largeData[i] = i * 2;
    }
    assert(binarySearch(largeData, 5000) == 2500);
    assert(binarySearchRec(largeData, 5000) == 2500);

    cout << "All tests passed!" << endl;
    return 0;
}
