// Given a Integer array A[] of n elements. Your task is to complete the function PalinArray.
//Which will return 1 if all the elements of the Array are palindrome otherwise it will return 0.
// Example 1:
// Input:
// 5
// 111 222 333 444 555
// Output:
// 1

#include <string>
#include <iostream>

class Solution {
public:
    bool isPalin(int a){
        std::string str=std::to_string(a);
        int l=0;
        int r=str.size()-1;
        bool res=1;
        while(l<r){
            if(str[l]!=str[r]){
                res=0;
                break;
            }
            l++;
            r--;
        }
        return res;
    }
    int PalinArray(int a[], int n)
    {
    	for(int i=0;i<n;i++){
    	    if(isPalin(a[i])!=1){
    	        return 0;
    	    }
    	}
    	return 1;
    	
    }
};
int main(){
    Solution solution;
    int a[]={101,303,303,101};
    int n=4;
    std::cout << solution.PalinArray(a,n);
    return 0;
}