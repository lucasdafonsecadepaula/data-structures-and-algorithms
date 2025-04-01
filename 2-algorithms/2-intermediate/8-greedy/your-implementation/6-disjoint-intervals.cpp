#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the maximum number of disjoint intervals
int maxDisjointIntervals(vector<pair<int, int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), [](pair<int, int> a, pair<int, int> b)
         { return a.second < b.second; });
    int count = 0;
    int lastEnd = -1;

    for (const auto &interval : intervals)
    {
        if (interval.first > lastEnd)
        {
            count++;
            lastEnd = interval.second;
        }
    }

    return count;
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
    vector<pair<int, int>> intervals = {{1, 3}, {2, 5}, {6, 9}, {8, 10}, {11, 15}};

    cout << maxDisjointIntervals(intervals) << endl;
    return 0;
}
