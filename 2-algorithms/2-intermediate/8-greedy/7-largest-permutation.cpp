#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void largestPermutation(vector<int> &arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> pos;

    for (int i = 0; i < n; i++)
    {
        pos[arr[i]] = i;
    }

    for (int i = 0; i < n && k > 0; i++)
    {
        int largest = n - i;

        if (arr[i] == largest)
            continue;

        int largestPos = pos[largest];

        swap(arr[i], arr[largestPos]);

        pos[arr[largest]] = i;
        pos[arr[largestPos]] = largestPos;

        k--;
    }
}

int main()
{
    vector<int> arr = {4, 2, 3, 5, 1};
    int k = 2;

    largestPermutation(arr, k);

    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
