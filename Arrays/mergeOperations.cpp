// Find minimum number of merge operations to make an array palindrome
// Given an array of positive integers. We need to make the given array a ‘Palindrome’. The only allowed operation is”merging” (of two adjacent elements).
//Merging two adjacent elements means replacing them with their sum. 
// The task is to find the minimum number of merge operations required to make the given array a ‘Palindrome’.
// Input : arr[] = {1, 4, 5, 1}
// Output : 1
// We can make given array palindrome with
// minimum one merging (merging 4 and 5 to make 9)

#include <bits/stdc++.h>
using namespace std;
int findMinOps(int arr[], int n)
{
    int ans = 0;
    for (int i = 0, j = n - 1; i <= j;)
    {
        if (arr[i] == arr[j])
        {
            i++;
            j--;
        }
        else if (arr[i] > arr[j])
        {
            j--;
            arr[j] += arr[j + 1];
            ans++;
        }
        else
        {
            i++;
            arr[i] += arr[i - 1];
            ans++;
        }
    }

    return ans;
}
int main()
{
    int arr[] = {1, 4, 5, 9, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Count of minimum operations is "
         << findMinOps(arr, n) << endl;
    return 0;
}
