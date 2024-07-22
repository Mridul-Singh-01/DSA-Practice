//GFG QUESTION -> Maximum product subset of an array
// Given an array arr. The task is to find and return the maximum product possible with the subset of elements present in the array.
// Note:
// The maximum product can be a single element also.
// Since the product can be large, return it modulo 109 + 7.
// Input: arr[] = [-1, 0, -2, 4, 3]
// Output: 24
// Explanation: Maximum product will be ( -1 * -2 * 4 * 3 ) = 24
// Input: arr[] = [-1, 0]
// Output: 0
// Explanation: Maximum product will be ( -1 * 0) = 0

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {        //time complexity O(n) and space complexity O(1)
        const int MOD = 1000000007;
        if (arr.size() == 1) return arr[0] % MOD;
        long long int maxProduct = 1;
        int negativeCount = 0;
        int zeroCount = 0;
        int maxNegative = INT_MIN;
        for (int num : arr) {
            if (num == 0) {
                zeroCount++;
                continue;
            }
            if (num < 0) {
                negativeCount++;
                maxNegative = std::max(maxNegative, num);
            }
            maxProduct = (maxProduct * num) % MOD;
        }
        if (zeroCount == arr.size()) 
            return 0;
        
        if (negativeCount % 2 != 0) {
            if (negativeCount == 1 && zeroCount + negativeCount == arr.size()) 
                return 0;
            maxProduct = (maxProduct / maxNegative) % MOD;
        }
        if (maxProduct < 0) 
            maxProduct += MOD;
        
        return maxProduct;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}