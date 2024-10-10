#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr, int start,int end){
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

void rotate(vector<int> &arr,int k){
    int n=arr.size()-1;
    k=k%arr.size();
    reverseArray(arr,0,n);
    reverseArray(arr,0,k);
    reverseArray(arr,k+1,n);
}

int main() {
    int n=2;
    vector<int> arr={2,3,5,11,1,6};
    rotate(arr,n);
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
    return 0;
}