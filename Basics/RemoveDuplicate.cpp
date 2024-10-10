#include <bits/stdc++.h>
using namespace std;

void dupli(int arr[],int n){
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }
    for(auto i:mp){
        if(i.second>1){
            cout << i.first << " ";
        }
    }
}

int main() {
    int arr[10]={2,33,4,2,33,5,1,6,1,5};
    int n=10;
    dupli(arr,n);
    return 0;
}