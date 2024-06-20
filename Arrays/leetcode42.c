#include <stdio.h>

int min(int x, int y) {
  return (x < y) ? x : y;
}

int main(){
    int n=12;
    int arr[12]={0,1,0,2,1,0,1,3,2,1,2,1};
    int left[n];
    int right[n];
    left[0]=arr[0];
    for(int i=1;i<n;i++){
        if(left[i-1]<arr[i]){
            left[i]=arr[i];
        }
        else{
            left[i]=left[i-1];
        }
    }
    right[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        if(right[i+1]<arr[i]){
            right[i]=arr[i];
        }
        else{
            right[i]=right[i+1];
        }
    }
    int res=0;
    int final=0;
    for(int i=0;i<n;i++){
        res=min(left[i],right[i])-arr[i];
        final=final+res;
    }
    printf("%d",final);
    return 0;
}