// Given a binary array nums, return the maximum number of consecutive 1's in the array.
// Example 1:
// Input: nums = [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sum=0;
        int maxSum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                sum=sum+1;
                maxSum=max(sum,maxSum);
            }
            if(nums[i]==0){
                sum=0;
            }
        }
        return maxSum;
    }
};

int main(){
    vector<int> nums={1,1,1,0,1,1,1,1};
    Solution solution;
    cout << solution.findMaxConsecutiveOnes(nums);
    return 0;
}