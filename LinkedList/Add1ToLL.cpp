//GFG QUESTION -> Add 1 to a Linked List Number
// You are given a linked list where each element in the list is a node and have an integer data. You need to add 1 to the number formed by concatinating all the list node numbers together and return the head of the modified linked list. 
// Note: The head represents the first element of the given array.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};

class Solution {
public:
    int helper(Node* temp) {    //time complexity O(n) ands space complexity O(1)
        if (temp == nullptr) return 1;
        int carry = helper(temp->next);
        temp->data = temp->data + carry;
        if (temp->data < 10) {
            return 0;
        }
        temp->data = 0;
        return 1;
    }
    
    Node* addOne(Node* head) {
        int carry = helper(head);
        if (carry == 1) {
            Node* temp = new Node(1);
            temp->next = head;
            return temp;
        }
        return head;
    }
};

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;
    Node* head = new Node(1);
    head->next = new Node(9);
    head->next->next = new Node(9);
    head->next->next->next = new Node(9);
    cout << "Original list: ";
    printList(head);
    head = solution.addOne(head);
    cout << "List after adding one: ";
    printList(head);
    return 0;
}
