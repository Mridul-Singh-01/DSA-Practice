// Delete all occurrences of a given key in a doubly linked list
// You are given the head_ref of a doubly Linked List and a Key. 
// Your task is to delete all occurrences of the given key if it is present and return the new DLL.

#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
};

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

void deleteAllOccurOfX(Node **head_ref, int x) {
    Node *temp = *head_ref;
    while (temp != nullptr) {
        if (temp->data == x) {
            Node *toDelete = temp;
            if (temp == *head_ref) {
                *head_ref = temp->next;
                if (*head_ref != nullptr) {
                    (*head_ref)->prev = nullptr;
                }
            } else {
                if (temp->prev != nullptr) {
                    temp->prev->next = temp->next;
                }
                if (temp->next != nullptr) {
                    temp->next->prev = temp->prev;
                }
            }
            temp = temp->next;
            delete toDelete;
        } else {
            temp = temp->next;
        }
    }
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
    append(&head, 2);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 2);
    append(&head, 5);
    cout << "Original Doubly Linked List:" << endl;
    printList(head);
    int key = 2;
    deleteAllOccurOfX(&head, key);
    cout << "Doubly Linked List after deleting all occurrences of " << key << ":" << endl;
    printList(head);
    return 0;
}
