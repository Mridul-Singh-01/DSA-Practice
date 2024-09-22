//Diameter of Binary Tree
// Given the root of a binary tree, return the length of the diameter of the tree.
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. 
//This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges between them.

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

class Solution {
public:
    int height(Node* root, int& diameter) {
        if (root == nullptr) {
            return 0;
        }
        int leftHeight = height(root->left, diameter);
        int rightHeight = height(root->right, diameter);
        diameter = max(diameter, leftHeight + rightHeight);
        return max(leftHeight, rightHeight) + 1;
    }
    int diameterOfBinaryTree(Node* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};