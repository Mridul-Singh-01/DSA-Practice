#include<bits/stdc++.h>
using namespace std;

int partition(int arr[],int low,int high){
    int i=low;
    int j=high;
    int pivot=arr[low];
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[j],arr[low]);
    return j;
}

void qs(int arr[],int low, int high){
    if(low<high){
        int position=partition(arr,low,high);
        qs(arr,low,position);
        qs(arr,position+1,high);
    }
}

void quickSort(int arr[],int size){
    qs(arr,0,size-1);
}

int main(){
    int arr[5]={1,5,2,4,3};
    int size=sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,size);
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    return 0;
}