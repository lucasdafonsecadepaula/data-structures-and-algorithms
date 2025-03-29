#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

int ternarySearch(const vector<int> &arr, int left, int right, int target)
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

void testTernarySearch()
{
    vector<int> arr = {-5, -2, 0, 3, 7, 10, 15, 20, 25};
    assert(ternarySearch(arr, 0, arr.size() - 1, 10) == 5);
    assert(ternarySearch(arr, 0, arr.size() - 1, 3) == 3);
    assert(ternarySearch(arr, 0, arr.size() - 1, 25) == 8);
    assert(ternarySearch(arr, 0, arr.size() - 1, -5) == 0);
    assert(ternarySearch(arr, 0, arr.size() - 1, 100) == -1);
    assert(ternarySearch(arr, 0, arr.size() - 1, -10) == -1);

    cout << "All ternary search tests passed!" << endl;
}

int main()
{
    testTernarySearch();
    return 0;
}
