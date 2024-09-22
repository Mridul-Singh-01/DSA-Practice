#include<bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// Function to perform pre-order traversal iteratively
vector<int> preOrder(Node* root) {
    vector<int> res;
    if (root == nullptr) return res;
    stack<Node*> st;
    st.push(root);
    
    while (!st.empty()) {
        Node* temp = st.top();
        st.pop();
        res.push_back(temp->data);
        
        // Push right child first so that left is processed first
        if (temp->right) {
            st.push(temp->right);
        }
        if (temp->left) {
            st.push(temp->left);
        }
    }
    return res;
}

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Perform pre-order traversal
    vector<int> result = preOrder(root);

    // Output the result
    cout << "Pre-order Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
