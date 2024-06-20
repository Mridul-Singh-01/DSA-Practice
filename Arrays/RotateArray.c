// Given an array of integers arro of size N and an integer, the task is to rotate the array elements to the left by d positions. 
// Input:1234567
// Output: 3456712
#include<stdio.h>
void function(int *arr,int d,int n){
    for(int i=0; i<d;i++){
        int last=arr[0];
        for(int j=0;j<n-1;j++){
            arr[j]=arr[j+1];
        }
        arr[n-1]=last;
    }
}

int main(){
    int arr[]={1,2,3,4,5,6,7};
    int n= sizeof(arr)/sizeof(arr[0]);
    int d=2;
    function(arr,d,n);
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    return 0;
}