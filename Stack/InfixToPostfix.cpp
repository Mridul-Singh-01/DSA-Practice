#include <iostream>
#include <stack>
#include <string>
using namespace std;

int priority(char c) {
    if (c == '*' || c == '/') {
        return 2;
    } else if (c == '^') {
        return 3;
    } else if (c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}

char associativity(char c) {
    if (c == '^')
        return 'R';
    return 'L'; // Default to left-associative
}

string infixToPostfix(string s) {   //time complexity O(n) and space complexity O(n)
    stack<char> st;
    string postfix = "";
    int i = 0;
    while (i < s.size()) {
        if ((s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= '0' && s[i] <= '9')) {
            postfix += s[i];
        } else if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        } else {
            while (!st.empty() && priority(st.top()) > priority(s[i]) || 
                !st.empty() && priority(s[i]) == priority(st.top()) && associativity(s[i]) == 'L') {
                postfix += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int main() {
    string infix1 = "a+b*(c^d-e)^(f+g*h)-i";
    string infix2 = "(A+B)*C";
    string infix3 = "A*(B+C)/D";
    cout << "Infix: " << infix1 << " -> Postfix: " << infixToPostfix(infix1) << endl;
    cout << "Infix: " << infix2 << " -> Postfix: " << infixToPostfix(infix2) << endl;
    cout << "Infix: " << infix3 << " -> Postfix: " << infixToPostfix(infix3) << endl;
    return 0;
}