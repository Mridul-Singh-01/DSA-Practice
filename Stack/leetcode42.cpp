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

//Another Apporach
// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n=height.size();
//         vector<int> leftMax(n);
//         vector<int> rightMax(n);
//         leftMax[0]=height[0];
//         rightMax[n-1]=height[n-1];
//         for(int i=1;i<n;i++){
//             leftMax[i]=max(height[i],leftMax[i-1]);
//         }
//         for(int i=n-2;i>=0;i--){
//             rightMax[i]=max(height[i],rightMax[i+1]);
//         }
//         int res=0;
//         int finalRes=0;
//         for(int i=0;i<n;i++){
//             if(height[i]<leftMax[i] && height[i]<rightMax[i]){
//                 res=min(leftMax[i],rightMax[i])-height[i];
//                 finalRes+=res;
//             }
//         }
//         return finalRes;
//     }
// };

int main(){
    Solution s;
    vector<int> arr={0,1,0,2,1,0,1,3,2,1,2,1};
    cout << s.trap(arr);
    return 0;
}