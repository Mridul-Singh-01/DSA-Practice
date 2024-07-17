// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
// Example 1:
// Input: nums = [3,2,3]
// Output: [3]
// Example 2:
// Input: nums = [1]
// Output: [1]

#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> arr,int n){
    int cnt1=0, cnt2=0;
    int el1=INT_MIN;
    int el2=INT_MIN;
    for(int i=0;i<n;i++){
        if(cnt1==0 && el2!=arr[i]){
            cnt1=1;
            el1=arr[i];
        }
        else if(cnt2==0 && el1!=arr[i]){
            cnt2=1;
            el2=arr[i];
        }
        else if(arr[i]==el1) cnt1++;
        else if(arr[i]==el2) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }
    cnt1=0,cnt2=0;
    for(int i=0;i<n;i++){
        if(el1==arr[i]){
            cnt1++;
        }
        if(el2==arr[i]){
            cnt2++;
        }
    }
    vector<int> ans;
    int majority=(n/3)+1;
    if(cnt1>=majority){
        ans.push_back(el1);
    }
    if(cnt2>=majority){
        ans.push_back(el2);
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main(){
    int n=2;
    vector<int>arr={1,2};
    vector<int> res=majorityElement(arr,n);
    for(int i=0;i<res.size();i++){
        cout << res[i] << " ";
    }
    return 0;
}