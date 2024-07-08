// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.
// Example 1:
// Input: nums = [1,1,1], k = 2
// Output: 2

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumFreq;
        sumFreq[0] = 1;
        int sum = 0;
        int count = 0;
        for (int num : nums) {
            sum += num;
            if (sumFreq.find(sum - k) != sumFreq.end()) {
                count += sumFreq[sum - k];
            }
            sumFreq[sum]++;
        }
        return count;
    }
};

int main(){
    vector<int> nums={10,1,23,3,4};
    Solution solution;
    cout << solution.subarraySum(nums,7);
    return 0;
}