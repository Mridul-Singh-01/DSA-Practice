//longest subaaray without repeation characters

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    if(n == 0) return 0;
    vector <int> mp(256, -1);
    int max_len = 0;
    int left = 0;
    int right=0;
    while(right < n){
        if(mp[s[right]] != -1){
            left = max(mp[s[right]] + 1, left);
        }
        mp[s[right]] = right;
        max_len = max(max_len, right - left + 1);
        right++;
    }
    return max_len;
}

int main(){
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}