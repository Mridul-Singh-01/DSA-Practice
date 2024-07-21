// Given an integer array nums and two integers left and right, return the number of contiguous non-empty subarrays such that the value of the maximum array element in that subarray is in the range [left, right].
// The test cases are generated so that the answer will fit in a 32-bit integer.
// Example 1:
// Input: nums = [2,1,4,3], left = 2, right = 3
// Output: 3
// Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].

#include <bits/stdc++.h>
using namespace std;

int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {     
    int i=0,j=0;
    int count=0,preCount=0;
    while(j<nums.size()){
        if(nums[j]>right){
            preCount=0;
            i=j+1;
        }
        else if(nums[j]>=left && nums[j]<=right){
            preCount=j-i+1;
        }
        count+=preCount;
        j++;
    }
    return count;
}

int main(){
    vector<int> nums={2,20,3,4,5,8};
    cout << numSubarrayBoundedMax(nums,2,8);
    return 0;
}