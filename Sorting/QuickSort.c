#include<stdio.h>
int partition(int arr[],int l,int h){
    int p=arr[h];
    int i=l-1;
    for(int j=l;j<h;j++){
        if(arr[j]<=p){
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp;
    temp=arr[i+1];
    arr[i+1]=arr[h];
    arr[h]=temp;
    return i+1;
}
void quicksort(int arr[],int l,int h){
    if(l<h){
        int q=partition(arr,l,h);
        quicksort(arr,l,q-1);
        quicksort(arr,q+1,h);
    }
}
int main(){
    int arr[8]={10,5,8,2,9,90,86,1};
    int s=8;
    quicksort(arr,0,s);
    for(int i=0;i<s;i++){
        printf("%d  ",arr[i]);
    }
    return 0;
}