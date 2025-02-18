#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

// Selection Sort picks the smallest element first and places it correctly.
void selectionSort(vector<int> &arr) {
}

void testSelectionSort(vector<int> &arr)
{
    selectionSort(arr);
    vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert(arr == expected);
}

int main()
{
    vector<int> arr = {5, 2, 9, 3, 1, 4, 8, 6, 7};

    testSelectionSort(arr);

    cout << "Selection sort test passed!" << endl;

    return 0;
}