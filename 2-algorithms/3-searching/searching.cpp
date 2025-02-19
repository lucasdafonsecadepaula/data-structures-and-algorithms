#include <iostream>
#include <vector>

// Linear Search Function: Works on both sorted & unsorted arrays
int linearSearch(const std::vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

// Binary Search Function:  Works only on sorted arrays
int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if(arr[mid] == target) return mid;
        if(arr[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return -1;
}

// Binary Search Function (Recursive):  Works only on sorted arrays
int binarySearchRec(const std::vector<int>& arr, int left, int right, int target) {
    if (left > right) return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target) return mid;
    if (arr[mid] < target) return binarySearchRec(arr, mid + 1, right, target);
    return binarySearchRec(arr, left, mid - 1, target);
}

int main() {
    std::vector<int> data = {4, 2, 8, 10, 15, 23, 42};
    std::vector<int> sortedData = {2, 4, 8, 10, 15, 23, 42};
    int target = 10;

    int linearRes = linearSearch(data, target);
    int binaryRes = binarySearch(sortedData, target);
    int binaryRecRes = binarySearchRec(sortedData, 0, sortedData.size() - 1, target);

    if (linearRes == binaryRes && linearRes == binaryRecRes)
        std::cout << "Element found at index: " << linearRes << std::endl;

    return 0;
}
