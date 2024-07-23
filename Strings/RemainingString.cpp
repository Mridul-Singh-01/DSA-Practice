// GFG Question -> Remaining String
// Given a string s without spaces, a character ch and an integer count. Your task is to return the substring that remains after the character ch has appeared count number of times.
// Note:  Assume upper case and lower case alphabets are different. “”(Empty string) should be returned if it is not possible, or the remaining substring is empty.
// Examples:
// Input: s = "Thisisdemostring", ch = 'i', count = 3
// Output: ng
// Explanation: The remaining substring of s after the 3rd
// occurrence of 'i' is "ng", hence the output is ng.

#include <bits/stdc++.h>
using namespace std;

string printString(string s, char ch, int count) {      //time complexity O(n) and space complexity O(1)
    int c = 0;
    int index = -1;
    string ans = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ch) {
            c++;
        }
        if (c == count) {
            index = i;
            break;
        }
    }
    if (index != -1 && index < s.size() - 1) {
        ans = s.substr(index + 1);
    }
    return ans;
}

int main(){
    string s="abcd";
    char ch='c';
    int count=1;
    cout << printString(s,ch,count);
    return 0;
}