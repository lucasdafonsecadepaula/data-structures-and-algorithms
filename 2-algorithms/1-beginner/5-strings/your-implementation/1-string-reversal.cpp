#include <iostream>
#include <cassert>
using namespace std;

void reverseString(string &str)
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

void testReverseString()
{
    string testA = "hello";
    string testB = "world";
    string testC = "a";
    string testD = "";
    string testE = "racecar";
    string testF = "12345";
    reverseString(testA);
    reverseString(testB);
    reverseString(testC);
    reverseString(testD);
    reverseString(testE);
    reverseString(testF);
    assert(testA == "olleh");
    assert(testB == "dlrow");
    assert(testC == "a");
    assert(testD == "");
    assert(testE == "racecar");
    assert(testF == "54321");

    cout << "All string reversal tests passed!" << endl;
}

int main()
{
    testReverseString();
    return 0;
}
