// Given a linked list of n nodes and a key , the task is to check if the key is present in the linked list or not.
// Example:
// Input:
// n = 4
// 1->2->3->4
// Key = 3
// Output:
// True

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    bool searchKey(int n, struct Node* head, int key) {
        Node* it=head;
        while(it!=nullptr){
            if(it->data==key){
                return true;
            }
            it=it->next;
        }
        return false;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < n - 1; ++i) {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.searchKey(n, head, key) << endl;
    }
    return 0;
}