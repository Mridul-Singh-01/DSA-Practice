// Remove duplicates from a sorted doubly linked list
// Given a doubly linked list of n nodes sorted by values, the task is to remove duplicate nodes present in the linked list.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

Node* removeDuplicates(Node* head) {
    if (head == nullptr) return head;
    Node* temp = head;
    while (temp != nullptr && temp->next != nullptr) {
        if (temp->data == temp->next->data) {
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            if (toDelete->next != nullptr) {
                toDelete->next->prev = temp;
            }
            delete toDelete;
        } else {
            temp = temp->next;
        }
    }
    return head;
}

void append(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    Node* last = *head_ref;
    if (*head_ref == nullptr) {
        *head_ref = new_node;
        return;
    }
    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    append(&head, 1);
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 3);
    append(&head, 4);
    append(&head, 4);
    append(&head, 5);
    cout << "Original list: ";
    printList(head);
    head = removeDuplicates(head);
    cout << "List after removing duplicates: ";
    printList(head);
    return 0;
}
