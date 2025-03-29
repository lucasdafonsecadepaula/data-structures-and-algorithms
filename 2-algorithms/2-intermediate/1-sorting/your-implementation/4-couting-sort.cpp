#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

void countingSort(vector<int> &arr)
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

void testCountingSort()
{
    vector<int> arr1 = {4, 2, 2, 8, 3, 3, 1};
    countingSort(arr1);
    assert(arr1 == vector<int>({1, 2, 2, 3, 3, 4, 8}));

    vector<int> arr2 = {10, -1, 2, -3, 5, 0};
    countingSort(arr2);
    assert(arr2 == vector<int>({-3, -1, 0, 2, 5, 10}));

    vector<int> arr3 = {1, 1, 1, 1};
    countingSort(arr3);
    assert(arr3 == vector<int>({1, 1, 1, 1}));

    vector<int> arr4 = {5};
    countingSort(arr4);
    assert(arr4 == vector<int>({5}));

    vector<int> arr5 = {};
    countingSort(arr5);
    assert(arr5.empty());

    cout << "All counting sort tests passed!" << endl;
}

int main()
{
    testCountingSort();
    return 0;
}
