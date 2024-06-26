#include<bits/stdc++.h>
using namespace std;

void merge(int arr[],int low,int mid,int high){
    int left=low;
    int right=mid+1;
    vector <int> temp;
    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}

void divide(int arr[],int low,int high){
    if(low>=high) return;
    int mid=(low+high)/2;
    divide(arr,low,mid);
    divide(arr,mid+1,high);
    merge(arr,low,mid,high);
}

void mergeSort(int arr[],int size){
    divide(arr,0,size-1);
}

int main(){
    int arr[5]={90,80,40,50,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,size);
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    return 0;
}