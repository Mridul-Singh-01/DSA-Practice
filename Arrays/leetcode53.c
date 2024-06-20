/*Given an integer array nums, find the 
subarray with the largest sum, and return its sum.
Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.*/

//This is brout force approch but this has time complexcity of n2
#include<stdio.h>
#include<limits.h>
// int main(){
//     int arr[5]={1,2,-3,4,-5};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     int max_sum=INT_MIN;
//     for(int i=0;i<n;i++){
//         int sum=0;
//         for(int j=i;j<n;j++){
//             sum=sum+arr[j];
//             if(sum>max_sum){
//             max_sum=sum;
//             };
//         }        
//     }
//     printf("\n%d",max_sum);
//     return 0;
// }

//Kadane Algorithm approch in this time complexcity is n

int main(){
    int arr[5]={1,2,3,-4,-5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int curr_sum=0;
    int max_Sum=INT_MIN;
    for(int i=0;i<n;i++){
        curr_sum=curr_sum+arr[i];
        if(curr_sum>max_Sum){
            max_Sum=curr_sum;
        }
        if(curr_sum<0){
            curr_sum=0;
        }
    }
    printf("%d",max_Sum);
    return 0;
}