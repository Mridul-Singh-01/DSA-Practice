#include<stdio.h>
#include<limits.h>

int max(int x,int y){
    return x>y?x:y;
}

//time complexity is n2
int main(){
    int arr[4]={2,3,2,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    int max_no=INT_MIN;
    for(int i=0;i<n;i++){
        int pro=1;
        for(int j=i;j<n;j++){
            pro=pro*arr[j];
            max_no=max(pro,max_no);
        }
        
    }
    printf("%d",max_no);
    return 0;
}

//more optimal solution time complexity is n

int maxProduct(int* nums, int numsSize) {{
    int ans=INT_MIN;
    int per=1;
    int suf=1;
    for(int i=0;i<numsSize;i++){
        per=per*nums[i];
        suf=suf*nums[numsSize-i-1];
        ans=max(ans,max(per,suf));
    }
    return ans;
}
