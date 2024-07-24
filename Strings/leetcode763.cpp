// You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.
// Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
// Return a list of integers representing the size of these parts.
// Example 1:
// Input: s = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
// Explanation:
// The partition is "ababcbaca", "defegde", "hijhklij".
// This is a partition so that each letter appears in at most one part.
// A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {     //time complexity O(n) and space complexity O(1)
        vector<int>dict(26,0);
        int partition=-1;
        int maxImpact=0;
        for(int i=0;i<s.size();i++){
            dict[s[i]-'a']=i;
        }
        vector<int> ans;
        for(int i=0;i<s.size();i++){
           maxImpact=max(maxImpact,dict[s[i]-'a']);
            if(maxImpact==i){
                ans.push_back(maxImpact-partition);
                partition=maxImpact;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector res=s.partitionLabels("ababcbacadefegdehijhklij");
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}