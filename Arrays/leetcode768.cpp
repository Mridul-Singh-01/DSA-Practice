// You are given an integer array arr.
// We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.
// Return the largest number of chunks we can make to sort the array.

#include <bits/stdc++.h>
using namespace std;

int maxChunksToSorted(vector<int>& arr) {       //time complexity O(n) and space complexity O(n)
        int n=arr.size();
        vector<int> rmin(n + 1, INT_MAX);
        for(int i=n-1;i>=0;i--){
            rmin[i]=min(rmin[i+1],arr[i]);
        }
        int lmax=INT_MIN;
        int count=0;
        for(int i=0;i<n;i++){
            lmax=max(lmax,arr[i]);
            if(lmax<=rmin[i+1]){
                count++;
            }
        }
        return count;
}

int main(){
    vector<int> arr={5,4,3,2,1};
    cout << maxChunksToSorted(arr);
    return 0;
}