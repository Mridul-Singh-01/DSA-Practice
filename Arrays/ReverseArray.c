#include<stdio.h>

int main(){
    int arr[6]={10,2,8,6,9,5};
    int n=6;
    int temp;
    printf("Before Reverse ");
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    for(int i=0;i<n/2;i++){
        temp=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
    }
    printf("\nAfter Reverse ");
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    return 0;
}