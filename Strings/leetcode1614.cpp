#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int n=s.size();
        int finalDepth=0;
        int currdepth=0;
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                while(st.top()!='('){
                    st.pop();
                }
                st.pop();
                finalDepth=max(finalDepth,currdepth);
                currdepth--;
            }
            else{
                if(s[i]=='('){
                    currdepth++;
                }
                st.push(s[i]);
            }
        }
        return finalDepth;
    }
};

int main(){
    Solution s;
    cout << s.maxDepth("(1+((2/4)))");
    return 0;
}