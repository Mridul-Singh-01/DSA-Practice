// You are given a string s and two integers x and y. You can perform two types of operations any number of times.
// Remove substring "ab" and gain x points.
// For example, when removing "ab" from "cabxbae" it becomes "cxbae".
// Remove substring "ba" and gain y points.
// For example, when removing "ba" from "cabxbae" it becomes "cabxe".
// Return the maximum points you can gain after applying the above operations on s.

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string first,second;
        int highScore,lowScore;
        int finalScore=0;
        if(x>y){
            first="ab";
            highScore=x;
            second="ba";
            lowScore=y;
        }
        else{
            first="ba";
            highScore=y;
            second="ab";
            lowScore=x;
        }
        stack<char> stack;
        for(char ch: s){
            if(ch==first[1] && !stack.empty() && stack.top()==first[0]){
                stack.pop();
                finalScore+=highScore;
            }
            else{
                stack.push(ch);
            }
        }
        string newString;
        while (!stack.empty()) {
            newString += stack.top();
            stack.pop();
        }
        reverse(newString.begin(), newString.end());
        for(char ch : newString){
            if(ch==second[1] && !stack.empty() && stack.top()==second[0]){
                finalScore+=lowScore;
                stack.pop();
            }
            else{
                stack.push(ch);
            }
        }
        return finalScore;
    }
};

int main(){
    string s="cdbcbbaaabab";
    Solution solution;
    cout << solution.maximumGain(s,4,5);
    return 0;
}