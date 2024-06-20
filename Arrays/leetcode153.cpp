#include<stdio.h>
#include<limits.h>
#include <vector>
#include <algorithm>
#include<iostream>

class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[low] <= nums[high]) {
                ans = std::min(ans, nums[low]);
                break;
            }
            if (nums[low] <= nums[mid]) {
                ans = std::min(ans, nums[low]);
                low = mid + 1;
            } else {
                ans = std::min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main(){
    Solution solution;
    std::vector<int> arr={11,13,15,17};
    std::cout << solution.findMin(arr);
    return 0;
}