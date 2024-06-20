// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
// Example 1:
// Input: nums = [1,2,3,1]
// Output: true

#include<stdio.h>

bool containsDuplicate(int* nums, int numsSize) {
    for(int i=0;i<numsSize;i++){
        for(int j=i+1;j<numsSize;j++){
            if(nums[i]==nums[j]){
                return "true";
            }
            else{
                return "false";
            }
        }
    }
}
int main(){
    int nums[5]={10,3,4,68,9};
    int numsSize=5;
    printF("%B",containsDuplicate(&nums,numsSize));
    return 0;
}