#include<iostream>
#include<vector>
using namespace std;

int* reverseArray(int arr[],int n){
    int* arr2 = new int[n];
    int i=0;
    while(n!=0){
        arr2[i]=arr[n-1];
        n--;
        i++;
    }
    return arr2;
}

void reverse_optimzed(vector<int> &arr){
    int r=arr.size();
    int l=0;
    while(l<r){
        int temp=arr[l];
        arr[l]=arr[r];
        arr[r]=temp;
        l++;
        r--;
    }
}

int main(){
    vector<int> arr={0,1,2,3,4,5,6,7,8,9};
    reverse_optimzed(arr);
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
    return 0;
}