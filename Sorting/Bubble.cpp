#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[],int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

void display(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[5]={90,80,50,40,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout << "Array before sorting : ";
    display(arr, size);
    bubbleSort(arr,size);
    cout << "\nArray after sorting : ";
    display(arr, size);
    return 0;
}