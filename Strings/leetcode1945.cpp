//convert string to integer and then add integer k times

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumDigits(int x){
        int sum=0;
        while(x>0){
            int temp=x%10;
            x=x/10;
            sum+=temp;
        }
        return sum;
    }
    int getLucky(string s, int k) {
        string numString="";
        for (char c : s) {
            int x = c - 'a' + 1;
            numString += to_string(x);
        }
        int num = 0;
        for (char c : numString) {
            num += (c - '0');
        }
        for (int i = 1; i < k; i++) {
            num = sumDigits(num);
        }
        return num;
    }
};

int main(){
    Solution s;
    cout << s.getLucky("zbax",2);
    return 0;
}