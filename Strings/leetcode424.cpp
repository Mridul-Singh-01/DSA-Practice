#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int right=0;
        int maxf=0;
        int ans=0;
        vector<int> mp(26);
        while(right<s.size()){
           maxf=max(maxf,++mp[s[right]-'A']);
           while(maxf+k<right-left+1){
                --mp[s[left++]-'A'];
           }
           ans=max(ans,right-left+1);
           right++;
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout<<s.characterReplacement("ABAB",2)<<endl;
    return 0;
}