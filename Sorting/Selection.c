#include<stdio.h>
int *selectionsort(int arr[],int s){
    int temp,max;
    for(int i=s-1;i>0;i--){
        max=i;
        for (int j=i-1;j>=0;j--){
            if(arr[j]>arr[max]){
                max=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[max];
        arr[max]=temp;
    }
    return arr;
}
int main()
{
    int arr[6]={10,2,30,8,9,40};
    int s=6;
    int *res=selectionsort(arr,s);
    for (int i=0;i<s;i++){
        printf("%d  ",res[i]);
    }
    return 0;
}