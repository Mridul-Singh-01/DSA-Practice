// Given an integer array nums, find three numbers whose product is maximum and return the maximum product.
// Example 1:
// Input: nums = [1,2,3]
// Output: 6

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {     //time compexity O(n) sapce compexity O(1)
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;
        int n=nums.size();
        for (int n : nums) {
            if (n > max1) {
                max3 = max2;
                max2 = max1;
                max1 = n;
            }
            else if (n > max2) {
                max3 = max2;
                max2 = n;
            }
            else if (n > max3) {
                max3 = n;
            }
            if (n < min1) {
                min2 = min1;
                min1 = n;
            }
            else if (n < min2) {
                min2 = n;
            }
        }
        return max(max1*max2*max3, max1*min1*min2);
    }
};

int main(){
    Solution s;
    vector<int> arr={-4,-5,1,3};
    cout << s.maximumProduct(arr);
    return 0;
}