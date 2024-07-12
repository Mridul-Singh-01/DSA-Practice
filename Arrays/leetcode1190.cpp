// You are given a string s that consists of lower case English letters and brackets.
// Reverse the strings in each pair of matching parentheses, starting from the innermost one.
// Your result should not contain any brackets.
// Example 1:
// Input: s = "(abcd)"
// Output: "dcba"

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {    //time complexity o(n) and space complexity o(n)
        string finalString;
        stack<char> st;
        for(char ch : s){
            if(ch == ')'){
                string temp="";
                while(st.top()!='('){
                    temp+=st.top();
                    st.pop();
                }
                if(!st.empty()){
                    st.pop();
                }
                for(int j=0 ;j<temp.length();j++){
                    st.push(temp[j]);
                }
            }
            else{
                st.push(ch);
            }
        }
        while(!st.empty()){
            finalString=st.top()+finalString;
            st.pop();
        }
        return finalString;
    }
};

int main(){
    Solution solution;
    string s="(u(love)i)";
    cout << solution.reverseParentheses(s);
    return 0;
}