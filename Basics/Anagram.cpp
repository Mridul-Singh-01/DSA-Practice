#include <bits/stdc++.h>
using namespace std;

bool check_anagram(string s1,string s2){
    if(s1.size()!=s2.size()){
        return false;
    }
    vector<int> fre(26,0);
    for(char c:s1){
        fre[c-'a']++;
    }
    for(char c:s2){
        fre[c-'a']--;
    }
    for(int i=0;i<26;i++){
        if(fre[i]!=0){
            return false;
        }
    }
    return true;
}

int main() {
    string s1="act";
    string s2="tca";
    cout << check_anagram(s1,s2);
    return 0;
}