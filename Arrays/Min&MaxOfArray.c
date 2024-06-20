#include<stdio.h>
#include <limits.h>

int max_Fun(int arr[],int n){
    int max_num=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>max_num){
            max_num=arr[i];
        }
    }
    return max_num;
}

int min_Fun(int arr[],int n){
    int min_num=INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<min_num){
            min_num=arr[i];
        }
    }
    return min_num;
}

int main(){
    int arr[5]={10,2,5,11,8};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("\n");
    printf("Max number :%d",max_Fun(arr,n));
    printf("\n");
    printf("Min number :%d",min_Fun(arr,n));
    return 0;
}