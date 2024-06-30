// Given an array nums, return true if the array was originally sorted in non-decreasing order, then rotated some number of positions (including zero). Otherwise, return false.

// There may be duplicates in the original array.

// Note: An array A rotated by x positions results in an array B of the same length such that A[i] == B[(i+x) % A.length], where % is the modulo operation.
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int c=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1) % n]){
                c++;
            }
            if(c>1){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution solution;
    vector<int> arr;
    arr.push_back(6);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    cout << solution.check(arr);
    return 0;
}