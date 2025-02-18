#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// Insertion Sort picks the next element and places it correctly, 
// but doesn't care if smaller elements are still in the unsorted part.
void insertionSort(vector<int> &arr) {
}

void testInsertionSort(vector<int> &arr)
{
    insertionSort(arr);
    vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert(arr == expected);
}

int main()
{
    vector<int> arr = {5, 2, 9, 3, 1, 4, 8, 6, 7};

    testInsertionSort(arr);

    cout << "Insertion sort test passed!" << endl;

    return 0;
}