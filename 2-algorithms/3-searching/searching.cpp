#include <iostream>
#include <vector>
#include <cassert>

// Linear Search Function: Works on both sorted & unsorted arrays
int linearSearch(const std::vector<int> &arr, int target)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

// Binary Search Function: Works only on sorted arrays
int binarySearch(const std::vector<int> &arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        if (arr[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return -1;
}

// Binary Search Function (Recursive): Works only on sorted arrays
int binarySearchRecHelper(const std::vector<int> &arr, int left, int right, int target)
{
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid;
    if (arr[mid] < target)
        return binarySearchRecHelper(arr, mid + 1, right, target);
    return binarySearchRecHelper(arr, left, mid - 1, target);
}

int binarySearchRec(const std::vector<int> &arr, int target)
{
    return binarySearchRecHelper(arr, 0, arr.size() - 1, target);
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
    std::vector<int> emptyData;
    assert(linearSearch(emptyData, 10) == -1);
    assert(binarySearch(emptyData, 10) == -1);
    assert(binarySearchRec(emptyData, 10) == -1);

    std::vector<int> data1 = {10, 20, 30, 40, 50};
    assert(linearSearch(data1, 10) == 0);
    assert(binarySearch(data1, 10) == 0);
    assert(binarySearchRec(data1, 10) == 0);

    assert(linearSearch(data1, 50) == 4);
    assert(binarySearch(data1, 50) == 4);
    assert(binarySearchRec(data1, 50) == 4);

    assert(linearSearch(data1, 60) == -1);
    assert(binarySearch(data1, 60) == -1);
    assert(binarySearchRec(data1, 60) == -1);

    std::vector<int> data2 = {10, 20, 30, 40};
    assert(linearSearch(data2, 20) == 1);
    assert(binarySearch(data2, 20) == 1);
    assert(binarySearchRec(data2, 20) == 1);

    std::vector<int> largeData(10000);
    for (int i = 0; i < 10000; ++i)
    {
        largeData[i] = i * 2;
    }
    assert(linearSearch(largeData, 5000) == 2500);
    assert(binarySearch(largeData, 5000) == 2500);
    assert(binarySearchRec(largeData, 5000) == 2500);

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
