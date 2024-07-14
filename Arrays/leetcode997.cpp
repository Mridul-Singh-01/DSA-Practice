// LEETCODE PROBLEM 977
// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
// Example 1:
// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {      //time complexity O(n) and spce O(n)
        vector<int> res(nums.size(), 0);
        int left = 0;
        int right = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (abs(nums[left]) > abs(nums[right])) {
                res[i] = nums[left] * nums[left];
                left++;
            } else {
                res[i] = nums[right] * nums[right];
                right--;
            }
        }
        return res;   
    }
};

int main(){
    Solution solution;
    vector<int> nums={-4,-1,0,3,7};
    vector<int> res=solution.sortedSquares(nums);
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}