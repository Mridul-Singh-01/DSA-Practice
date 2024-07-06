// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
// For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].
#include<stdio.h>

void rev(int arr[], int s, int e) {
    while (s < e) {
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;
        s++;
        e--;
    }
}

int *nextpermutation(int arr[], int n){
    int index=-1;
    for(int i=n-2;i>=0;i--){
        if(arr[i]<arr[i+1]){
            index=i;
            break;
        }
    }
    if(index==-1){
        rev(arr,0,n-1);
        return arr;
    }
    for(int i=n-1;i>index;i--){
        if(arr[index]<arr[i]){
            int temp=arr[index];
            arr[index]=arr[i];
            arr[i]=temp;
            break;
        }
    }
    rev(arr,index+1,n-1);
    return arr;
}

int main(){
    int arr[5]={3,5,3,4,2};
    nextpermutation(arr,5);
    for(int i=0;i<5;i++){
        printf("%d",arr[i]);
    }
    return 0;
}
//Another optimal solution in c++
// class Solution {
// public:
//     void nextPermutation(vector<int>& nums) {
//         int ind=-1;
//         int n=nums.size();
//         for(int i=n-2;i>=0;i--){
//             if(nums[i]<nums[i+1]){
//                 ind=i;
//                 break;
//             }
//         }
//         if(ind==-1){
//             reverse(nums.begin(),nums.end());
//             return;
//         }
//         for(int i=n-1;i>ind;i--){
//             if(nums[i]>nums[ind]){
//                 swap(nums[ind],nums[i]);
//                 break;
//             }
//         }
//         reverse(nums.begin()+ind+1,nums.end());
//     }
// };