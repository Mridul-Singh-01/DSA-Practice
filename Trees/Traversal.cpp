#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

void inorder(Node* head){
    if(head == nullptr) return;
    inorder(head->left);
    cout << head->data << " ";
    inorder(head->right);
}

void preorder(Node* head){
    if(head == nullptr) return;
    cout << head->data << " ";
    preorder(head->left);
    preorder(head->right);
}

void postorder(Node* head){
    if(head == nullptr) return;
    postorder(head->left);
    postorder(head->right);
    cout << head->data << " ";
}

int main(){
    Node* head = new Node(10);
    head->left = new Node(20);
    head->right = new Node(30);
    head->left->left = new Node(40);
    head->left->right = new Node(50);
    head->right->left = new Node(60);
    head->right->right = new Node(70);
    cout << "Inorder Traversal: ";
    inorder(head);
    cout << endl;
    cout << "Preorder Traversal: ";
    preorder(head);
    cout << endl;
    cout << "Postorder Traversal: ";
    postorder(head);
    cout << endl;
    return 0;
}
