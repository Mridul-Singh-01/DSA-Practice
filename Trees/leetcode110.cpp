//110. Balanced Binary Tree
// Given a binary tree, determine if it is height-balanced (balanced tree is a binary tree in which 
//the depth of the two subtrees of every node never differs by more than one.)

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

int check(Node* root){
    if(root==nullptr)return 0;
    int left=check(root->left);
    int right=check(root->right);
    if(left==-1 || right==-1 || abs(left-right)>1){
        return -1;
    }
    return max(left,right)+1;
}

bool balanced(Node* root){
    if(root==nullptr)return true;
    return check(root)!=-1;
}

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    cout << balanced(root);
    return 0;
}