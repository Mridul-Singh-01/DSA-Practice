//Leetcode problem 124

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
    int helper(Node* root,int& maxi){
        if(root==nullptr)return 0;
        int leftSum=max(0,helper(root->left,maxi));
        int rightSum=max(0,helper(root->right,maxi));
        maxi=max(maxi,leftSum+rightSum+root->data);
        return root->data+max(leftSum,rightSum);
    }
    int maxPathSum(Node* root) {
        int  maxi=INT_MIN;
        helper(root,maxi);
        return maxi;
    }
};

int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    Solution s;
    cout <<s.maxPathSum(root);
    return 0;
}