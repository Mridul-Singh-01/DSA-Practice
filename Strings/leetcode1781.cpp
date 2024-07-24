// The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
// For example, the beauty of "abaacc" is 3 - 1 = 2.
// Given a string s, return the sum of beauty of all of its substrings.
// Example 1:
// Input: s = "aabcb"
// Output: 5
// Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beauty(vector<int> alpha){      
        int mf=INT_MIN,lf=INT_MAX;
        for(int i=0;i<alpha.size();i++){
            mf=max(mf,alpha[i]);
            if(alpha[i]>=1){
                lf=min(lf,alpha[i]);
            }
        }
        return mf-lf;
    }
    int beautySum(string s) {       //time complexity O(n**2) and space is O(1)
        int res=0;
        for(int i=0;i<s.size();i++){
            vector<int>alpha(26,0);
            for(int j=i;j<s.size();j++){    
                alpha[s[j]-'a']++;
                res+=beauty(alpha);
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    cout << s.beautySum("aabaca");
    return 0;
}