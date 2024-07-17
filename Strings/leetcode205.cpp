// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> smap;
        unordered_map<char,bool> used;
        for(int i=0;i<s.size();i++){
            if(smap.count(s[i])){
                if(smap[s[i]]!=t[i]){
                    return false;
                }
            }
            else{
                if(used.count(t[i])){
                    return false;
                }
                smap[s[i]]=t[i];
                used[t[i]]=true;
            }
        }
        return true;
    }
};

int main(){
    Solution s;
    cout << s.isIsomorphic("egg","aded");
    return 0;
}