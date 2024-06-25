#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[],int size){
    for(int i=0;i<size-1;i++){
        int min=i;
        for(int j=i;j<size;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        swap(arr[i],arr[min]);
    }
}

void display(int arr[],int size){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int arr[5]={10,4,6,2,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    cout << "Array before sorting : ";
    display(arr,size);
    selectionSort(arr,size);
    cout << "\nSorted Array :";
    display(arr,size);
    return 0;
}