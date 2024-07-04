// Given an array arr[], with index ranging from 0 to n-1, select any two indexes, i and j such that i < j .
//From the subarray arr[i...j], select the two minimum numbers and add them, you will get the score for that subarray.
//Return the maximum possible score across all the subarrays of array arr[].

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends


class Solution {
  public:
    long long pairWithMaxSum(long long arr[], long long N) {
        // Your code goes here
        long long maxSum=INT_MIN;
        for(int i=0;i<N-1;i++){
            long long sum=arr[i]+arr[i+1];
            maxSum=max(maxSum,sum);
        }
        return maxSum;
    }
};


//{ Driver Code Starts.
int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll a[n];
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.pairWithMaxSum(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends