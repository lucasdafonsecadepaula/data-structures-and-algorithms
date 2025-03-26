// (Divide & Conquer)
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSortHelper(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSortHelper(arr, left, mid);
    mergeSortHelper(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void mergeSort(vector<int> &arr)
{
    mergeSortHelper(arr, 0, arr.size() - 1);
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

void testMergeSort()
{
    vector<int> arr1 = {5, 2, 9, 3, 1, 4, 8, 6, 7};
    mergeSort(arr1);
    assert(arr1 == vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));

    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    mergeSort(arr2);
    assert(arr2 == vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));

    vector<int> arr3 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    mergeSort(arr3);
    assert(arr3 == vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));

    vector<int> arr4 = {5, 5, 5, 5, 5};
    mergeSort(arr4);
    assert(arr4 == vector<int>({5, 5, 5, 5, 5}));

    vector<int> arr5 = {42};
    mergeSort(arr5);
    assert(arr5 == vector<int>({42}));

    vector<int> arr6 = {};
    mergeSort(arr6);
    assert(arr6.empty());

    vector<int> arr7 = {-3, -1, -4, -2, 0, 2, 1};
    mergeSort(arr7);
    assert(arr7 == vector<int>({-4, -3, -2, -1, 0, 1, 2}));

    cout << "All merge sort tests passed!" << endl;
}

int main()
{
    testMergeSort();
    return 0;
}