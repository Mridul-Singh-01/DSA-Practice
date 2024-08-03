//gfg Question Sort a linked list of 0s, 1s and 2s
// Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only.
// The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side,
// 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* segregate(Node *head) {       //time complexity O(n) and space complexity O(1)
    if (head == nullptr || head->next == nullptr) return head;
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == 0) zeroCount++;
        else if (temp->data == 1) oneCount++;
        else twoCount++;
        temp = temp->next;
    }

    temp = head;
    while (zeroCount) {
        temp->data = 0;
        zeroCount--;
        temp = temp->next;
    }
    while (oneCount) {
        temp->data = 1;
        oneCount--;
        temp = temp->next;
    }
    while (twoCount) {
        temp->data = 2;
        twoCount--;
        temp = temp->next;
    }
    return head;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);
    head->next->next->next->next->next->next = new Node(0);
    head->next->next->next->next->next->next->next = new Node(1);
    cout << "Original list: ";
    printList(head);
    head = segregate(head);
    cout << "Segregated list: ";
    printList(head);
    return 0;
}
