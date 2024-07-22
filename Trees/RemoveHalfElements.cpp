//GFG Question -> Remove half nodes
// You are given a binary tree and you need to remove all the half nodes (which have only one child). Return the root node of the modified tree after removing all the half-nodes.
// Note: The output will be judged by the inorder traversal of the resultant tree, inside the driver code.

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
Node* buildTree(string str) {
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);
    Node* root = new Node(stoi(ip[0]));
    queue<Node*> queue;
    queue.push(root);
    int i = 1;
    while (!queue.empty() && i < ip.size()) {
        Node* currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if (currVal != "N") {
            currNode->left = new Node(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];
        if (currVal != "N") {
            currNode->right = new Node(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inorder(Node* node) {
    if (node == NULL)
        return;

    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

//MAIN FUNCTION 
class Solution {
  public:
    Node *RemoveHalfNodes(Node *root) {     //time complexity O(n) and space complexity O(1)
        // code here
        if(root==NULL){
            return NULL;
        }
        root->left  = RemoveHalfNodes(root->left);
        root->right  = RemoveHalfNodes(root->right);
        if(root->left==NULL && root->right==NULL){
            return root;
        }
        if(root->left==NULL){
            struct Node *new_root = root->right;
            free(root);
            return new_root;
        }
        if(root->right==NULL){
            struct Node *new_root = root->left;
            free(root);
            return new_root;
        }
        return root;
    }
};

int main() {

    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution obj;
        Node* fresh = obj.RemoveHalfNodes(root);
        inorder(fresh);
        cout << endl;
    }
    return 1;
}