#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

struct Activity
{
    int start, end;
};

// Comparator function to sort activities based on their end time
bool activityCompare(const Activity &a1, const Activity &a2)
{
    return a1.end < a2.end;
}

// Function to find the maximum number of activities that can be performed
int maxActivities(vector<Activity> &activities)
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

void testActivitySelection()
{
    vector<Activity> activities1 = {{1, 3}, {2, 5}, {3, 9}, {6, 8}, {8, 9}};
    assert(maxActivities(activities1) == 3);

    vector<Activity> activities2 = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
    assert(maxActivities(activities2) == 4);

    vector<Activity> activities3 = {};
    assert(maxActivities(activities3) == 0);

    cout << "All activity selection tests passed!" << endl;
}

int main()
{
    testActivitySelection();
    return 0;
}
