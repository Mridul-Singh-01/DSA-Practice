#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        stack<int> st;
        unordered_map<int, int> mp;
        for (int i = 0; i < len2; i++) {
            while (!st.empty() && nums2[i] > st.top()) {
                mp[st.top()] = nums2[i];
                st.pop();
            }
            st.push(nums2[i]);
        }
        while (!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }
        vector<int> ans(len1);
        for (int i = 0; i < len1; i++) {
            ans[i] = mp[nums1[i]];
        }
        return ans;
    }
};

int main(){
    Solution sol;
    std::vector<int> nums1 = {4, 1, 2};
    std::vector<int> nums2 = {1, 3, 4, 2};
    std::vector<int> result = sol.nextGreaterElement(nums1, nums2);
    for (int r : result) {
        std::cout << r << " ";
    }
    return 0;
}