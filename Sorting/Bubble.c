#include<stdio.h>
int *bubblesort(int arr[],int s)
{
    int temp;
     for (int i=0;i<s;i++)
     {
        for (int j=0;j<s-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
     }
    return arr;
}


int main()
{
    int arr[5]={5,6,3,8,1};
    int s=5;
    int *arr1;
    arr1=bubblesort(arr,s);
    for (int i=0;i<5;i++)
    {
        printf("%d  ",arr1[i]);
    } 
    return 0;
}