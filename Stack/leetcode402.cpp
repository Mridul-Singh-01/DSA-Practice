#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(int i=0;i<num.size();i++){
            while(!st.empty() && k>0 && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        string res;
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        int start = 0;
        while (start < res.size() && res[start] == '0') {
            start++;
        }
        res = res.substr(start);
        if (res.empty()) {
            return "0";
        }
        return res;
    }
};

int main(){
    Solution s;
    cout << s.removeKdigits("10200",1);
    return 0;
}