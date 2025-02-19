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

void testQuickSort(vector<int> &arr)
{
    quickSort(arr);
    vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert(arr == expected);
}

int main()
{
    vector<int> arr = {5, 2, 9, 3, 1, 4, 8, 6, 7};

    testQuickSort(arr);

    cout << "Quick sort test passed!" << endl;

    return 0;
}