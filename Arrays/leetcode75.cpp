// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.
// Example 1:
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red=0,white=0,blue=0;
        for(int e: nums){
            if(e==0)red++;
            else if(e==2)blue++;
            else white++;
        }
        nums.clear();
        while(red){
            nums.push_back(0);red--;
        }
        while(white){
            nums.push_back(1);white--;
        }
        while(blue){
            nums.push_back(2);blue--;
        }
    }
};

int main(){
    vector<int> nums={2,0,2,1,1,0};
    Solution solution;
    solution.sortColors(nums);
    for(int e: nums){
        cout << e << " ";
    }
    return 0;
}