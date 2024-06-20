// Given two strings s and t, return true if t is an anagram of s, and false otherwise.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
// class Solution {


#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> countS, countT;
        for (char c : s) {
            countS[c]++;
        }
        for (char c : t) {
            countT[c]++;
        }

        return countS == countT;
    }
};
int main(){
    Solution solution;
    string s = "anagram";
    string t = "anagrae";
    cout << solution.isAnagram(s, t);
    return 0;
}