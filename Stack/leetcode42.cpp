#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        int finalRes = 0;
        while (left <= right) {
            if (height[left] <= height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    finalRes += leftMax - height[left];
                }
                left++;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    finalRes += rightMax - height[right];
                }
                right--;
            }
        }
        return finalRes;
    }
};

int main(){
    Solution s;
    vector<int> arr={0,1,0,2,1,0,1,3,2,1,2,1};
    cout << s.trap(arr);
    return 0;
}