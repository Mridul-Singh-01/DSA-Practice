//GFG QUESTION -> Binary Tree Representation

#include<bits/stdc++.h>
using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}

class Solution{
public:
    node* solve(vector<int> &vec,int i){
        if(i >= vec.size()){
            return NULL;
        }
        node* newNode1 = newNode(vec[i]);
        newNode1->left = solve(vec,2*i+1);
        newNode1->right = solve(vec,2*i+2);
        return newNode1;
    }
    void create_tree(node* &root0, vector<int> &vec){
        root0 = solve(vec,0);
    }
    void printInorder(node* root){
        if(root==nullptr){
            return ;
        }
        printInorder(root->left);
        cout << root->data << " ";
        printInorder(root->right);
    }
};

int main(){
    vector<int> arr={1,2,3,4,5,6,7};
    node* root;
    Solution s;
    s.create_tree(root,arr);
    s.printInorder(root);
    return 0;
}