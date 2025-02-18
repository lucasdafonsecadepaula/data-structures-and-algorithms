#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &arr) {
    bool shouldSort = true;
    while(shouldSort) {
        shouldSort = false;
        for(int i = 0; i < arr.size() - 1; i++) {
            if(arr[i] > arr[i + 1]) {
                shouldSort = true;
                swap(arr[i], arr[i + 1]);
            }
        }
    }
}


void testBubbleSort(vector<int> &arr)
{
    bubbleSort(arr);
    vector<int> expected = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    assert(arr == expected);
}

int main()
{
    vector<int> arr = {5, 2, 9, 3, 1, 4, 8, 6, 7};

    testBubbleSort(arr);

    cout << "Bubble sort test passed!" << endl;

    return 0;
}