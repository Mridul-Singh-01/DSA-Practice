#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr,int x){
    int n= arr.size();
    int low=0;
    int high=n-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]>=x){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr={1,2,3,3,6,8,8,9,10};
    cout << lowerBound(arr,9);
    return 0;
}