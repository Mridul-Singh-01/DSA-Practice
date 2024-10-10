#include<bits/stdc++.h>
using namespace std;

vector<int> mergeArray(vector<int> &arr1,vector<int> &arr2){
    int n1=arr1.size();
    int n2=arr2.size();
    vector<int> arr;
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            arr.push_back(arr1[i]);
            i++;
        }
        else{
            arr.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n1){
        arr.push_back(arr1[i]);
        i++;
    }
    while(j<n2){
        arr.push_back(arr2[j]);
        j++;
    }
    return arr;
}

int main(){
    vector<int> arr1={1,4,6,8,18,20};
    vector<int> arr2={3,6,7,9,19,21};
    vector<int> arr=mergeArray(arr1,arr2);
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
    return 0;
}