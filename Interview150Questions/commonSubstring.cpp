#include<bits/stdc++.h>
using namespace std;

bool match(string s1,string s2){
    unordered_set<char> chars;
    for (char c : s1) {
        chars.insert(c);
    }
    for (char c : s2) {
        if (chars.find(c) != chars.end()) {
            return true;
        }
    }
    return false;
}

void commonSubstring(vector<string> &s1,vector<string> &s2){
    int n=s1.size();
    for(int i=0;i<n;i++){
        if(match(s1[i],s2[i])){
            cout << "Yes" << "\n";
        }
        else{
            cout << "No"<< "\n";
        }
    }
}

int main(){
    vector<string> s1={"ab","cd","ef"};
    vector<string> s2={"af","ee","ef"};
    commonSubstring(s1,s2);
    return 0;
}