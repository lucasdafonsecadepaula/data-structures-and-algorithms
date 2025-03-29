#include <iostream>
#include <cassert>
using namespace std;

bool isPalindrome(const string &str)
{
    string reversed = "";
    for (int i = str.size() - 1; i >= 0; i--)
    {
        reversed += str[i];
    }
    return str == reversed;
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

void testPalindromeCheck()
{
    assert(isPalindrome("racecar") == true);
    assert(isPalindrome("hello") == false);
    assert(isPalindrome("madam") == true);
    assert(isPalindrome("a") == true);
    assert(isPalindrome("") == true);
    assert(isPalindrome("level") == true);
    assert(isPalindrome("12321") == true);
    assert(isPalindrome("12345") == false);

    cout << "All palindrome check tests passed!" << endl;
}

int main()
{
    testPalindromeCheck();
    return 0;
}