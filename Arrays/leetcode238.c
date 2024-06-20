/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int *left = (int*)malloc(numsSize * sizeof(int));
    int *right = (int*)malloc(numsSize * sizeof(int));
    int *ans = (int*)malloc(numsSize * sizeof(int));
    
    left[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        left[i] = left[i-1] * nums[i-1];
    }
    
    right[numsSize-1] = 1;
    for (int i = numsSize-2; i >= 0; i--) {
        right[i] = right[i+1] * nums[i+1];
    }
    
    for (int i = 0; i < numsSize; i++) {
        ans[i] = left[i] * right[i];
    }

    free(left);
    free(right);
    *returnSize = numsSize;
    return ans;
}
int main()
{
    int nums[]={1,2,3,4};
    int numsSize=sizeof(nums)/sizeof(nums[0]);
    int returnSize;
    int *result = productExceptSelf(nums,numsSize,&returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    return 0;
}
