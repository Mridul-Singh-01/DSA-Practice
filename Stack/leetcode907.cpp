#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextSmallerElement(vector<int> arr) {
        int n = arr.size();
        vector<int> res(n, n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                res[i] = st.top() - i;
            } else {
                res[i] = n - i;
            }
            st.push(i);
        }
        return res;
    }

    vector<int> previousSmallerElement(vector<int> arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                res[i] = i - st.top();
            } else {
                res[i] = i + 1;
            }
            st.push(i);
        }
        return res;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> left = previousSmallerElement(arr);
        vector<int> right = nextSmallerElement(arr);
        int mod = int(1e9 + 7);
        long sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum = (sum + (long)arr[i] * left[i] * right[i]) % mod;
        }
        return (int)sum;
    }
};
