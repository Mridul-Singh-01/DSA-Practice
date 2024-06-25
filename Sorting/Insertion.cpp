#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[],int size){
    for(int i=0;i<size;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}

void display(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[5]={10,30,90,20,15};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout << "Array before sorting : ";
    display(arr, size);
    insertionSort(arr,size);
    cout << "\nArray after sorting : ";
    display(arr, size);
    return 0;
}