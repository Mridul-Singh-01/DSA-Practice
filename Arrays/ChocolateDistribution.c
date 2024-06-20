// Given an array of N integers where each value represents the number of chocolates in a packet. Each packet can have a variable number of chocolates. There are m students, the task is to distribute chocolate packets such that:
// Each student gets one packet.
// The difference between the number of chocolates in the packet with maximum chocolates and the packet with minimum chocolates given to the students is minimum.

#include<stdio.h>
#include<limits.h>
int *insertionsort(int arr[],int n){
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return arr;
}
int main(){
    int arr[5]={10,2,3,22,15};
    int m=3;
    int min_diff=INT_MAX;
    int n=sizeof(arr)/sizeof(arr[0]);
    if (m == 0 || n == 0)
        printf("%d",0);
    insertionsort(arr,n);
    if (n < m)
        printf("%d",-1);
    for(int i=0;i+m-1<n;i++){
        int diff=arr[m+i-1]-arr[i];
        if(diff<min_diff){
            min_diff=diff;
        }
    }
    printf("%d",min_diff);
    return 0;
}