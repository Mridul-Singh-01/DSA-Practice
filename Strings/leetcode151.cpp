// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
       int n=s.size();
       int i=0;
       string str;
       s=s+" ";
       stack<string> st;
       for(i=0;i<s.length();i++){
            if(s[i]==' '){
                if (!str.empty()) {
                    st.push(str);
                    str = "";
                }
            }
            else{
                str+=s[i];
            }
       }
       string ans;
       while(!st.empty()){
            ans+=st.top();
            st.pop();
            if (!st.empty()) {
                ans += " ";
            }
       }
       return ans;
    }
};

int main(){
    Solution solution;
    cout << solution.reverseWords("string is best");
    return 0;
}