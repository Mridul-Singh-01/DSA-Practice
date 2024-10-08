#include<bits/stdc++.h>
using namespace std;

int reverse_No(int n){
    int new_no=0;
    while(n!=0){
        int digit=n%10;
        new_no = new_no * 10 + digit;
        n=n/10;
    }
    return new_no;
}

int main(){
    int n=234;
    cout << reverse_No(n);
    return 0;
}