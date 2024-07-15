// A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.
// For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
// A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.
// Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.
// Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string result;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                if (!st.empty()) {
                    result += s[i];
                }
                st.push(s[i]);
            } else if (s[i] == ')') {
                st.pop();
                if (!st.empty()) {
                    result += s[i];
                }
            }
        }

        return result;
    }
};

int main() {
    Solution solution;
    string s1 = "(()())(())";
    cout << solution.removeOuterParentheses(s1) << endl;
    string s2 = "(()())(())(()(()))";
    cout << solution.removeOuterParentheses(s2) << endl;
    string s3 = "()()";
    cout << solution.removeOuterParentheses(s3) << endl;
    return 0;
}
