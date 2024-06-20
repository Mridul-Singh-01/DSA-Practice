// Given a string S. For each index i(1<=i<=N-1), erase it if s[i] is equal to s[i-1] in the string.
// Example 1:
// Input:
// S = aabb
// Output:  ab 
//{ Driver Code Starts
//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
    string removeConsecutiveCharacter(string S)
    {
        // code here.
        int i = 1;
        while (i < S.length()) {
            if (S[i] == S[i - 1]) {
                S.erase(S.begin() + i); 
            } 
            else {
                i++;
            }
        }
        return S;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
    return 0;
} 