#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to compute the Z-array for a string
vector<int> ZAlgorithm(const string &s)
{
    int n = s.length();
    vector<int> Z(n, 0); // Z-array initialized to 0
    int l = 0, r = 0;    // l and r are the bounds of the current window

    for (int i = 1; i < n; ++i)
    {
        if (i <= r)
        {
            // Case 1: If i is within the window [l, r], we can reuse previous results
            Z[i] = min(r - i + 1, Z[i - l]);
        }

        // Case 2: We extend the window to the right as much as possible
        while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]])
        {
            Z[i]++;
        }

        // Update the window [l, r] if we expanded the window
        if (i + Z[i] - 1 > r)
        {
            l = i;
            r = i + Z[i] - 1;
        }
    }

    return Z;
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
