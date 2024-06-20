#include <functional>
#include <queue>
#include <vector>
#include <iostream>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (int i = 0; i < k; i++) {
            pq.push(nums[i]);
        }
        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};

int main() {
    std::vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    Solution solution;
    int kthLargest = solution.findKthLargest(nums, k);
    std::cout << "The " << k << "nd largest element is: " << kthLargest << std::endl;
    return 0;
}
