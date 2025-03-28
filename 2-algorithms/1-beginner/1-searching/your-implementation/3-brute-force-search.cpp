// pattern matching (basic string searching)
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

bool bruteForceSearch(const string &text, const string &pattern)
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

int main()
{
    string text = "ababcabcabababd";
    string pattern = "ababd";

    assert(bruteForceSearch(text, pattern) == true);
    assert(bruteForceSearch(text, "zzzz") == false);

    cout << "All tests passed!" << endl;

    return 0;
}
