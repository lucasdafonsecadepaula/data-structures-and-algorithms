#include <iostream>
#include <cassert>
using namespace std;

bool isPalindrome(const string &str)
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