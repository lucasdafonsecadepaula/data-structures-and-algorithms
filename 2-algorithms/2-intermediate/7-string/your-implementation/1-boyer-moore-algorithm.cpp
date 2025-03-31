#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

vector<int> badCharacterHeuristic(const string &pattern)
{
}

vector<int> boyerMoore(const string &text, const string &pattern)
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
    string text = "ABAAABCDABAAABCDBABCDABDE";
    string pattern = "ABC";
    vector<int> res = {4, 12, 17};
    assert(boyerMoore(text, pattern) == res);
    cout << "All tests passed!" << endl;
    return 0;
}
