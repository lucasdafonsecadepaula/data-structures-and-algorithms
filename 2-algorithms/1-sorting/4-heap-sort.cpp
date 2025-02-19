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

void testHeapSort(vector<int> &arr)
{
    heapSort(arr);
    vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert(arr == expected);
}

int main()
{
    vector<int> arr = {5, 2, 9, 3, 1, 4, 8, 6, 7};

    testHeapSort(arr);

    cout << "Heap sort test passed!" << endl;

    return 0;
}