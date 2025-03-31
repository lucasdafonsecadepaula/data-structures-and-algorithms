#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to compute the Z-array for a string
vector<int> ZAlgorithm(const string &s)
{
}

int main()
{
    string text = "ababcababcabc";
    vector<int> Z = ZAlgorithm(text);

    // Output the Z-array
    cout << "Z-array for the string '" << text << "' is: ";
    for (int i = 0; i < Z.size(); ++i)
    {
        cout << Z[i] << " ";
    }
    cout << endl;

    return 0;
}
