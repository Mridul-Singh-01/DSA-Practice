// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.

#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int l = 0;
        int r = s.length() - 1;
        while (l < r)
        {
            while (l < r && !isalnum(s[l])) // we can use if and else if condition on place of while loop
                ++l;
            while (l < r && !isalnum(s[r]))
                --r;
            if (tolower(s[l]) != tolower(s[r]))
                return false;
            ++l;
            --r;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string s="aabbaa";
    cout << solution.isPalindrome(s);
    return 0;
}