#include<stdio.h>
int *bubblesort(int arr[],int s)
{
    int temp,swapped=1;
     for (int i=0;i<s;i++)
     {
        swapped=0;
        for (int j=0;j<s-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                swapped=1;
            }
        }
     }
    return arr;
}


int main()
{
    int arr[5]={5,60,3,8,100};
    int s=5;
    int *arr1;
    arr1=bubblesort(arr,s);
    for (int i=0;i<5;i++)
    {
        printf("%d  ",arr1[i]);
    } 
    return 0;
}