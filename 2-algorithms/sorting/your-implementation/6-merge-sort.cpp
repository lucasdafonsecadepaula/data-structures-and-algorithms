#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

void mergeSort(vector<int> &arr)
{
}

void testMergeSort(vector<int> &arr)
{
    mergeSort(arr);
    vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert(arr == expected);
}

int main()
{
    vector<int> arr = {5, 2, 9, 3, 1, 4, 8, 6, 7};

    testMergeSort(arr);

    cout << "Merge sort test passed!" << endl;

    return 0;
}