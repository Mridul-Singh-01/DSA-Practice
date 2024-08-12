#include<bits/stdc++.h>
using namespace std;

int binarySerch(vector<int> arr,int k){     //log n
    int low=0;
    int high=arr.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==k){
            return 1;
        }
        if(k>mid){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return 0;
}

int SquareLessThanK(int k){
    int low=1;
    int high=k;
    int res=1;
    while(low<=high){
        int mid=(low+high)/2;
        if((mid*mid)<=k){
            res=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return res;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    int k=4;
    cout << SquareLessThanK(501);
    return 0;
}