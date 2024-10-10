#include<bits/stdc++.h>
using namespace std;

int sumArray(int arr[], int n) {
    if (n == 0) {
        return 0;
    }
    return arr[n - 1] + sumArray(arr, n - 1);
}

int main(){
    int arr[10]={1,2,3,4,5,6,7,8,9,10};
    cout << sumArray(arr,10);
    return 0;
}