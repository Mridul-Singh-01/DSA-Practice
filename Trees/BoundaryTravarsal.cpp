#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data=x;
        left=nullptr;
        right=nullptr;
    }
};

bool isLeaf(Node* root){
    if(root->left==nullptr && root->right==nullptr){
        return true;
    }
    return false;
}

void addLeftBoundary(Node* root,vector<int> &res){
    while(root){
        if(!isLeaf(root)){
            res.push_back(root->data);
        }
        if(root->left){
            root=root->left;
        }
        else root=root->right;
    }
}

void addRightBoundary(Node* root,vector<int> &res){
    stack<int> st;
    while(root){
        if(!isLeaf(root)){
            st.push(root->data);
        }
        if(root->right)root=root->right;
        else root=root->left;
    }
    while(!st.empty()){
        res.push_back(st.top());
        st.pop();
    }
}

void addLeaf(Node* root,vector<int> &res){
    if(root==nullptr)return;
    if(isLeaf(root)){
        res.push_back(root->data);
    }
    addLeaf(root->left,res);
    addLeaf(root->right,res);
}

vector<int> boundary(Node* root){
    vector<int> res;
    if(root == nullptr) return res;
    if(!isLeaf(root)) {
        res.push_back(root->data);
    }
    if(root->left) {
        addLeftBoundary(root->left, res);
    }
    addLeaf(root, res);
    if(root->right) {
        addRightBoundary(root->right, res);
    }
    return res;
}

int main() {
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right->right = new Node(25);
    vector<int> boundaryTraversal = boundary(root);
    cout << "Boundary Traversal of the binary tree is: ";
    for (int i : boundaryTraversal) {
        cout << i << " ";
    }
    return 0;
}