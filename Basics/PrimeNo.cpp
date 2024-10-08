#include<bits/stdc++.h>
using namespace std;

bool check_prime(int n){
    if(n<=1){
        return false;
    }
    if(n==2 || n==3){
        return true;
    }
    if(n%2==0 || n%3==0){
        return false;
    }
    for(int i=5;i<=sqrt(n);i+6){
        if(n%i==0 || n%(i+2)==0){
            return false;
        }
    }
    return true;
}

/*
Brute force approach
check_prime(vector<int> arr){
    if(n<=1){
        return false;    
    }
    int c=0;
    else{
        for(int i=1;i<n;i++){
            if(n%i==0){
                c++;
            }
        }
        if(c>2){
            retrun false;
        }
    }
    return true;
}
*/

int main(){
    int n=751;
    cout << check_prime(n);
    return 0;
}