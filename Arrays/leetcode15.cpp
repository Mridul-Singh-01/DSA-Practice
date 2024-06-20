// 3Sum Problem
// Given an integer array nums,
// return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
#include <vector>
#include <iostream>
#include <algorithm>  // for sort

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum > 0) {
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k + 1]) {
                        k--;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = solution.threeSum(nums);

    for (const auto& triplet : result) {
        cout << "[";
        for (size_t i = 0; i < triplet.size(); ++i) {
            cout << triplet[i];
            if (i < triplet.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }
    return 0;
}
//4Sum
// class Solution {
// public:
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         sort(nums.begin(),nums.end());
//         vector<vector<int>> ans;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             if(i>0 && nums[i]==nums[i-1]) continue;
//             for(int j=i+1;j<n;j++){
//                 if(j>i+1 && nums[j]==nums[j-1]) continue;
//                 int k=j+1;
//                 int l=n-1;
//                 while(l>k){
//                     long long sum=nums[i]+nums[j];
//                     sum+=nums[k];
//                     sum+=nums[l];
//                     if(sum== target){
//                         vector<int> temp={nums[i],nums[j], nums[k], nums[l]};
//                         ans.push_back(temp);
//                         k++;
//                         l--;
//                         while(l>k && nums[k]==nums[k-1]) continue;
//                         while(l>k && nums[l]==nums[l+1]) continue;
//                     }
//                     else if(sum>target){
//                         l--;
//                     }
//                     else{
//                         k++;
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };