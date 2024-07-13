// Input: s = "42"
// Output: 42
// Explanation:
// The underlined characters are what is read in and the caret is the current reader position.
// Step 1: "42" (no characters read because there is no leading whitespace)
//          ^
// Step 2: "42" (no characters read because there is neither a '-' nor '+')
//          ^
// Step 3: "42" ("42" is read in)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();
        while (i < n && isspace(s[i])) {
            i++;
        }
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }        
        long result = 0;
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            if (result * sign > INT_MAX) return INT_MAX;
            if (result * sign < INT_MIN) return INT_MIN;
            i++;
        }
        return result * sign;
    }
};

int main() {
    Solution solution;
    string s1 = "42";
    cout << solution.myAtoi(s1) << endl;
    string s2 = "   -42";
    cout << solution.myAtoi(s2) << endl;
    string s3 = "4193 with words";
    cout << solution.myAtoi(s3) << endl;
    string s4 = "words and 987";
    cout << solution.myAtoi(s4) << endl;
    string s5 = "-91283472332";
    cout << solution.myAtoi(s5) << endl;
    return 0;
}
