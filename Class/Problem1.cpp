//arr - > [1,5,-3,7,1]
//output -> [5,7,7,-1,-1];

#include<bits/stdc++.h>
using namespace std;

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

vector<int> nextGreaterElementUsingStack(vector<int> arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            res[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return res;
}

int main(){
    vector<int> arr={1, 5, -3, 7, 1};
    vector<int> res=nextGreaterElementUsingStack(arr);
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}