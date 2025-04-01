#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

struct Item
{
    int value, weight;
};

// Comparator function to sort items by value/weight ratio in descending order
bool compareItems(const Item &a, const Item &b)
{
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

// Function to compute the maximum value for the fractional knapsack problem
double fractionalKnapsack(int capacity, vector<Item> &items)
{
    sort(items.begin(), items.end(), compareItems);
    double totalValue = 0.0;

    for (const Item &item : items)
    {
        if (capacity >= item.weight)
        {
            capacity -= item.weight;
            totalValue += item.value;
        }
        else
        {
            totalValue += item.value * ((double)capacity / item.weight);
            break;
        }
    }
    return totalValue;
}

void testFractionalKnapsack()
{
    vector<Item> items1 = {{60, 10}, {100, 20}, {120, 30}};
    assert(abs(fractionalKnapsack(50, items1) - 240.0) < 1e-6);

    vector<Item> items2 = {{500, 30}, {400, 20}, {300, 10}};
    assert(abs(fractionalKnapsack(50, items2) - 900.0) < 1e-6);

    vector<Item> items3 = {{100, 50}};
    assert(abs(fractionalKnapsack(25, items3) - 50.0) < 1e-6);

    cout << "All fractional knapsack tests passed!" << endl;
}

int main()
{
    testFractionalKnapsack();
    return 0;
}
