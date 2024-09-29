#include<bits/stdc++.h>
using namespace std;

void countFrequency(string str){
    string word="";
    map<string,int> mp;
    for(int i=0;i<str.size();i++){
        if(str[i]==' '){
            if (!word.empty()) {
                mp[word]++;
                word="";
            }
        }
        else{
            word+=str[i];
        }
    }
    if (!word.empty()) {
        mp[word]++;
    }
    for(auto &it:mp){
        cout << it.first << " - " << it.second << "\n";
    }
}

int main()
{
    string str = "Geeks For Geeks    ";
    countFrequency(str);
    return 0;
}