// You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.
// You should return the array of nums such that the the array follows the given conditions:
// Every consecutive pair of integers have opposite signs.
// For all integers with the same sign, the order in which they were present in nums is preserved.
// The rearranged array begins with a positive integer.
// Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> posNums;
        vector<int> negNums;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                negNums.push_back(nums[i]);
            }
            else{
                posNums.push_back(nums[i]);
            }
        }
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                nums[i]=posNums[i/2];
            }
            else{
                nums[i]=negNums[i/2];
            }
        }
        return nums;
    }
};

// Optimized code
// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         vector<int> result(nums.size());
//         int posIndex = 0, negIndex = 1;
        
//         for (int num : nums) {
//             if (num >= 0) {
//                 result[posIndex] = num;
//                 posIndex += 2;
//             } else {
//                 result[negIndex] = num;
//                 negIndex += 2;
//             }
//         }
        
//         return result;
//     }
// };


int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    Solution ob;
    vector<int> ans=ob.rearrangeArray(nums);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}