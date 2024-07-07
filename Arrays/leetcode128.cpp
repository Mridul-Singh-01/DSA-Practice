// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.
// Example 1:
// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        int longest=1;
        unordered_set<int> st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        for(auto it:st){
            if(st.find(it-1)==st.end()){
                int x=it;
                int cur=1;
                while(st.find(x+1)!=st.end()){
                    x=x+1;
                    cur=cur+1;
                }
                longest=max(longest,cur);
            }
        }
        return longest;
    }
};

int main(){
    Solution s;
    vector<int> nums={100,4,200,1,3,2};
    cout<<s.longestConsecutive(nums)<<endl;
    return 0;
}