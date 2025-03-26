#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

void quickSortHelper(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    int pivotIndex = i + 1;

    quickSortHelper(arr, low, pivotIndex - 1);
    quickSortHelper(arr, pivotIndex + 1, high);
}

void quickSort(vector<int> &arr)
{
    quickSortHelper(arr, 0, arr.size() - 1);
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

void testQuickSort()
{
    vector<int> arr1 = {5, 2, 9, 3, 1, 4, 8, 6, 7};
    quickSort(arr1);
    assert(arr1 == vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));

    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    quickSort(arr2);
    assert(arr2 == vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));

    vector<int> arr3 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    quickSort(arr3);
    assert(arr3 == vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));

    vector<int> arr4 = {5, 5, 5, 5, 5};
    quickSort(arr4);
    assert(arr4 == vector<int>({5, 5, 5, 5, 5}));

    vector<int> arr5 = {42};
    quickSort(arr5);
    assert(arr5 == vector<int>({42}));

    vector<int> arr6 = {};
    quickSort(arr6);
    assert(arr6.empty());

    vector<int> arr7 = {-3, -1, -4, -2, 0, 2, 1};
    quickSort(arr7);
    assert(arr7 == vector<int>({-4, -3, -2, -1, 0, 1, 2}));

    cout << "All quick sort tests passed!" << endl;
}

int main()
{
    testQuickSort();
    return 0;
}