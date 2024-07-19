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

//More optimal solution is this becuase don't use extra space 
// int maxDepth(string s) {
//         int maxDepth = 0;
//         int currentDepth = 0;

//         for (char c : s) {
//             if (c == '(') {
//                 currentDepth++;
//                 maxDepth = max(maxDepth, currentDepth);
//             } else if (c == ')') {
//                 currentDepth--;
//             }
//         }

//         return maxDepth;
//     }
// }

int main(){
    Solution s;
    cout << s.maxDepth("(1+((2/4)))");
    return 0;
}