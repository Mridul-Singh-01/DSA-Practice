#include<bits/stdc++.h>
using namespace std;

void bubblesort(int arr[],int s)
{
    int temp,swapped=1;
     for (int i=s-1;i>=0;i--)
     {
        swapped=0;
        for (int j=0;j<i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                swapped=1;
            }
        }
        if(swapped==0){
            break;
        }
     }
}

void display(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[5]={5,60,3,8,100};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout << "Array before sorting : ";
    display(arr, size);
    bubblesort(arr,size);
    cout << "\nArray after sorting : ";
    display(arr, size);
    return 0;
}