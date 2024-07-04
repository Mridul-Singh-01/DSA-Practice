// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
// Example 1:
// Input: nums = [3,2,3]
// Output: 3


//this solution using unordered_map which takes O(n) time and O(n) space
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int,int> freq;
//         for(int i=0;i<nums.size();i++){
//             freq[nums[i]]++;
//         }
//         int res=-1;
//         for(auto it:freq){
//             if(it.second>nums.size()/2){
//                 res=it.first;
//             }
//         }
//         return res;
//     }
// };

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count = count+(num == candidate) ? 1 : -1;
        }
        return candidate;
    }
};


int main(){
    vector<int> nums={3,2,3};
    Solution solution;
    cout << solution.majorityElement(nums);
    return 0;
}