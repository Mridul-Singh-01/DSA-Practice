//arr - > [1,5,-3,7,1]
//output -> [5,7,7,-1,-1];

#include<bits/stdc++.h>
using namespace std;

//brute force approach
vector<int> nextGreaterElement(vector<int> arr){
    vector<int> res;
    for(int i=0;i<arr.size();i++){
        int temp=-1;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]>arr[i]){
                temp=arr[j];
                break;
            }
        }
        res.push_back(temp);
    }
    return res;
}

//Optimized Solution using Monotonic Stack(store elements in specific order in stack is called monotonic stack)
vector<int> nextGreaterElementRightUsingStack(vector<int> arr) {    //Also Called next Greater Element 
    int n = arr.size();
    vector<int> res(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        if(st.empty())res[i]=-1;
        else{
            res[i]=st.top();
        }
        st.push(arr[i]);
    }
    return res;
}

vector<int> nextGreaterElementLeftUsingStack(vector<int> arr) { //Also Called previous Greater Element 
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            res[i] = st.top();
        }
        st.push(arr[i]);
    }
    return res;
}

vector<int> nextSmallerElementRightUsingStack(vector<int> arr) {    //Also Called next smaller Element 
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            res[i] = st.top();
        }
        st.push(arr[i]);
    }
    return res;
}

vector<int> nextSmallerElementLeftUsingStack(vector<int> arr){  //Also Called previous smaller Element 
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            res[i] = st.top();
        }
        st.push(arr[i]);
    }
    return res;
}

int main(){
    vector<int> arr={1, 5, -3, 7, 1};
    cout << "Array :\n";
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << " ";
    }
    vector<int> res=nextGreaterElementRightUsingStack(arr);
    cout << "\n NGE from right(means to look greater element on right side) \n";
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    cout << "\n NGE from left(means to look greater element on left side) \n";
    vector<int> res1=nextGreaterElementLeftUsingStack(arr);
    for(int i=0;i<res1.size();i++){
        cout << res1[i] << " ";
    }
    return 0;
}