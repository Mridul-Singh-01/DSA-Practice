#include<stdio.h>
void merge(int a[],int p, int q, int r){
    int i,j;
    int n1=q-p+1;
    int n2=r-q;
    int larr[n1+1];
    int rarr[n2+1];
    for(int i=0;i<n1;i++){
        larr[i]=a[i+p];
    }
    for(int j=0;j<n2;j++){
        rarr[j]=a[j+p];
    }
    larr[n1+1]=10000;
    rarr[n2+1]=10000;
    for(int k=p;k<r;k++){
        if(larr[i]<rarr[j]){
            a[k]=larr[i];
            i++;
        }
        else{
            a[k]=rarr[j];
            j++;
        }
    }
}
void mergeSort(int a[],int p,int r){
    if(p<r){
        int q=(p+r)/2;
        mergeSort(a,p,q);
        mergeSort(a,q+1,r);
        merge(a,p,q,r);
    }
}
int main(){
    int arr[5]={10,2,5,1,8};
    int s=5;
    mergeSort(arr,0,s);
    for(int i=0;i<s;i++){
        printf("%d  ",arr[i]);
    }
    return 0;
}


// #include <stdio.h>

// void merge(int l,int h,int m,int arr[]){
//     int i,j=0;
//     int k=l;
//     int n1=m-l+1;
//     int n2=h-m;
//     int larr[n1+1], rarr[n2+1];
//     for(int x=0;x<n1;x++){
//         larr[x]=arr[l+x];
//     }
//     for(int y=0;y<n2;y++){
//         rarr[y]=arr[m+1+y];
//     }
//     larr[n1+1]=10000;
//     rarr[n2+1]=10000;
//     while(k<h){
//         if(larr[i]<=rarr[j]){
//             arr[k]=larr[i];
//             i++;
//         }
//         else{
//             arr[k]=rarr[j];
//             j++;
//         }
//         k++;
//     }
// }
// void mergesort(int l,int h, int arr[]){
//     if(l<h){
//         int m=(l+h)/2;
//         mergesort(l,m,arr);
//         mergesort(m+1,h,arr);
//         merge(l,h,m,arr);
//     }
// }
// void printArray(int arr[], int s)
// {
//     int i;
//     for (i = 0; i < s; i++)
//         printf("%d ", arr[i]);
//     printf("\n");
// }
// int main()
// {
//     int arr[5]={10,2,5,1,8};
//     int s=5;
//     mergesort(0,s,arr);
//     printArray(arr,s);
//     return 0;
// }
