// You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].
// We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them, the result should equal the sorted array.
// Return the largest number of chunks we can make to sort the array.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {       //time complexity O(n) and space complexity O(1)
        int maxCount=0;
        int finalCount=0;
        for(int i=0;i<arr.size();i++){
            maxCount=max(arr[i],maxCount);
            if(maxCount==i){
                finalCount++;
            }
        }
        return finalCount;
    }
};

int main(){
    Solution s;
    vector<int> arr={4,3,2,1,0};
    cout << s.maxChunksToSorted(arr);
    return 0;
}