#include<stdio.h>
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
    int arr[6]={10,7,8,5,1,8};
    int n=6;
    int *res=insertionsort(arr,n);
    for (int i=0;i<n;i++){
        printf("%d  ",res[i]);
    }
    return 0;
}