// Given an array arr of n positive integers, your task is to find all the leaders in the array.
// An element of the array is considered a leader if it is greater than all the elements on its right side or if it is equal to the maximum element on its right side.
// The rightmost element is always a leader.

//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(int n, int arr[]) {
        vector<int> leaders;
    if (n == 0) return leaders;

    int max_from_right = arr[n - 1];
    leaders.push_back(max_from_right);

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= max_from_right) {
            max_from_right = arr[i];
            leaders.push_back(max_from_right);
        }
    }
    reverse(leaders.begin(), leaders.end());
    return leaders;
    }
};

//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t; // testcases
    while (t--) {
        long long n;
        cin >> n; // total size of array

        int arr[n];

        // inserting elements in the array
        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution obj;
        // calling leaders() function
        vector<int> v = obj.leaders(n, arr);

        // printing elements of the vector
        for (auto it = v.begin(); it != v.end(); it++) {
            cout << *it << " ";
        }

        cout << endl;
    }
}

// } Driver Code Ends