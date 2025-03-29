#include <iostream>
#include <cassert>
#include <cctype>
using namespace std;

pair<int, int> countVowelsAndConsonants(const string &str)
{
    int vowels = 0, consonants = 0;
    string vowelSet = "aeiouAEIOU";

    for (char ch : str)
    {
        if (isalpha(ch))
        {
            if (vowelSet.find(ch) != string::npos)
                vowels++;
            else
                consonants++;
        }
    }
    return {vowels, consonants};
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

void testCountVowelsAndConsonants()
{
    assert(countVowelsAndConsonants("hello") == make_pair(2, 3));
    assert(countVowelsAndConsonants("world") == make_pair(1, 4));
    assert(countVowelsAndConsonants("aeiou") == make_pair(5, 0));
    assert(countVowelsAndConsonants("bcdfg") == make_pair(0, 5));
    assert(countVowelsAndConsonants("12345") == make_pair(0, 0));
    assert(countVowelsAndConsonants("a e i o u") == make_pair(5, 0));
    assert(countVowelsAndConsonants("") == make_pair(0, 0));

    cout << "All vowel and consonant count tests passed!" << endl;
}

int main()
{
    testCountVowelsAndConsonants();
    return 0;
}
