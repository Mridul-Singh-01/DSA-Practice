// You are given an integer array nums where the largest integer is unique.
// Determine whether the largest element in the array is at least twice as much as every other number in the array. If it is, return the index of the largest element, or return -1 otherwise.
// Example 1:
// Input: nums = [3,6,1,0]
// Output: 1
// Explanation: 6 is the largest integer.
// For every other number in the array x, 6 is at least twice as big as x.
// The index of value 6 is 1, so we return 1.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dominantIndex(vector<int>& nums) {      //time complexity O(n) and sapce complexity O(1)
        int max1=INT_MIN,max2=INT_MIN;
        for(int n:nums){
            if(n>max1){
                max2=max1;
                max1=n;
            }
            else if(n>max2){
                max2=n;
            }
        }
        if(max1>=2*max2){
            for(int i=0;i<nums.size();i++){
                if(nums[i]==max1){
                    return i;
                }
            }
        }
        return -1;
    }
};

int main(){
    Solution s;
    vector<int> arr={4,3,2,8};
    cout << s.dominantIndex(arr);
    return 0;
}