//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Given two sorted arrays of size n and m respectively, find their union. The Union of two arrays can be defined as the common and distinct elements in the two arrays. Return the elements in sorted order.
// Example 1:
// Input: 
// n = 5, arr1[] = {1, 2, 3, 4, 5}  
// m = 5, arr2 [] = {1, 2, 3, 6, 7}
// Output: 
// 1 2 3 4 5 6 7
// Explanation: 
// Distinct elements including both the arrays are: 1 2 3 4 5 6 7.

// } Driver Code Ends
class Solution{
    public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        vector<int> unionArr;
        int i = 0, j = 0;

        while (i < n && j < m) {
            // Skip duplicates in arr1
            while (i > 0 && i < n && arr1[i] == arr1[i - 1]) i++;
            // Skip duplicates in arr2
            while (j > 0 && j < m && arr2[j] == arr2[j - 1]) j++;

            if (i < n && j < m) {
                if (arr1[i] < arr2[j]) {
                    unionArr.push_back(arr1[i]);
                    i++;
                } else if (arr1[i] > arr2[j]) {
                    unionArr.push_back(arr2[j]);
                    j++;
                } else {
                    unionArr.push_back(arr1[i]);
                    i++;
                    j++;
                }
            }
        }

        // Add remaining elements from arr1
        while (i < n) {
            if (i > 0 && arr1[i] != arr1[i - 1]) {
                unionArr.push_back(arr1[i]);
            } else if (i == 0) {
                unionArr.push_back(arr1[i]);
            }
            i++;
        }

        // Add remaining elements from arr2
        while (j < m) {
            if (j > 0 && arr2[j] != arr2[j - 1]) {
                unionArr.push_back(arr2[j]);
            } else if (j == 0) {
                unionArr.push_back(arr2[j]);
            }
            j++;
        }

        return unionArr;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends