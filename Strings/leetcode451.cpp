// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
// Return the sorted string. If there are multiple answers, return any of them.
// Example 1:
// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

#include<bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
    map<char,int> freq;
    for(auto c: s){
        freq[c]++;
    }
    vector<pair<int,char>> freqList;
    for (auto& it : freq) {
        freqList.push_back({it.second, it.first});
    }
    sort(freqList.rbegin(),freqList.rend());
    string ans;
    for (auto& it : freqList) {
        ans.append(it.first, it.second);
    }
    return ans;
}

int main(){
    cout << frequencySort("HiiFromC++");
    return 0;
}