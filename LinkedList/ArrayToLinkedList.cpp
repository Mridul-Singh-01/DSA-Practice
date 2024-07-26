// Geek loves linked list data structure. Given an array of integer arr of size n, Geek wants to construct the linked list from arr.
// Construct the linked list from arr and return the head of the linked list.
// Example 1:
// Input:
// n = 5
// arr = [1,2,3,4,5]
// Output:
// 1 2 3 4 5
// Explanation: Linked list for the given array will be 1->2->3->4->5.

#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        Node* head=new Node(arr[0]);
        Node* it=head;
        for(int i=1;i<arr.size();i++){
            Node* temp= new Node(arr[i]);
            it->next=temp;
            it=temp;
        }
        return head;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        Node* ans = obj.constructLL(arr);
        while (ans) {
            cout << ans->data << " ";
            ans = ans->next;
        }
        cout << "\n";
    }
    return 0;
}