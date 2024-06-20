// Pair with given sum in a sorted array
// You are given an array Arr of size N. You need to find all pairs in the array that sum to a number K. If no such pair exists then output will be -1. The elements of the array are distinct and are in sorted order.
// Note: (a,b) and (b,a) are considered same. Also, an element cannot pair with itself, i.e., (a,a) is invalid.

// Example 1:

// Input:
// n = 7
// arr[] = {1, 2, 3, 4, 5, 6, 7}
// K = 8
// Output:
// 3
// Explanation:
// We find 3 such pairs that
// sum to 8 (1,7) (2,6) (3,5)
#include <vector>
#include<iostream>

class Solution{
  public:
    int Countpair(int arr[], int n, int sum){
        
        // Complete the function
        int left=0;
        int right=n-1;
        int c=0;
        while(left<right){
            if(arr[left]+arr[right]==sum){
                c++;
                left=left+1;
                right=right-1;
            }
            if(arr[left]+arr[right]>sum){
                right=right-1;
            }
            if(arr[left]+arr[right]<sum){
                left=left+1;
            }
            
        }
        if(c==0){
            return -1;
        }
        return c;
        
    }
};

int main(){
    Solution solution;
    std::vector<int> arr={1, 2, 3, 4, 5, 6, 7};
    int* arrPtr = arr.data(); 
    std::cout << solution.Countpair(arrPtr,7,8);
    return 0;
}