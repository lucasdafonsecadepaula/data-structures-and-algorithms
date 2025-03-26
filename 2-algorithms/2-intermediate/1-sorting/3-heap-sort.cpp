#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

int getParent(int index)
{
    return (index - 1) / 2;
}

int getLeftChild(int index)
{
    return (index * 2) + 1;
}

int getRightChild(int index)
{
    return (index * 2) + 2;
}

int getLastNonLeaf(int size)
{
    return (size / 2) - 1;
}

void heapify(vector<int> &arr, int n, int i)
{
    int largest = i;
    int left = getLeftChild(i);
    int right = getRightChild(i);

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest == i)
        return;

    swap(arr[i], arr[largest]);
    heapify(arr, n, largest);
}

void heapSort(vector<int> &arr)
{
    int n = arr.size();

    for (int i = getLastNonLeaf(n); i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
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

void testHeapSort()
{
    vector<int> arr1 = {5, 2, 9, 3, 1, 4, 8, 6, 7};
    heapSort(arr1);
    assert(arr1 == vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));

    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    heapSort(arr2);
    assert(arr2 == vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));

    vector<int> arr3 = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    heapSort(arr3);
    assert(arr3 == vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9}));

    vector<int> arr4 = {5, 5, 5, 5, 5};
    heapSort(arr4);
    assert(arr4 == vector<int>({5, 5, 5, 5, 5}));

    vector<int> arr5 = {42};
    heapSort(arr5);
    assert(arr5 == vector<int>({42}));

    vector<int> arr6 = {};
    heapSort(arr6);
    assert(arr6.empty());

    vector<int> arr7 = {-3, -1, -4, -2, 0, 2, 1};
    heapSort(arr7);
    assert(arr7 == vector<int>({-4, -3, -2, -1, 0, 1, 2}));

    cout << "All heap sort tests passed!" << endl;
}

int main()
{
    testHeapSort();
    return 0;
}