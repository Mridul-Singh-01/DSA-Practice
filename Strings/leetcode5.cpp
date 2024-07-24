// Given a string s, return the longest palindromic substring in s.
// Example 1:
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {        //time complexity O(n**2) and space compexity O(1)
        int resLen=0;
        string res="";
        for(int i=0;i<s.size();i++){
            //odd length
            int l=i;
            int r=i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(resLen<r-l+1){
                    resLen=r-l+1;
                    res=s.substr(l,resLen);
                }
                l--;
                r++;
            }
            //even length
            l=i;
            r=i+1;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(resLen<r-l+1){
                    resLen=r-l+1;
                    res=s.substr(l,resLen);
                }
                l--;
                r++;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    cout << s.longestPalindrome("abbad");
    return 0;
}